#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace Compilers::Tokens
{
    /**
     * @brief Class representing a token in the compiler.
     */
    class Token
    {
    public:
        /**
         * @brief Enumeration representing the class of the token.
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
         * @brief Convert a token class enumeration value to its string representation.
         *
         * @param tokenClass Token class enumeration value.
         * @return std::string String representation of the token class.
         */
        static std::string token_ToString(TClass tokenClass);

    public:
        /**
         * @brief Default constructor for Token class.
         */
        Token();

        /**
         * @brief Constructor for Token class with specified token class, line, and column.
         *
         * @param tokenClass Class of the token.
         * @param line Line number of the token.
         * @param column Column number of the token.
         */
        Token(TClass tokenClass, size_t line, size_t column);

        /**
         * @brief Constructor for Token class with specified token class, value, line, and column.
         *
         * @param tokenClass Class of the token.
         * @param tokenValue Value of the token (if applicable).
         * @param line Line number of the token.
         * @param column Column number of the token.
         */
        Token(TClass tokenClass, std::string tokenValue, size_t line, size_t column);

        /**
         * @brief Get the class of the token.
         *
         * @return TClass Class of the token.
         */
        TClass get_tokenClass() const;

        /**
         * @brief Get the value of the token.
         *
         * @return std::string Value of the token.
         */
        std::string get_tokenValue() const;

        /**
         * @brief Get the line number of the token.
         *
         * @return size_t Line number of the token.
         */
        size_t get_line() const;

        /**
         * @brief Get the column number of the token.
         *
         * @return size_t Column number of the token.
         */
        size_t get_column() const;

        /**
         * @brief Print the token information.
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
