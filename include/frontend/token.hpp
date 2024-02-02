#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace cask::frontend
{
    enum TokenType
    {
        token_spacing,
        token_comment,
        token_keyword,
        token_typename,
        token_identifier,
        token_op_assignment,
        token_op_or,
        token_op_and,
        token_op_equality,
        token_op_inequality,
        token_op_less,
        token_op_greater,
        token_op_less_equals,
        token_op_greater_equals,
        token_op_multiply,
        token_op_divide,
        token_op_plus,
        token_op_minus,
        token_boolean,
        token_integer,
        token_float,
        token_string,
        token_comma,
        token_colon,
        token_left_brace,
        token_right_brace,
        token_left_brack,
        token_right_brack,
        token_left_paren,
        token_right_paren,
        token_eof,
        token_unknown
    };

    struct Token
    {
        size_t begin;
        size_t length;
        TokenType type;
    };

    const char* viewToken(const Token& token, const std::string& source);

    [[nodiscard]] std::string stringifyToken(const Token& token, const std::string& source);
}

#endif