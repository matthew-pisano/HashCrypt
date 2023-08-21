//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_BASE_IO_H
#define MATHESISDOC_BASE_IO_H

#include <filesystem>
#include <fstream>
#include <string>
#include "utils.h"

class Reader {
    std::filesystem::path filepath;

public:

    Reader() = default;
    Reader(std::string filepath);
    std::string read();
    virtual std::string decode(std::string raw) = 0;
};

class Writer {
    std::filesystem::path filepath;

public:
    Writer() = default;
    Writer(std::string filepath);
    void write(const std::string& content);
    virtual std::string encode(std::string raw) = 0;
};

#endif //MATHESISDOC_BASE_IO_H
