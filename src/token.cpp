/**
 * @file token.cpp
 * @author DrkWithT
 * @brief Implements Token.
 * @date 2024-01-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <exception>
#include "frontend/token.hpp"

using namespace cask::frontend;

const char* viewToken(const Token& token, const std::string& source)
{
    if (token.type == token_eof || token.length == 0)
        return nullptr;

    return source.c_str() + token.begin;
}

[[nodiscard]] std::string stringifyToken(const Token& token, const std::string& source)
{
    if (token.type == token_eof || token.length == 0)
        throw std::invalid_argument {"stringifyToken: invalid Token to stringify"};

    return source.substr(token.begin, token.length);
}
