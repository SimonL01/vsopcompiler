#ifndef LEXICALANALYZER_HPP
#define LEXICALANALYZER_HPP

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "../Token/Token.hpp"

namespace Compilers::LexicalAnalyzers
{
    class LexicalAnalyzer
    {
    public:
        LexicalAnalyzer(const std::string &sourceFile, const std::string &sourceFileName);
        void tokenize();
        std::vector<Tokens::Token> get_tokens() const;
        void advance();
        void advance_comment();
        bool is_curr_operator();
        void skip_space_and_comment();
        Tokens::Token scanIdentifier();
        Tokens::Token scanIntegerLiteral();
        Tokens::Token scanStringLiteral();
        Tokens::Token get_next_token();
        void print_error(size_t line, size_t column, const std::string& lexicalErrorDescription) const;

    protected:
        std::string vsopCode;
        std::string vsopFileName;
        size_t location;
        size_t line;
        size_t column;
        std::vector<Tokens::Token> tokens;
        std::unordered_map<std::string, Tokens::Token::TClass> keyWordMap;
    };

} // namespace Compiler::LexicalAnalyzer

#endif // LEXICALANALYZER_HPP