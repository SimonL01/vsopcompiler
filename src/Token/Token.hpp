#ifndef TOKEN_HPP
#define TOKEN_HPP

/* Includes */
#include <string>

namespace Compilers::Tokens
{
    class Token
    {
    public:
        enum class TClass
        {
            AND,
            BOOL,
            CLASS,
            DO,
            ELSE,
            EXTENDS,
            FALSE,
            IF,
            IN,
            INT32,
            ISNULL,
            LET,
            NEW,
            NOT,
            SELF,
            STRING,
            THEN,
            TRUE,
            UNIT,
            WHILE,
            TYPE_IDENTIFIER,
            OBJECT_IDENTIFIER,
            INTEGER_LITERAL,
            STRING_LITERAL,
            LBRACE,
            RBRACE,
            LPAR,
            RPAR,
            COLON,
            SEMICOLON,
            COMMA,
            PLUS,
            MINUS,
            TIMES,
            DIV,
            POW,
            DOT,
            EQUAL,
            LOWER,
            LOWER_EQUAL,
            ASSIGN,
            NOT_A_TOKEN,
            END_OF_FILE
        };

        static std::string token_ToString(TClass tokenClass);

    public:
        Token();
        Token(TClass tokenClass, size_t line, size_t column);
        Token(TClass tokenClass, std::string tokenValue, size_t line, size_t column);
        TClass get_tokenClass() const;
        void print_token() const;

    protected:
        TClass tokenClass;
        std::string tokenValue;
        size_t line;
        size_t column;
    };

} // namespace Compiler::LexicalAnalyzer

#endif // TOKEN_HPP