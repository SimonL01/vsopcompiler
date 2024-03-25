#ifndef SYNTAXANALYZER_HPP
#define SYNTAXANALYZER_HPP

#include "../Token/Token.hpp"
#include "../LexicalAnalyzer/LexicalAnalyzer.hpp"
#include "AST.hpp"
#include "Parser.hpp"
#include <memory>
#include <unordered_map>

namespace Compilers::Parsers
{
    extern std::string FILE_NAME; /**< Global variable to store the filename. */

    /**
     * Prototype of the yylex() function.
     *
     * @param synAnalysis Reference to the SyntaxAnalyzer object.
     * @return The next token.
     */
    #define YY_DECL Parser::symbol_type yylex(SyntaxAnalyzer& synAnalysis)
    YY_DECL;

    /**
     * Class representing a SyntaxAnalyzer for the compiler.
     */
    class SyntaxAnalyzer
    {
    public:
        /**
         * Constructor for SyntaxAnalyzer class.
         *
         * @param sourceFile Path to the source file.
         * @param sourceFileName Name of the source file.
         */
        SyntaxAnalyzer(const std::string &sourceFile, const std::string &sourceFileName);

        Program<void> *program;

        /**
         * Parses the source code.
         *
         * @return Operation success flag.
         */
        int parse();

        /**
         * Retrieves the filename associated with the syntax analyzer's lexical analyzer.
         *
         * @return Filename.
         */
        std::string get_filename();

        /**
         * Retrieves the next token from the source code.
         *
         * @return Next token from the source code.
         */
        Parser::symbol_type YYlex();

        /**
         * Converts a lexical token to a parse token.
         *
         * @param token The lexical token to be converted.
         * @param loc The location information of the token.
         * @return Parse token.
         */
        Parser::symbol_type convertLexTokenToParseToken(Tokens::Token token, const Parser::location_type &loc);

    protected:
        std::unique_ptr<LexicalAnalyzers::LexicalAnalyzer> lexAnalysis; /**< Pointer to the lexical analyzer instance. */
    };

} // namespace Compilers::SyntaxAnalyzers

#endif // SYNTAXANALYZER_HPP
