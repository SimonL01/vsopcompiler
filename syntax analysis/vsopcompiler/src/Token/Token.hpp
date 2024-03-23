#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace Compilers::Tokens
{
    /**
     * Class representing a token in the compiler.
     */
    class Token
    {
    public:
        /**
         * Enumeration representing the class of the token.
         */
        enum class TClass
        {
            AND,               /**< 'and' keyword. */
            BOOL,              /**< 'bool' keyword. */
            CLASS,             /**< 'class' keyword. */
            DO,                /**< 'do' keyword. */
            ELSE,              /**< 'else' keyword. */
            EXTENDS,           /**< 'extends' keyword. */
            FALSE,             /**< 'false' keyword. */
            IF,                /**< 'if' keyword. */
            IN,                /**< 'in' keyword. */
            INT32,             /**< 'int32' keyword. */
            ISNULL,            /**< 'isnull' keyword. */
            LET,               /**< 'let' keyword. */
            NEW,               /**< 'new' keyword. */
            NOT,               /**< 'not' keyword. */
            SELF,              /**< 'self' keyword. */
            STRING,            /**< 'string' keyword. */
            THEN,              /**< 'then' keyword. */
            TRUE,              /**< 'true' keyword. */
            UNIT,              /**< 'unit' keyword. */
            WHILE,             /**< 'while' keyword. */
            TYPE_IDENTIFIER,   /**< Type identifier token. */
            OBJECT_IDENTIFIER, /**< Object identifier token. */
            INTEGER_LITERAL,   /**< Integer literal token. */
            STRING_LITERAL,    /**< String literal token. */
            LBRACE,            /**< Left brace token '{'. */
            RBRACE,            /**< Right brace token '}'. */
            LPAR,              /**< Left parenthesis token '('. */
            RPAR,              /**< Right parenthesis token ')'. */
            COLON,             /**< Colon token ':'. */
            SEMICOLON,         /**< Semicolon token ';'. */
            COMMA,             /**< Comma token ','. */
            PLUS,              /**< Plus token '+'. */
            MINUS,             /**< Minus token '-'. */
            TIMES,             /**< Multiplication token '*'. */
            DIV,               /**< Division token '/'. */
            POW,               /**< Power token '^'. */
            DOT,               /**< Dot token '.'. */
            EQUAL,             /**< Equal token '='. */
            LOWER,             /**< Lower than token '<'. */
            LOWER_EQUAL,       /**< Lower than or equal token '<='. */
            ASSIGN,            /**< Assignment token ':='. */
            NOT_A_TOKEN,       /**< Not a recognized token. */
            END_OF_FILE        /**< End of file token. */
        };

        /**
         * Convert a token class enumeration value to its string representation.
         *
         * @param tokenClass Token class enumeration value.
         * @return String representation of the token class.
         */
        static std::string token_ToString(TClass tokenClass);

    public:
        /**
         * Default constructor for Token class.
         */
        Token();

        /**
         * Constructor for Token class with specified token class, line, and column.
         *
         * @param tokenClass Class of the token.
         * @param line Line number of the token.
         * @param column Column number of the token.
         */
        Token(TClass tokenClass, size_t line, size_t column);

        /**
         * Constructor for Token class with specified token class, value, line, and column.
         *
         * @param tokenClass Class of the token.
         * @param tokenValue Value of the token (if applicable).
         * @param line Line number of the token.
         * @param column Column number of the token.
         */
        Token(TClass tokenClass, std::string tokenValue, size_t line, size_t column);

        /**
         * Get the class of the token.
         *
         * @return Class of the token.
         */
        TClass get_tokenClass() const;

        std::string get_tokenValue() const;

        /**
         * Print the token information.
         */
        void print_token() const;

    protected:
        TClass tokenClass;      /**< Class of the token. */
        std::string tokenValue; /**< Value of the token (if applicable). */
        size_t line;            /**< Line number of the token. */
        size_t column;          /**< Column number of the token. */
    };

} // namespace Compiler::LexicalAnalyzer

#endif // TOKEN_HPP
