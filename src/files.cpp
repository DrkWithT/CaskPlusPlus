/**
 * @file files.cpp
 * @author DrkWithT
 * @brief Implements file reading helpers for parser.
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <fstream>
#include "utils/files.hpp"

char* readFile(const std::string& file_path, size_t* read_count)
{
    std::ifstream reader {};

    reader.open(file_path);

    if (!reader.is_open())
    {
        *read_count = 0;
        return nullptr;
    }

    size_t file_size = 0;

    reader.seekg(0, std::ios::end);
    file_size = reader.tellg();
    reader.seekg(0, std::ios::beg);

    char* contents = new char[file_size + 1];

    bool read_ok = reader.read(contents, file_size).bad();

    if (!read_ok)
    {
        delete[] contents;
        contents = nullptr;
        *read_count = 0;
    }
    else
    {
        contents[file_size] = '\0';
        *read_count = file_size;
    }

    return contents;
}
