//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_BASE_IO_H
#define MATHESISDOC_BASE_IO_H

#include <filesystem>
#include <fstream>
#include <string>
#include "../utils.h"

using namespace utils;

class Reader {
    std::filesystem::path filepath;

public:

    Reader() = default;
    Reader(string filepath);
    virtual ~Reader() = default;
    string read(const string& key = "");
    virtual string decode(string encoded, const string& key) = 0;
};

class Writer {
    std::filesystem::path filepath;

public:
    Writer() = default;
    Writer(string filepath);
    virtual ~Writer() = default;
    void write(const string& content, const string& key = "");
    virtual string encode(string raw, const string& key) = 0;
};

#endif //MATHESISDOC_BASE_IO_H
