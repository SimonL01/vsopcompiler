#include <memory>
#include <iostream>
#include <map>
#include <string>

#include "Compiler.hpp"

using Compilers::Compiler;
using std::cout;
using std::endl;
using std::make_unique;
using std::map;
using std::string;
using std::unique_ptr;

/**
 * Enumeration representing the mode of operation.
 */
enum class Mode
{
    LEX,  /**< Lexical analysis mode. */
    PARSE /**< Parsing mode. */
};

/**
 * Map to associate command line flags with modes.
 */
static const map<string, Mode> flagToMode = {
    {"-l", Mode::LEX},
    {"-p", Mode::PARSE}};

/**
 * Main function for the compiler program.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return EXIT_SUCCESS if compilation succeeds, EXIT_FAILURE otherwise.
 */
int main(int argc, char const *argv[])
{
    Mode mode;         // Mode of operation
    string sourceFile; // Source file name

    // Parse command-line arguments
    if (argc == 2)
    {
        mode = Mode::PARSE;
        sourceFile = argv[1];
    }
    else if (argc == 3)
    {
        if (flagToMode.count(argv[1]) == 0)
        {
            cout << "Invalid mode: " << argv[1] << endl;
            return EXIT_FAILURE;
        }
        mode = flagToMode.at(argv[1]);
        sourceFile = argv[2];
    }
    else
    {
        cout << "Usage: " << argv[0] << " [-l|-p] <sourceFile>" << endl;
        return EXIT_FAILURE;
    }

    // Create compiler instance
    unique_ptr<Compiler> compiler = make_unique<Compiler>(sourceFile);

    // Perform compilation based on selected mode
    int opSuccess;
    switch (mode)
    {
    case Mode::LEX:
        opSuccess = compiler->lex();
        if (opSuccess == 0)
        {
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }

    case Mode::PARSE:
        opSuccess = compiler->parse();
        if (opSuccess == 0)
        {
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }

    default:
        cout << "Unknown mode." << endl;
        return EXIT_FAILURE;
    }
}