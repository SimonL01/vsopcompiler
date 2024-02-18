#include <iostream>


#include "Token.hpp"

using std::cout;
using std::endl;
using std::string;

namespace Compilers::Tokens
{
    // Converts the "TClass" enum values into their string representations
    string Token::token_ToString(TClass tokenClass)
    {
        switch (tokenClass)
        {
        case TClass::AND:
            return "and";
        case TClass::BOOL:
            return "bool";
        case TClass::CLASS:
            return "class";
        case TClass::DO:
            return "do";
        case TClass::ELSE:
            return "else";
        case TClass::EXTENDS:
            return "extends";
        case TClass::FALSE:
            return "false";
        case TClass::IF:
            return "if";
        case TClass::IN:
            return "in";
        case TClass::INT32:
            return "int32";
        case TClass::ISNULL:
            return "isnull";
        case TClass::LET:
            return "let";
        case TClass::NEW:
            return "new";
        case TClass::NOT:
            return "not";
        case TClass::SELF:
            return "self";
        case TClass::STRING:
            return "string";
        case TClass::THEN:
            return "then";
        case TClass::TRUE:
            return "true";
        case TClass::UNIT:
            return "unit";
        case TClass::WHILE:
            return "while";
        case TClass::TYPE_IDENTIFIER:
            return "type-identifier";
        case TClass::OBJECT_IDENTIFIER:
            return "object-identifier";
        case TClass::INTEGER_LITERAL:
            return "integer-literal";
        case TClass::STRING_LITERAL:
            return "string-literal";
        case TClass::LBRACE:
            return "lbrace";
        case TClass::RBRACE:
            return "rbrace";
        case TClass::LPAR:
            return "lpar";
        case TClass::RPAR:
            return "rpar";
        case TClass::COLON:
            return "colon";
        case TClass::SEMICOLON:
            return "semicolon";
        case TClass::COMMA:
            return "comma";
        case TClass::PLUS:
            return "plus";
        case TClass::MINUS:
            return "minus";
        case TClass::TIMES:
            return "times";
        case TClass::DIV:
            return "div";
        case TClass::POW:
            return "pow";
        case TClass::DOT:
            return "dot";
        case TClass::EQUAL:
            return "equal";
        case TClass::LOWER:
            return "lower";
        case TClass::LOWER_EQUAL:
            return "lower-equal";
        case TClass::ASSIGN:
            return "assign";
        default:
            return "unknow value";
        }
    }

    // Default constructor that initializes a token with no parameters
    Token::Token()
    {  
    }

    // Constructor that takes "TClass, "line" and "column" as parameters to initialize a token without a value.
    Token::Token(TClass tokenClass, size_t line, size_t column) : tokenClass(tokenClass), tokenValue(""), line(line), column(column)
    {
    }

    // Constructor that takes "TClass, "tokenValue", "line" and "column" as parameters to initialize a token with a value (as a string).
    Token::Token(TClass tokenClass, string tokenValue, size_t line, size_t column) : tokenClass(tokenClass), tokenValue(tokenValue), line(line), column(column)
    {
    }

    // Returns the token class "TClass" of the token
    Token::TClass Token::get_tokenClass() const
    {
        return this->tokenClass;
    }

    // Prints the token's details to standard output
    void Token::print_token() const
    {
        if (tokenValue.empty())
        {
            cout << this->line << "," << this->column << "," << token_ToString(this->tokenClass) << endl;
        }
        else
        {
            cout << this->line << "," << this->column << "," << token_ToString(this->tokenClass) << "," << this->tokenValue << endl;
        }
    }

}