#ifndef LEXER_HPP
#define LEXER_HPP

#include <set>
#include <map>
#include <sstream>
#include <string>
#include "frontend/token.hpp"

namespace cask::frontend
{
    enum LexicalWordType
    {
        word_type_keyword,
        word_type_typename,
        word_type_identifier
    };

    class Lexer
    {
    private:
        std::set<std::string> keywords;
        std::set<std::string> typenames;
        std::set<std::string> specials;
        std::unordered_map<std::string, TokenType> operators;
        std::ostringstream sout;
        const char* source_view;
        size_t source_index;
        size_t source_length;

        void skipWhitespace();
    public:
        Lexer(const char* source_cstr, size_t source_cstr_length);

        Token lexSingular(TokenType type);
        Token lexComment();
        Token lexWord();
        Token lexOperator();
        Token lexNumeric();
        Token lexString();
        Token lexNext();

        ~Lexer() = default;
    };
}

#endif