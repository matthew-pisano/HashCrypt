//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_BASE_IO_H
#define MATHESISDOC_BASE_IO_H

#include <filesystem>
#include <fstream>
#include <string>
#include "../utils.h"

class Reader {
    std::filesystem::path filepath;

public:

    Reader() = default;
    Reader(std::string filepath);
    virtual ~Reader() = default;
    std::string read(const std::string& key = "");
    virtual std::string decode(std::string encoded, const std::string& key) = 0;
};

class Writer {
    std::filesystem::path filepath;

public:
    Writer() = default;
    Writer(std::string filepath);
    virtual ~Writer() = default;
    void write(const std::string& content, const std::string& key = "");
    virtual std::string encode(std::string raw, const std::string& key) = 0;
};

#endif //MATHESISDOC_BASE_IO_H
