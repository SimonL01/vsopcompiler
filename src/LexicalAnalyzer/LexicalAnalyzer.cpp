#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <stdlib.h>
#include <stdexcept>

#include "LexicalAnalyzer.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Compilers::LexicalAnalyzers
{
    // Convert a string to an int, if possible
    // Returns -1 if conversion fails
    static int str2maybeint(const string &s)
    {
        size_t l = s.length();

        if (l > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        {
            for (size_t i = 2; i < l; ++i)
            {
                if (!std::isxdigit(s[i]))
                {
                    return -1;
                }
            }
            try
            {
                return std::stoi(s, nullptr, 16);
            }
            catch (const std::out_of_range &)
            {
                return -1; // Gestion de dépassement de capacité
            }
        }

        for (size_t i = 0; i < l; ++i)
        {
            if (!std::isdigit(s[i]))
            {
                return -1;
            }
        }
        try
        {
            return std::stoi(s, nullptr, 10);
        }
        catch (const std::out_of_range &)
        {
            return -1; // Gestion de dépassement de capacité
        }
    }

    static std::string char2hex(char c) {
        std::string s = "\\x00";

        char d = c / 16;
        s[2] = d + (d < 10 ? '0' : 'a' - 10);
        d = c % 16;
        s[3] = d + (d < 10 ? '0' : 'a' - 10);

        return s;
    }

    LexicalAnalyzer::LexicalAnalyzer(const string &sourceFile) : vsopCode(sourceFile), location(0), line(1), column(1)
    {
        this->keyWordMap = {
            {"and", Tokens::Token::TClass::AND},
            {"bool", Tokens::Token::TClass::BOOL},
            {"class", Tokens::Token::TClass::CLASS},
            {"do", Tokens::Token::TClass::DO},
            {"else", Tokens::Token::TClass::ELSE},
            {"extends", Tokens::Token::TClass::EXTENDS},
            {"flase", Tokens::Token::TClass::FALSE},
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
            tokens.push_back(token);
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
        while (this->location < this->vsopCode.length() && (std::isspace(this->vsopCode[this->location]) || this->vsopCode[this->location] == '/'))
        {
            if (this->vsopCode[this->location] == '\n')
            {
                this->line++;
                this->column = 1;
            }
            else if (this->vsopCode[this->location] == '/')
            {
                if (this->location + 1 < this->vsopCode.length() && this->vsopCode[this->location + 1] == '/')
                {
                    // Skip the entire comment line
                    while (this->location < this->vsopCode.length() && this->vsopCode[this->location] != '\n')
                    {
                        this->location++;
                    }
                    // Handle the case where the comment line ends with '\n'
                    if (this->location < this->vsopCode.length() && this->vsopCode[this->location] == '\n')
                    {
                        this->line++;
                        this->column = 1;
                    }
                }
                else
                {
                    // Not a comment, just a regular '/'
                    return;
                }
            }
            else
            {
                this->column++;
            }
            this->location++;
        }
    }
    /* @TODO modify this one to differentiate type identifier and object identifier */
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
        // find returns an iterator to the element if found, otherwise it returns an iterator to the end of the map
        auto it = this->keyWordMap.find(tokenValue);
        if (it != keyWordMap.end())
        {
            return {it->second, tokenValue, startLine, this->column};
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
        std::string tokenValue;
        size_t startLine = this->line;
        size_t startColumn = this->column;
        while (this->location < this->vsopCode.length() && std::isdigit(this->vsopCode[this->location]))
        {
            tokenValue += this->vsopCode[this->location];
            advance();
        }
        return {Tokens::Token::TClass::INTEGER_LITERAL, tokenValue, startLine, startColumn};
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
        advance(); // Skip the opening quote


        while (this->location < this->vsopCode.length() && this->vsopCode[this->location] != '"')
        {
            // Si le character est \\, alors je vérifie la suite en essayant de respecter les guidelines
            if (this->vsopCode[this->location] == '\\') // \\ is an escape sequence for a SINGLE backslash
            {
                // It is an error if a string contains an invalid escape sequence
                if(this->vsopCode[this->location+1] != 'b' && this->vsopCode[this->location+1] != 't' && this->vsopCode[this->location+1] != 'n' && this->vsopCode[this->location+1] != 'r' && this->vsopCode[this->location+1] != '"' && this->vsopCode[this->location+1] != '\\' && this->vsopCode[this->location+1] != 'x' && this->vsopCode[this->location+1] != '\n')
                {
                    throw std::runtime_error("Invalid escape sequence.");
                }

                // Skip all leading whitespace on the next line
                while (std::isspace(this->vsopCode[this->location+1]))
                {
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
                    tokenValue += '"';
                    advance();
                }
                else if(this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == '\\' && this->vsopCode[this->location] == '\\'){
                    tokenValue += '\\';
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
                        throw std::runtime_error("Invalid hexadecimal character byte sequence.");
                    }
                }
                else
                {   
                    if(this->vsopCode[this->location] == '\n'){
                    throw std::runtime_error("Backslash not followed by end of line.");
                    }
                }
                advance();
            }
            else
            {
                if(this->vsopCode[this->location] != '\n' && this->vsopCode[this->location-1] == '\\'){
                    // raw line feed error
                    throw std::runtime_error("Raw line feed in string literal.");
                }
                tokenValue += this->vsopCode[this->location];
                advance();
            }
        }
        if (this->location >= this->vsopCode.length() || this->vsopCode[this->location] != '"')
        {
            throw std::runtime_error("Unterminated string literal.");
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
            switch (currentChar)
            {
            case '{':
                advance();
                return {Tokens::Token::TClass::LBRACE, "{", this->line, this->column};
            case '}':
                advance();
                return {Tokens::Token::TClass::RBRACE, "}", this->line, this->column};
            case '(':
                advance();
                return {Tokens::Token::TClass::LPAR, "(", this->line, this->column};
            case ')':
                advance();
                return {Tokens::Token::TClass::RPAR, ")", this->line, this->column};
            case ';':
                advance();
                return {Tokens::Token::TClass::SEMICOLON, ";", this->line, this->column};
            case ':':
                advance();
                return {Tokens::Token::TClass::COLON, ":", this->line, this->column};
            case ',':
                advance();
                return {Tokens::Token::TClass::COMMA, ",", this->line, this->column};
            case '+':
                advance();
                return {Tokens::Token::TClass::PLUS, "+", this->line, this->column};
            case '-':
                advance();
                return {Tokens::Token::TClass::MINUS, "-", this->line, this->column};
            case '*':
                advance();
                return {Tokens::Token::TClass::TIMES, "*", this->line, this->column};
            case '/':
                advance();
                return {Tokens::Token::TClass::DIV, "/", this->line, this->column};
            case '^':
                advance();
                return {Tokens::Token::TClass::POW, "^", this->line, this->column};
            case '.':
                advance();
                return {Tokens::Token::TClass::DOT, ".", this->line, this->column};
            case '=':
                advance();
                return {Tokens::Token::TClass::EQUAL, "=", this->line, this->column};
            case '<':
                // If currentChar is '<', we need to check if the next character is '=' or '-'
                if (this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == '=')
                {
                    advance();
                    advance();
                    return {Tokens::Token::TClass::LOWER_EQUAL, "<=", this->line, this->column};
                }
                else if (this->location+1 < this->vsopCode.length() && this->vsopCode[this->location+1] == '-')
                {
                    advance();
                    advance();
                    return {Tokens::Token::TClass::ASSIGN, "<-", this->line, this->column};
                }
                else
                {
                    return {Tokens::Token::TClass::LOWER, "<", this->line, this->column};
                }
            default:
                throw std::runtime_error("Invalid token.");
            }
        }
    }
}

/*
char LexicalAnalyzer::get_next_char() const
{
    if (this->location < this->sourceFile.size())
    {
        return sourceFile[location];
    }
    return '\0';
}

char LexicalAnalyzer::get_second_next_char() const
{
    if (this->location + 1 < this->sourceFile.size())
    {
        return sourceFile[location + 1];
    }
    return '\0';
}

void LexicalAnalyzer::consume_next_char()
{
    if (this->location < this->sourceFile.size())
    {
        if (this->sourceFile[this->location] == '\n')
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
    while (isspace(get_next_char()) || get_next_char() == '/' || get_next_char() == '(')
    {
        if (get_next_char() == '/')
        {
            if (get_second_next_char() == '/')
            {
                consume_next_char();
                consume_next_char();
                while (get_next_char() != '\n' && get_next_char() != '\0')
                {
                    consume_next_char();
                }
            }
            else
            {
                return;
            }
        }
        else if (get_next_char() == '(')
        {
            if (get_second_next_char() == '*')
            {
                consume_next_char();
                consume_next_char();
                // @TODO incorrect is to correct  //
                size_t nestedLevel = 1;
                while (nestedLevel > 0 && get_next_char() != '\0')
                {
                    char currentChar = get_next_char();
                    consume_next_char();
                    if (currentChar == '*' && get_next_char() == ')')
                    {
                        consume_next_char(); // Consomme le ')'
                        nestedLevel--;
                    }
                    else if (currentChar == '(' && get_next_char() == '*')
                    {
                        consume_next_char(); // Consomme le '*'
                        nestedLevel++;
                    }
                }
                if (get_next_char() == '\0')
                {
                    std::cerr << "multiline comment not finish" << std::endl;
                }
            }else
            {
                break;
            }
        }
        else
        {
            consume_next_char(); // consumme spaces
        }
    }
}
}*/