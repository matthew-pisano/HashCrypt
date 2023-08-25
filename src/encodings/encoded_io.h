//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_ENCODED_IO_H
#define MATHESISDOC_ENCODED_IO_H

#include <filesystem>
#include "base_io.h"

using namespace utils;

class PlainReader : public Reader{
public:
    PlainReader(string filepath);
    string decode(string encoded, const string& key) override;
};

class PlainWriter : public Writer{
public:
    PlainWriter(string filepath);
    string encode(string raw, const string& key) override;
};

class ShiftAllReader : public Reader{
public:
    ShiftAllReader(string filepath);
    string decode(string encoded, const string& key) override;
};

class ShiftAllWriter : public Writer{
public:
    ShiftAllWriter(string filepath);
    string encode(string raw, const string& key) override;
};

class ShiftCharReader : public Reader{
public:
    ShiftCharReader(string filepath);
    string decode(string encoded, const string& key) override;
};

class ShiftCharWriter : public Writer{
public:
    ShiftCharWriter(string filepath);
    string encode(string raw, const string& key) override;
};

#endif //MATHESISDOC_ENCODED_IO_H
