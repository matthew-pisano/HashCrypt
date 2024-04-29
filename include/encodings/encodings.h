//
// Created by matthew on 8/20/23.
//

#ifndef HCRYPT_ENCODINGS_H
#define HCRYPT_ENCODINGS_H

#include <string>
#include "../utils.h"


using namespace utils;


/**
 * An abstract encoding specification
 */
struct Encoding {

    /**
     * The name identifier of the encoding
     * @return The encoding name
     */
    virtual string name() = 0;

    /**
     * The extension associated with the encoding
     * @return The encoding extension
     */
    virtual string ext() = 0;

    /**
     * Decodes a string using the given key and returns the result
     * @param encoded The original, encoded string
     * @param key The key to decode with
     * @return The decoded string
     */
    virtual string decode(string encoded, const string& key) = 0;

    /**
     * Encodes a string using the given key and returns the result
     * @param raw The original string
     * @param key The key to encode with
     * @return The encoded string
     */
    virtual string encode(string raw, const string& key) = 0;
};


/**
 * A plaintext encoding
 */
struct PlainEncoding : public Encoding {

    string name() override;

    string ext() override;

    string decode(string encoded, const string& key) override;

    string encode(string raw, const string& key) override;
};


/**
 * A shiftall encoding.  Encoded text is shifted up in characters uniformly based off of the key hash
 */
struct ShiftAllEncoding : public Encoding {

    string name() override;

    string ext() override;

    string decode(string encoded, const string& key) override;

    string encode(string raw, const string& key) override;
};


/**
 * A shiftchar encoding.  Encoded text is shifted up character by character based off of the hash of the key and the character index
 */
struct ShiftCharEncoding : public Encoding {

    string name() override;

    string ext() override;

    string decode(string encoded, const string& key) override;

    string encode(string raw, const string& key) override;
};


/**
 * Gets a pointer to an encoding object based off of the name of the encoding
 * @param name The name of the encoding to get
 * @return A pointer to an encoding instance
 */
Encoding* encodingFromName(const string& name);

#endif //HCRYPT_ENCODINGS_H
