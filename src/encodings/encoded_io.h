//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_ENCODED_IO_H
#define MATHESISDOC_ENCODED_IO_H

#include <filesystem>
#include "base_io.h"

class PlainReader : public Reader{
public:
    PlainReader(std::string filepath);
    std::string decode(std::string encoded, const std::string& key) override;
};

class PlainWriter : public Writer{
public:
    PlainWriter(std::string filepath);
    std::string encode(std::string raw, const std::string& key) override;
};

class KeyReader : public Reader{
public:
    KeyReader(std::string filepath);
    std::string decode(std::string encoded, const std::string& key) override;
};

class KeyWriter : public Writer{
public:
    KeyWriter(std::string filepath);
    std::string encode(std::string raw, const std::string& key) override;
};

#endif //MATHESISDOC_ENCODED_IO_H
