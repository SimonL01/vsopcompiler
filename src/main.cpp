#include <memory>
#include <iostream>
#include <map>
#include <string>

#include "Compiler.hpp"

#define ABSOLUTE_PATH "./srcFile/"

using Compilers::Compiler;
using std::cout;
using std::endl;
using std::make_unique;
using std::map;
using std::string;
using std::unique_ptr;

enum class Mode
{
    LEX,
    PARSE
};

static const map<string, Mode> flagToMode = {
    {"-l", Mode::LEX},
    {"-p", Mode::PARSE}};

int main(int argc, char const *argv[])
{
    Mode mode;
    string sourceFile;

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

    unique_ptr<Compiler> compiler = make_unique<Compiler>(ABSOLUTE_PATH + sourceFile);

    int opSucces;
    switch (mode)
    {
    case Mode::LEX:
        opSucces = compiler->lex();
        if (opSucces == 0)
        {
            // print the value
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }

    case Mode::PARSE:
        opSucces = compiler->parse();
        if (opSucces == 0)
        {
            // print the value
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }
    default:
        return EXIT_FAILURE;
    }
}
