//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_ENCODINGS_H
#define MATHESISDOC_ENCODINGS_H

#include <string>

struct Encoding {
    virtual std::string name() = 0;
    virtual std::string ext() = 0;

    virtual std::string decode(std::string raw) = 0;
    virtual std::string encode(std::string raw) = 0;
};

struct PlainEncoding : public Encoding{

    std::string name() override;
    std::string ext() override;

    std::string decode(std::string raw) override;
    std::string encode(std::string raw) override;
};

Encoding* encodingFromName(std::string name);

#endif //MATHESISDOC_ENCODINGS_H
