#include <iostream>
#include <fstream>

#include "Compiler.hpp"
#include "./Token/Token.hpp"

// #define ABSOLUTE_PATH "./srcFile/"
#define ABSOLUTE_PATH "./"

using Compilers::LexicalAnalyzers::LexicalAnalyzer;
using Compilers::Parsers::SyntaxAnalyzer;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::make_unique;
using std::string;
using std::vector;

namespace Compilers
{
    Compiler::Compiler(string sourceFile) : lexAnalysis(make_unique<LexicalAnalyzer>(this->readFileToString(ABSOLUTE_PATH + sourceFile), sourceFile)), synAnalysis(make_unique<SyntaxAnalyzer>(this->readFileToString(ABSOLUTE_PATH + sourceFile), sourceFile)), sourceFilePath(ABSOLUTE_PATH + sourceFile)
    {
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
        }
        else
        {
            cout << "Unable to open file " << filename << endl;
        }
        return content;
    }

    int Compiler::lex()
    {
        this->lexAnalysis->tokenize();
        vector<Tokens::Token> tokens = this->lexAnalysis->get_tokens();
        if (this->lexAnalysis->get_opSucces() == 0)
        {
            for (const Tokens::Token &token : tokens)
            {
                token.print_token();
            }
        }
        return this->lexAnalysis->get_opSucces();
    }

    int Compiler::parse()
    {
        int opSucces = this->synAnalysis->parse();
        return opSucces;
    }
}