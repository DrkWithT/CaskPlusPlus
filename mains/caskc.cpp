/**
 * @file caskc.cpp
 * @author DrkWithT
 * @brief Bytecode compiler for Cask. 
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include "utils/files.hpp"
#include "frontend/lexer.hpp"

const char* cask_flag_version = "--version";
const char* cask_flag_info = "--info";
const char* cask_flag_warn = "--warnings";
const char* cask_version_cstr = "caskc v0.1.0\nBy: DrkWithT@GitHub";
const char* cask_info_cstr = "caskc options:\n--version\t print version and exit.\n--info\tprint flag info and exit.\n--warnings\tenables compilation warnings.";

int main (int argc, const char* argv[])
{
    if (argc < 2)
    {
        std::cout << cask_info_cstr << '\n';
        return 1;
    }

    bool enable_warnings = false;

    std::string arg_str {argv[1]};

    if (arg_str == cask_flag_version)
    {
        std::cout << cask_version_cstr << '\n';
        return 0;
    }
    else if (arg_str == cask_flag_info)
    {
        std::cout << cask_info_cstr << '\n';
        return 0;
    }
    else if (arg_str == cask_flag_warn)
    {
        enable_warnings = true;
    }
    else
    {
        std::cerr << cask_info_cstr << '\n';
        return 1;
    }

    if (!argv[2])
    {
        std::cerr << "No file path found!\n";
        return 1;
    }

    arg_str = argv[2];

    size_t content_length = 0;
    char* file_contents = readFile(arg_str, &content_length);

    if (!file_contents || content_length < 1)
    {
        std::cerr << "Could not read file!\n";
        return -1;
    }

    cask::frontend::Lexer tokenizer {file_contents, content_length};
    cask::frontend::Token token;

    do
    {
        token = tokenizer.lexNext();

        std::cout << "{.begin = " << token.begin << ", .length = " << token.length << ", .type = " << token.type << "}\n";
    } while (token.type != cask::frontend::TokenType::token_eof);

    if (enable_warnings)
    {
        std::cout << "TODO: add enable_warnings for parsing.\n";
    }

    delete[] file_contents;
    return 0;
}
