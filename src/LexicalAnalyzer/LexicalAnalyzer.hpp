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
        LexicalAnalyzer(const std::string& sourceFile);
        void tokenize();
        std::vector<Tokens::Token> get_tokens() const;
        void advance();
        void advanceInString();
        void skip_space_and_comment();
        Tokens::Token scanIdentifier();
        Tokens::Token scanIntegerLiteral();
        Tokens::Token scanStringLiteral();
        Tokens::Token get_next_token();

        //char get_next_char() const;
        //char get_second_next_char() const;
        //void consume_next_char();
        //void skip_space_and_comment();

    protected:
        std::string vsopCode;
        size_t location;
        size_t line;
        size_t column;
        std::vector<Tokens::Token> tokens;
        std::unordered_map<std::string, Tokens::Token::TClass> keyWordMap;
    };

} // namespace Compiler::LexicalAnalyzer

#endif // LEXICALANALYZER_HPP