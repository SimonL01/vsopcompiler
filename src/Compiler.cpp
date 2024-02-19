#include <iostream>
#include <fstream>

#include "Compiler.hpp"

using Compilers::LexicalAnalyzers::LexicalAnalyzer;
using std::cout;
using std::endl;
using std::make_unique;
using std::string;
using std::vector;
using std::ifstream;
using std::getline;

namespace Compilers
{
    // Default constructor that initializes the "lexAnalysis" attribute with a hardcoded VSOP code. It uses "std::make_unique" to dynamically allocate a "LexicalAnalyzer" object.
    Compiler::Compiler() : lexAnalysis(make_unique<LexicalAnalyzer>())
    {
    }

    Compiler::Compiler(string sourceFile) : lexAnalysis(make_unique<LexicalAnalyzer>("class MyClass { var x : int := 10; in test : string := \"try this string\"; // Comment here \n method myMethod() : int { return x + 5; } }")), sourceFilePath(sourceFile)
    {
        string vsopCode = this->readFileToString(sourceFile);
        std::cerr << vsopCode << endl;
    }

    std::string Compiler::readFileToString(const std::string &filename)
    {
        ifstream file(filename);
        string content;
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                content += line + '\n';
            }
            file.close();
        } else {
            cout << "Unable to open file " << filename << endl;
        }
        return content;
    }

    int Compiler::lex()
    {
        cout << this->sourceFilePath << endl;
        this->lexAnalysis->tokenize();
        vector<Tokens::Token> tokens = this->lexAnalysis->get_tokens();
        for (const Tokens::Token &token : tokens)
        {
            token.print_token();
        }
        return 0;
    }

    int Compiler::parse()
    {
        return 0;
    }
}