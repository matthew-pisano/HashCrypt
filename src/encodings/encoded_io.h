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

class ShiftAllReader : public Reader{
public:
    ShiftAllReader(std::string filepath);
    std::string decode(std::string encoded, const std::string& key) override;
};

class ShiftAllWriter : public Writer{
public:
    ShiftAllWriter(std::string filepath);
    std::string encode(std::string raw, const std::string& key) override;
};

class ShiftCharReader : public Reader{
public:
    ShiftCharReader(std::string filepath);
    std::string decode(std::string encoded, const std::string& key) override;
};

class ShiftCharWriter : public Writer{
public:
    ShiftCharWriter(std::string filepath);
    std::string encode(std::string raw, const std::string& key) override;
};

#endif //MATHESISDOC_ENCODED_IO_H
