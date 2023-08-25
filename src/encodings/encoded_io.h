//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_ENCODED_IO_H
#define MATHESISDOC_ENCODED_IO_H

#include <filesystem>
#include "base_io.h"


using namespace utils;


/**
 * A reader for plaintext
 */
class PlainReader : public Reader {
public:
    PlainReader(string filepath);

    string decode(string encoded, const string &key) override;
};


/**
 * A writer for plaintext
 */
class PlainWriter : public Writer {
public:
    PlainWriter(string filepath);

    string encode(string raw, const string &key) override;
};


/**
 * A reader for shiftall encoded files
 */
class ShiftAllReader : public Reader {
public:
    ShiftAllReader(string filepath);

    string decode(string encoded, const string &key) override;
};


/**
 * A writer for shiftall encoded files
 */
class ShiftAllWriter : public Writer {
public:
    ShiftAllWriter(string filepath);

    string encode(string raw, const string &key) override;
};


/**
 * A reader for shiftchar encoded files
 */
class ShiftCharReader : public Reader {
public:
    ShiftCharReader(string filepath);

    string decode(string encoded, const string &key) override;
};


/**
 * A writer for shiftchar encoded files
 */
class ShiftCharWriter : public Writer {
public:
    ShiftCharWriter(string filepath);

    string encode(string raw, const string &key) override;
};


#endif //MATHESISDOC_ENCODED_IO_H
