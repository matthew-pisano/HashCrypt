//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_ENCODINGS_H
#define MATHESISDOC_ENCODINGS_H

#include <string>
#include "../utils.h"

using namespace utils;

struct Encoding {
    virtual string name() = 0;
    virtual string ext() = 0;

    virtual string decode(string encoded, const string& key) = 0;
    virtual string encode(string raw, const string& key) = 0;
};

struct PlainEncoding : public Encoding{

    string name() override;
    string ext() override;

    string decode(string encoded, const string& key) override;
    string encode(string raw, const string& key) override;
};

struct ShiftAllEncoding : public Encoding{

    string name() override;
    string ext() override;

    string decode(string encoded, const string& key) override;
    string encode(string raw, const string& key) override;
};

struct ShiftCharEncoding : public Encoding{

    string name() override;
    string ext() override;

    string decode(string encoded, const string& key) override;
    string encode(string raw, const string& key) override;
};

Encoding* encodingFromName(const string& name);

#endif //MATHESISDOC_ENCODINGS_H
