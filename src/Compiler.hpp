#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <memory>
#include <string>

#include "./LexicalAnalyzer/LexicalAnalyzer.hpp"

namespace Compilers
{
    class Compiler
    {
    public:
        Compiler(std::string sourceFile);
        std::string readFileToString(const std::string &filename);
        int lex();
        int parse();

    protected:
        std::unique_ptr<Compilers::LexicalAnalyzers::LexicalAnalyzer> lexAnalysis;
        std::string sourceFilePath;
    };
} // namespace Compilers

#endif // COMPILER_HPP