//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_IO_FACTORY_H
#define MATHESISDOC_IO_FACTORY_H

#include <string>
#include "base_io.h"
#include "encodings.h"


using namespace utils;


/**
 * Factory class for creating readers and writers based off their encoding name
 */
class IOFactory {

public:

    /**
     * Instantiates a reference to an appropriate reader object
     * @param encodingName The name of the encoding to use
     * @param filename The file to target
     * @return A pointer to an instance of the reader
     */
    Reader *reader(const string &encodingName, const string &filename = "");

    /**
     * Instantiates a reference to an appropriate writer object
     * @param encodingName The name of the encoding to use
     * @param filename The file to target
     * @return A pointer to an instance of the writer
     */
    Writer *writer(const string &encodingName, const string &filename = "");

    /**
     * Encodes a string by creating an instance of an appropriate writer and calling its encode function
     * @param encodingName The name of the encoding to use
     * @param raw The raw string to encode
     * @param key The key to use while encoding
     * @return The encoded string
     */
    string encode(const string &encodingName, const string &raw, const string &key = "");

    /**
     * Decodes a string by creating an instance of an appropriate reader and calling its decode function
     * @param encodingName The name of the encoding to use
     * @param encoded The encoded string to encode
     * @param key The key to use while decoding
     * @return The decoded string
     */
    string decode(string &encodingName, const string &encoded, const string &key = "");
};


#endif //MATHESISDOC_IO_FACTORY_H
