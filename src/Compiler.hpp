#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <memory>
#include <string>

#include "./LexicalAnalyzer/LexicalAnalyzer.hpp"

/**
 * Namespace containing compiler-related classes and functions.
 */
namespace Compilers
{
    /**
     * Class representing a compiler instance.
     */
    class Compiler
    {
    public:
        /**
         * Constructor for Compiler class.
         *
         * @param sourceFile Path to the source file to be compiled.
         */
        Compiler(std::string sourceFile);

        /**
         * Reads contents of a file into a string.
         *
         * @param filename Name of the file to read.
         * @return String containing the contents of the file.
         */
        std::string readFileToString(const std::string &filename);

        /**
         * Performs lexical analysis on the source file.
         *
         * @return 0 if lexical analysis succeeds, non-zero otherwise.
         */
        int lex();

        /**
         * Performs parsing on the source file.
         *
         * @return 0 if parsing succeeds, non-zero otherwise.
         */
        int parse();

    protected:
        std::unique_ptr<Compilers::LexicalAnalyzers::LexicalAnalyzer> lexAnalysis; /**< Pointer to the lexical analyzer instance. */
        std::string sourceFilePath;                                                /**< Path to the source file. */
    };
} // namespace Compilers

#endif // COMPILER_HPP
