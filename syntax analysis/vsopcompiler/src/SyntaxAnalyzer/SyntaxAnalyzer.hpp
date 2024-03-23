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
// Give prototype of yylex() function, then declare it.
#define YY_DECL Parser::symbol_type yylex(SyntaxAnalyzer& synAnalysis)
    YY_DECL;

    /**
     * Class representing a SyntaxAnalyzer for the compiler.
     */
    class SyntaxAnalyzer
    {
    public:
        SyntaxAnalyzer(const std::string &sourceFile, const std::string &sourceFileName);
        Program<void> *program;
        Parser::symbol_type YYlex();
        int parse();
        Parser::symbol_type convertLexTokenToParseToken(Tokens::Token token, const Parser::location_type &loc);

    protected:
        //std::unique_ptr<Compilers::Parsers::Parser> parser; /**< Pointer to the parser instance. */
        std::unique_ptr<LexicalAnalyzers::LexicalAnalyzer> lexAnalysis; /**< Pointer to the lexical analyzer instance. */
    };

} // namespace Compilers::SyntaxAnalyzers

#endif // SYNTAXANALYZER_HPP
