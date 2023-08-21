//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_PLAIN_IO_H
#define MATHESISDOC_PLAIN_IO_H

#include <filesystem>
#include "base_io.h"

class PlainReader : public Reader{
public:
    PlainReader(std::string filepath);
    std::string decode(std::string encoded) override;
};

class PlainWriter : public Writer{
public:
    PlainWriter(std::string filepath);
    std::string encode(std::string raw) override;
};

#endif //MATHESISDOC_PLAIN_IO_H
