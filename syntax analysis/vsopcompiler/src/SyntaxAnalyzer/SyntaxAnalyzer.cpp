#include <iostream>
#include <string>
#include <vector>

#include "SyntaxAnalyzer.hpp"
#include "location.hh"

using Compilers::LexicalAnalyzers::LexicalAnalyzer;
using std::cerr;
using std::cout;
using std::endl;
using std::isspace;
using std::make_unique;
using std::pair;
using std::string;
using std::unique_ptr;
using std::vector;

namespace Compilers::Parsers
{
    string FILE_NAME;

    static void init_filename(SyntaxAnalyzer &synAnalysis)
    {
        FILE_NAME = synAnalysis.get_filename();
    }

    Parser::symbol_type yylex(SyntaxAnalyzer &synAnalysis)
    {
        return synAnalysis.YYlex();
    }
    // Function to convert a TClass token to a ParserToken
    Parser::symbol_type SyntaxAnalyzer::convertLexTokenToParseToken(Tokens::Token token, const Parser::location_type &loc)
    {
        switch (token.get_tokenClass())
        {
        case Tokens::Token::TClass::END_OF_FILE:
            return Parser::make_YYEOF(loc);
        case Tokens::Token::TClass::AND:
            return Parser::make_AND("and", loc);
        case Tokens::Token::TClass::BOOL:
            return Parser::make_BOOL("bool", loc);
        case Tokens::Token::TClass::CLASS:
            return Parser::make_CLASS("class", loc);
        case Tokens::Token::TClass::DO:
            return Parser::make_DO("do", loc);
        case Tokens::Token::TClass::ELSE:
            return Parser::make_ELSE("else", loc);
        case Tokens::Token::TClass::EXTENDS:
            return Parser::make_EXTENDS("extends", loc);
        case Tokens::Token::TClass::FALSE:
            return Parser::make_FALSE("false", loc);
        case Tokens::Token::TClass::IF:
            return Parser::make_IF("if", loc);
        case Tokens::Token::TClass::IN:
            return Parser::make_IN("in", loc);
        case Tokens::Token::TClass::INT32:
            return Parser::make_INT32("int32", loc);
        case Tokens::Token::TClass::ISNULL:
            return Parser::make_ISNULL("isnull", loc);
        case Tokens::Token::TClass::LET:
            return Parser::make_LET("let", loc);
        case Tokens::Token::TClass::NEW:
            return Parser::make_NEW("new", loc);
        case Tokens::Token::TClass::NOT:
            return Parser::make_NOT("not", loc);
        case Tokens::Token::TClass::SELF:
            return Parser::make_SELF("self", loc);
        case Tokens::Token::TClass::STRING:
            return Parser::make_STRING("string", loc);
        case Tokens::Token::TClass::THEN:
            return Parser::make_THEN("then", loc);
        case Tokens::Token::TClass::TRUE:
            return Parser::make_TRUE("true", loc);
        case Tokens::Token::TClass::UNIT:
            return Parser::make_UNIT("unit", loc);
        case Tokens::Token::TClass::WHILE:
            return Parser::make_WHILE("while", loc);
        case Tokens::Token::TClass::TYPE_IDENTIFIER:
            return Parser::make_TYPE_IDENTIFIER(token.get_tokenValue(), loc);
        case Tokens::Token::TClass::OBJECT_IDENTIFIER:
            return Parser::make_OBJECT_IDENTIFIER(token.get_tokenValue(), loc);
        case Tokens::Token::TClass::INTEGER_LITERAL:
            return Parser::make_INTEGER_LITERAL(std::stoi(token.get_tokenValue()), loc);
        case Tokens::Token::TClass::STRING_LITERAL:
            return Parser::make_STRING_LITERAL(token.get_tokenValue(), loc);
        case Tokens::Token::TClass::LBRACE:
            return Parser::make_LBRACE("{", loc);
        case Tokens::Token::TClass::RBRACE:
            return Parser::make_RBRACE("}", loc);
        case Tokens::Token::TClass::LPAR:
            return Parser::make_LPAR("(", loc);
        case Tokens::Token::TClass::RPAR:
            return Parser::make_RPAR(")", loc);
        case Tokens::Token::TClass::COLON:
            return Parser::make_COLON(":", loc);
        case Tokens::Token::TClass::SEMICOLON:
            return Parser::make_SEMICOLON(";", loc);
        case Tokens::Token::TClass::COMMA:
            return Parser::make_COMMA(",", loc);
        case Tokens::Token::TClass::PLUS:
            return Parser::make_PLUS("+", loc);
        case Tokens::Token::TClass::MINUS:
            return Parser::make_MINUS("-", loc);
        case Tokens::Token::TClass::TIMES:
            return Parser::make_TIMES("*", loc);
        case Tokens::Token::TClass::DIV:
            return Parser::make_DIVIDE("/", loc);
        case Tokens::Token::TClass::POW:
            return Parser::make_POWER("^", loc);
        case Tokens::Token::TClass::DOT:
            return Parser::make_DOT(".", loc);
        case Tokens::Token::TClass::EQUAL:
            return Parser::make_EQUAL("=", loc);
        case Tokens::Token::TClass::LOWER:
            return Parser::make_LOWER("<", loc);
        case Tokens::Token::TClass::LOWER_EQUAL:
            return Parser::make_LOWER_EQUAL("<=", loc);
        case Tokens::Token::TClass::ASSIGN:
            return Parser::make_ASSIGN("<-", loc);
        default:
            return Parser::make_YYUNDEF(loc);
        }
    }

    SyntaxAnalyzer::SyntaxAnalyzer(const std::string &sourceFile, const std::string &sourceFileName) : lexAnalysis(make_unique<LexicalAnalyzer>(sourceFile, sourceFileName))
    {
    }

    Parser::symbol_type SyntaxAnalyzer::YYlex()
    {
        Tokens::Token token = this->lexAnalysis->get_next_token();

        /* token position definition */
        position posBegin;
        position posEnd;
        position::filename_type fileName = *make_unique<string>(this->lexAnalysis->get_file_name());
        position::counter_type line = token.get_line();
        position::counter_type column = token.get_column();

        posBegin.filename = &fileName;
        posBegin.line = line;
        posBegin.column = column;

        posEnd.filename = &fileName;
        posEnd.line = posBegin.line + token.get_tokenValue().length();
        posEnd.column = posBegin.column;

        /* token location definition */
        Parser::location_type loc = location(posBegin, posEnd);

        Parser::symbol_type pToken = convertLexTokenToParseToken(token, loc);
        return pToken;
    }

    std::string SyntaxAnalyzer::get_filename()
    {
        return this->lexAnalysis->get_file_name();
    }

    int SyntaxAnalyzer::parse()
    {
        std::unique_ptr<Compilers::Parsers::Parser> parser = make_unique<Parser>(*this);
        init_filename(*this); // Initialize the FILE_NAME global variable
        int opSucces = parser->parse();

        if (opSucces == 0)
        {
            unique_ptr<PrintVisitor> printVisitor = make_unique<PrintVisitor>();
            program->accept(*printVisitor);
            delete program;
        }

        return opSucces;
    }
}