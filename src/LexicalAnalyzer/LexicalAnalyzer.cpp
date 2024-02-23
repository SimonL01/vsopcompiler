#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <sstream>

#include "LexicalAnalyzer.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::isspace;
using std::pair;
using std::string;
using std::vector;

namespace Compilers::LexicalAnalyzers
{
    static void removeNewLine(string &str)
    {
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    }

    static void removeMultipleSpaces(string &str)
    {
        auto newEnd = std::unique(str.begin(), str.end(), [](char a, char b)
                                  { return a == ' ' && b == ' '; });
        str.erase(newEnd, str.end());
    }

    static string removeLeadingZeros(const string &str)
    {
        // Convertir la chaîne en un nombre entier
        int number = std::stoi(str);

        // Convertir le nombre en une chaîne
        std::stringstream ss;
        ss << number;
        return ss.str();
    }

    static string hexStringToIntString(const string &hexString)
    {
        try
        {
            long int result = std::stoll(hexString, nullptr, 16); // Convertit la chaîne hexadécimale en long int
            return std::to_string(result);                        // Convertit le résultat en std::string et le renvoie
        }
        catch (const std::invalid_argument &ia)
        {
            return "Invalid argument: " + string(ia.what());
        }
        catch (const std::out_of_range &oor)
        {
            return "Out of range: " + string(oor.what());
        }
    }

    static string char2hex(char c)
    {
        std::string s = "\\x00";

        char d = c / 16;
        s[2] = d + (d < 10 ? '0' : 'a' - 10);
        d = c % 16;
        s[3] = d + (d < 10 ? '0' : 'a' - 10);

        return s;
    }

    bool LexicalAnalyzer::is_curr_operator()
    {
        switch (this->vsopCode[this->location])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '=':
            return {true};
        case '<':
            if (this->location + 1 < this->vsopCode.length() && (this->vsopCode[this->location + 1] == '=' || this->vsopCode[this->location + 1] == '-' || isspace(this->vsopCode[this->location])))
            {
                return {true};
            }
            else
            {
                return {false};
            }
        default:
            return false;
        }
    }

    LexicalAnalyzer::LexicalAnalyzer(const string &sourceFile, const string &sourceFileName) : vsopCode(sourceFile), vsopFileName(sourceFileName), location(0), line(1), column(1)
    {
        this->keyWordMap = {
            {"and", Tokens::Token::TClass::AND},
            {"bool", Tokens::Token::TClass::BOOL},
            {"class", Tokens::Token::TClass::CLASS},
            {"do", Tokens::Token::TClass::DO},
            {"else", Tokens::Token::TClass::ELSE},
            {"extends", Tokens::Token::TClass::EXTENDS},
            {"false", Tokens::Token::TClass::FALSE},
            {"if", Tokens::Token::TClass::IF},
            {"in", Tokens::Token::TClass::IN},
            {"int32", Tokens::Token::TClass::INT32},
            {"isnull", Tokens::Token::TClass::ISNULL},
            {"let", Tokens::Token::TClass::LET},
            {"new", Tokens::Token::TClass::NEW},
            {"not", Tokens::Token::TClass::NOT},
            {"self", Tokens::Token::TClass::SELF},
            {"string", Tokens::Token::TClass::STRING},
            {"then", Tokens::Token::TClass::THEN},
            {"true", Tokens::Token::TClass::TRUE},
            {"unit", Tokens::Token::TClass::UNIT},
            {"while", Tokens::Token::TClass::WHILE}};
    }

    void LexicalAnalyzer::tokenize()
    {
        this->tokens.clear();
        Tokens::Token token;
        do
        {
            token = get_next_token();
            if (token.get_tokenClass() != Tokens::Token::TClass::NOT_A_TOKEN)
            {
                tokens.push_back(token);
            }
        } while (token.get_tokenClass() != Tokens::Token::TClass::END_OF_FILE);
    }

    vector<Tokens::Token> LexicalAnalyzer::get_tokens() const
    {
        return this->tokens;
    }

    void LexicalAnalyzer::advance()
    {
        if (this->location < this->vsopCode.length())
        {
            if (!isascii(this->vsopCode[this->location]))
            {
                // print_error(this->line, this->column, "Invalid VSOP character");
            }

            if (this->vsopCode[this->location] == '\n')
            {
                this->line++;
                this->column = 1;
            }
            else
            {
                this->column++;
            }
            this->location++;
        }
    }

    void LexicalAnalyzer::advance_comment()
    {
        if (this->location < this->vsopCode.length())
        {
            if (this->vsopCode[this->location] == '\n')
            {
                this->line++;
                this->column = 1;
            }
            else
            {
                this->column++;
            }
            this->location++;
        }
    }

    void LexicalAnalyzer::skip_space_and_comment()
    {
        while (this->location < this->vsopCode.length() && (isspace(this->vsopCode[this->location]) || this->vsopCode[this->location] == '/' || this->vsopCode[this->location] == '('))
        {
            if (this->vsopCode[this->location] == '\n' || isspace(this->vsopCode[this->location]))
            {
                advance_comment();
            }
            else if (this->vsopCode[this->location] == '(')
            {
                size_t depth = 0; // depth of the nested comment
                vector<pair<size_t, size_t>> multiLineCommentPos;
                if (this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '*')
                {
                    multiLineCommentPos.push_back(std::make_pair(this->line, this->column));
                    depth++; // Incrémenter la profondeur d'imbrication
                    advance_comment();
                    advance_comment();

                    while (this->location < this->vsopCode.length() && depth > 0)
                    {
                        if (this->vsopCode[this->location] == '(' && this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '*')
                        {
                            multiLineCommentPos.push_back(std::make_pair(this->line, this->column));
                            depth++;
                            advance_comment();
                            advance_comment();
                            continue;
                        }
                        else if (this->vsopCode[this->location] == '*' && this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == ')')
                        {
                            multiLineCommentPos.pop_back();
                            depth--;
                            advance_comment();
                            advance_comment();
                            continue;
                        }
                        advance_comment();
                    }
                    if (depth > 0)
                    {
                        for (const auto &Pos : multiLineCommentPos)
                        {
                            print_error(Pos.first, Pos.second, "Unclosed multi-line comment");
                        }
                    }
                }
                else
                {
                    return;
                }
            }
            else if (this->vsopCode[this->location] == '/' && this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '/')
            {
                // Skip the entire comment line
                while (this->location < this->vsopCode.length() && this->vsopCode[this->location] != '\n')
                {
                    advance();
                }
            }
        }
    }

    Tokens::Token LexicalAnalyzer::scanIdentifier()
    {
        string tokenValue;
        size_t startLine = this->line;
        size_t startColumn = this->column;
        while (this->location < this->vsopCode.length() && (std::isalnum(this->vsopCode[this->location]) || this->vsopCode[this->location] == '_'))
        {
            tokenValue += this->vsopCode[this->location];
            advance();
        }
        // Check if the tokenValue is a keyword
        auto it = this->keyWordMap.find(tokenValue);
        if (it != keyWordMap.end())
        {
            return {it->second, tokenValue, startLine, startColumn};
        }
        // Check if the tokenValue starts with an uppercase letter to determine if it's a type identifier
        if (std::isupper(tokenValue[0]))
        {
            return {Tokens::Token::TClass::TYPE_IDENTIFIER, tokenValue, startLine, startColumn};
        }
        return {Tokens::Token::TClass::OBJECT_IDENTIFIER, tokenValue, startLine, startColumn};
    }

    Tokens::Token LexicalAnalyzer::scanIntegerLiteral()
    {
        string tokenValue;
        size_t startLine = this->line;
        size_t startColumn = this->column;

        // Check if it's a hexadecimal integer

        if (this->vsopCode[this->location] == '0' && this->location + 1 < this->vsopCode.length() && (this->vsopCode[this->location + 1] == 'x'))
        {
            tokenValue += this->vsopCode[this->location]; // Add '0'
            advance();
            tokenValue += this->vsopCode[this->location]; // Add 'x'
            advance();

            // Read hexadecimal digits
            while (std::isxdigit(this->vsopCode[this->location]))
            {
                tokenValue += this->vsopCode[this->location];
                advance();
            }

            if (!is_curr_operator() && !isspace(this->vsopCode[this->location]) && std::isprint(this->vsopCode[this->location]))
            {
                if (!(this->vsopCode[this->location] == '(' && this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '*'))
                {
                    tokenValue += this->vsopCode[this->location];
                    advance();
                    while (this->location + 1 < this->vsopCode.length() && std::isspace(this->vsopCode[this->location + 1]))
                    {
                        tokenValue += this->vsopCode[this->location];
                        advance();
                    }
                    removeNewLine(tokenValue);
                    print_error(startLine, startColumn, "Invalid hexadecimal integer literal - " + tokenValue);
                    return {Tokens::Token::TClass::NOT_A_TOKEN, hexStringToIntString(tokenValue), startLine, startColumn};
                }
            }
            return {Tokens::Token::TClass::INTEGER_LITERAL, hexStringToIntString(tokenValue), startLine, startColumn};
        }
        else
        {
            // Read decimal digits
            while (std::isdigit(this->vsopCode[this->location]))
            {
                tokenValue += this->vsopCode[this->location];
                advance();
            }

            if (!is_curr_operator() && !isspace(this->vsopCode[this->location]) && std::isprint(this->vsopCode[this->location]))
            {
                if (!(this->vsopCode[this->location] == '(' && this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '*'))
                {
                    tokenValue += this->vsopCode[this->location];
                    advance();
                    while (this->location + 1 < this->vsopCode.length() && std::isspace(this->vsopCode[this->location + 1]))
                    {
                        tokenValue += this->vsopCode[this->location];
                        advance();
                    }
                    removeNewLine(tokenValue);
                    print_error(startLine, startColumn, "Invalid decimal integer literal- " + tokenValue);
                    return {Tokens::Token::TClass::NOT_A_TOKEN, removeLeadingZeros(tokenValue), startLine, startColumn};
                }
            }
            return {Tokens::Token::TClass::INTEGER_LITERAL, removeLeadingZeros(tokenValue), startLine, startColumn};
        }
    }

    Tokens::Token LexicalAnalyzer::scanStringLiteral()
    {
        std::string tokenValue;
        size_t startLine = this->line;
        size_t startColumn = this->column;

        // Insérer " dans la chaine de caractère puis advance
        if(this->vsopCode[this->location] == '"'){
            tokenValue += '"';
        }
        if(this->vsopCode[this->location] == '"' && this->vsopCode[this->location+1] == '"'){
            // empty string
            // throw std::runtime_error("empty string : unspecified behavior");
            print_error(this->line, this->column, "Empty string : unspecified behavior");
        }
        advance(); // Skip the opening quote


        while (this->location < this->vsopCode.length() && this->vsopCode[this->location] != '"')
        {
            if(this->vsopCode[this->location] == '\\' && this->vsopCode[this->location+1] == '"' && this->vsopCode[this->location+2] == '\n'){
                // It is an error if trying to format as such \" at the end of a line
                // throw std::runtime_error("Unterminated string literal");
                print_error(startLine, startColumn, "unterminated-string");
            }

            // Si le character est \\, alors je vérifie la suite en essayant de respecter les guidelines
            if (this->vsopCode[this->location] == '\\') // \\ is an escape sequence for a SINGLE backslash
            {
                while (this->vsopCode[this->location+1] == '\\'){
                    tokenValue += char2hex('\\');
                    advance();
                }

                // It is an error if a string contains an invalid escape sequence
                if(this->vsopCode[this->location+1] != 'b' && this->vsopCode[this->location+1] != 't' && this->vsopCode[this->location+1] != 'n' && this->vsopCode[this->location+1] != 'r' && this->vsopCode[this->location+1] != '"' && this->vsopCode[this->location+1] != '\\' && this->vsopCode[this->location+1] != 'x' && this->vsopCode[this->location+1] != '\n')
                {
                    // throw std::runtime_error("Invalid escape sequence after backslash.");
                    print_error(this->line, this->column, "unknown-escape-sequence");
                }

                // Skip all leading whitespace on the next line
                while (std::isspace(this->vsopCode[this->location+1]))
                {
                    if(this->vsopCode[this->location+1] == '\n' && this->vsopCode[this->location] != '\\'){
                        // It is an error if a string literal contains a raw line feed
                        // throw std::runtime_error("Raw line feed in string literal.");
                        print_error(this->line, this->column, "invalid-lf-in-string");
                    }
                    advance();
                }

                if (this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == 'b' && this->vsopCode[this->location] == '\\')
                {
                    tokenValue += char2hex('\b');
                    advance();
                }
                else if(this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == 't' && this->vsopCode[this->location] == '\\'){
                    tokenValue += char2hex('\t');
                    advance();
                }
                else if (this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == 'n' && this->vsopCode[this->location] == '\\')
                {
                    if(this->vsopCode[this->location+2] == '\n' && this->vsopCode[this->location+1] != '\\'){
                        // \n inserted before end of line instead of \ only
                        // throw std::runtime_error("Backslash n inserted before end of line !");
                        print_error(this->line, this->column, "invalid-lf-in-string");
                    }
                    tokenValue += char2hex('\n');
                    advance();
                }
                else if(this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == 'r' && this->vsopCode[this->location] == '\\'){
                    tokenValue += char2hex('\r');
                    advance();
                }
                else if(this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == '"' && this->vsopCode[this->location] == '\\'){
                    // throw std::runtime_error("Incorrect Use of Quotes");
                    // \" double-quote (not ending the string)
                    tokenValue += char2hex('\"');
                    advance();
                }
                else if(this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == '\\' && this->vsopCode[this->location] == '\\'){
                    tokenValue += char2hex('\\');
                    advance();
                }
                else if(this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == 'x' && this->vsopCode[this->location] == '\\'){
                    if(std::isxdigit(this->vsopCode[this->location+2]) && std::isxdigit(this->vsopCode[this->location+3])){
                        tokenValue += char2hex(std::stoi(this->vsopCode.substr(this->location+2, 2), nullptr, 16));
                        advance();
                        advance();
                        advance();
                    }
                    else
                    {
                        // throw std::runtime_error("Invalid hexadecimal character byte sequence.");
                        print_error(this->line, this->column, "wrong-hex-number");
                    }
                }
                advance();
            }
            else
            {
                if(this->vsopCode[this->location+1] == '\n' && this->vsopCode[this->location] != '\\'){
                    // It is an error if a string literal contains a raw line feed
                    // throw std::runtime_error("Raw line feed in string literal Fuck.");
                    print_error(this->line, this->column, "invalid-lf-in-string");
                }

                if(this->vsopCode[this->location]=='\\'){
                    tokenValue += char2hex('\\');
                }
                else{
                    tokenValue += this->vsopCode[this->location];
                    advance();
                }
            }
        }
        if (this->location >= this->vsopCode.length() || this->vsopCode[this->location] != '"')
        {
            // throw std::runtime_error("Unterminated string literal.");
            print_error(startLine, startColumn, "unterminated-string");
        }
        tokenValue += '"'; // Add the closing quote
        advance(); // Skip the closing quote
    
        return {Tokens::Token::TClass::STRING_LITERAL, tokenValue, startLine, startColumn};
    }

    Tokens::Token LexicalAnalyzer::get_next_token()
    {
        skip_space_and_comment();

        if (this->location >= this->vsopCode.length())
        {
            return {Tokens::Token::TClass::END_OF_FILE, "", this->line, this->column};
        }

        char currentChar = this->vsopCode[this->location];

        if (std::isalpha(currentChar))
        {
            return scanIdentifier();
        }
        else if (std::isdigit(currentChar))
        {
            return scanIntegerLiteral();
        }
        else if (currentChar == '"')
        {
            return scanStringLiteral();
        }
        else
        {
            size_t startLine = this->line;
            size_t startColumn = this->column;
            switch (currentChar)
            {
            case '{':
                advance();
                return {Tokens::Token::TClass::LBRACE, "{", startLine, startColumn};
            case '}':
                advance();
                return {Tokens::Token::TClass::RBRACE, "}", startLine, startColumn};
            case '(':
                advance();
                return {Tokens::Token::TClass::LPAR, "(", startLine, startColumn};
            case ')':
                advance();
                return {Tokens::Token::TClass::RPAR, ")", startLine, startColumn};
            case ';':
                advance();
                return {Tokens::Token::TClass::SEMICOLON, ";", startLine, startColumn};
            case ':':
                advance();
                return {Tokens::Token::TClass::COLON, ":", startLine, startColumn};
            case ',':
                advance();
                return {Tokens::Token::TClass::COMMA, ",", startLine, startColumn};
            case '+':
                advance();
                return {Tokens::Token::TClass::PLUS, "+", startLine, startColumn};
            case '-':
                advance();
                return {Tokens::Token::TClass::MINUS, "-", startLine, startColumn};
            case '*':
                advance();
                return {Tokens::Token::TClass::TIMES, "*", startLine, startColumn};
            case '/':
                advance();
                return {Tokens::Token::TClass::DIV, "/", startLine, startColumn};
            case '^':
                advance();
                return {Tokens::Token::TClass::POW, "^", startLine, startColumn};
            case '.':
                advance();
                return {Tokens::Token::TClass::DOT, ".", startLine, startColumn};
            case '=':
                advance();
                return {Tokens::Token::TClass::EQUAL, "=", startLine, startColumn};
            case '<':
                // If currentChar is '<', we need to check if the next character is '=' or '-'
                if (this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '=')
                {
                    advance();
                    advance();
                    return {Tokens::Token::TClass::LOWER_EQUAL, "<=", startLine, startColumn};
                }
                else if (this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '-')
                {
                    advance();
                    advance();
                    return {Tokens::Token::TClass::ASSIGN, "<-", startLine, startColumn};
                }
                else
                {
                    advance();
                    return {Tokens::Token::TClass::LOWER, "<", startLine, startColumn};
                }
            default:
                print_error(this->line, this->column, "Invalid VSOP character");
                advance();
                return get_next_token();
            }
        }
    }

    void LexicalAnalyzer::print_error(size_t line, size_t column, const string &lexicalErrorDescription) const
    {
        cerr << this->vsopFileName << ":" << line << ":" << column << " lexical error: " << lexicalErrorDescription << endl;
    }
}