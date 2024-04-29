//
// Created by matthew on 8/20/23.
//

#ifndef HCRYPT_BASE_IO_H
#define HCRYPT_BASE_IO_H

#include <filesystem>
#include <fstream>
#include <string>
#include "../utils.h"


using namespace utils;


/**
 * An abstract file reader for decoding and reading in a file
 */
class Reader {
    std::filesystem::path filepath;

public:

    Reader() = default;

    Reader(string filepath);

    virtual ~Reader() = default;

    /**
     * Reads in the object's filepath while decoding with the given key
     * @param key The key to encode with
     * @return The decoded file contents
     */
    string read(const string& key = "");

    /**
     * Decodes the given string using the given key
     * @param encoded The original, encoded string
     * @param key The key to decode with
     * @return The decoded string
     */
    virtual string decode(string encoded, const string& key) = 0;
};


/**
 * An abstract file writer for encoding and writing to a file
 */
class Writer {
    std::filesystem::path filepath;

public:
    Writer() = default;

    Writer(string filepath);

    virtual ~Writer() = default;

    /**
     * Writes to the object's filepath while encoding with the given key
     * @param key The key to encode with
     */
    void write(const string& content, const string& key = "");

    /**
     * Encodes the given string using the given key
     * @param raw The original, raw string
     * @param key The key to encode with
     * @return The encoded string
     */
    virtual string encode(string raw, const string& key) = 0;
};


#endif //HCRYPT_BASE_IO_H
