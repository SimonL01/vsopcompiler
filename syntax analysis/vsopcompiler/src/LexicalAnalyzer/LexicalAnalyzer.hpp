#ifndef LEXICALANALYZER_HPP
#define LEXICALANALYZER_HPP

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "../Token/Token.hpp"

namespace Compilers::LexicalAnalyzers
{
    /**
     * Class representing a lexical analyzer for the compiler.
     */
    class LexicalAnalyzer
    {
    public:
        /**
         * Constructor for LexicalAnalyzer class.
         *
         * @param sourceFile Path to the source file.
         * @param sourceFileName Name of the source file.
         */
        LexicalAnalyzer(const std::string &sourceFile, const std::string &sourceFileName);

        /**
         * Tokenizes the source code.
         */
        void tokenize();

        /**
         * Retrieves the tokens generated during tokenization.
         *
         * @return Vector of tokens.
         */
        std::vector<Tokens::Token> get_tokens() const;

        /**
         * Advances the position in the source code.
         */
        void advance();

        /**
         * Advances the position in the source code when encountering a comment.
         */
        void advance_comment();

        /**
         * Checks if the current position corresponds to an operator.
         *
         * @return True if the current position corresponds to an operator, false otherwise.
         */
        bool is_curr_operator();

        /**
         * Skips spaces and comments in the source code.
         */
        void skip_space_and_comment();

        /**
         * Retrieves the operation success flag.
         *
         * @return Operation success flag.
         */
        int get_opSucces();

        /**
         * Scans an identifier from the source code.
         *
         * @return Token representing the scanned identifier.
         */
        Tokens::Token scanIdentifier();

        /**
         * Scans an integer literal from the source code.
         *
         * @return Token representing the scanned integer literal.
         */
        Tokens::Token scanIntegerLiteral();

        /**
         * Scans a string literal from the source code.
         *
         * @return Token representing the scanned string literal.
         */
        Tokens::Token scanStringLiteral();

        /**
         * Retrieves the next token from the source code.
         *
         * @return Next token from the source code.
         */
        Tokens::Token get_next_token();

        /**
         * Prints an error message for lexical analysis.
         *
         * @param line Line number of the error.
         * @param column Column number of the error.
         * @param lexicalErrorDescription Description of the lexical error.
         */
        void print_error(size_t line, size_t column, const std::string &lexicalErrorDescription);

        std::string get_file_name();

        size_t get_column();

        size_t get_line();

    protected:
        std::string vsopCode;                                              /**< Source code to be analyzed. */
        std::string vsopFileName;                                          /**< Name of the source file. */
        size_t location;                                                   /**< Current location in the source code. */
        size_t line;                                                       /**< Current line number. */
        size_t column;                                                     /**< Current column number. */
        int opSucces;                                                      /**< Operation success flag. */
        std::vector<Tokens::Token> tokens;                                 /**< Vector of tokens. */
        std::unordered_map<std::string, Tokens::Token::TClass> keyWordMap; /**< Map of keywords. */
    };

} // namespace Compiler::LexicalAnalyzer

#endif // LEXICALANALYZER_HPP
