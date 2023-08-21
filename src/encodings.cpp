//
// Created by matthew on 8/20/23.
//


#include <stdexcept>
#include "encodings.h"

std::string PlainEncoding::name() { return "plain_text"; }
std::string PlainEncoding::ext() { return "txt"; }
std::string PlainEncoding::decode(std::string raw) { return raw; }
std::string PlainEncoding::encode(std::string raw) { return raw; }

Encoding* encodingFromName(std::string name) {
    if(name == PlainEncoding().name())
        return new PlainEncoding();
    throw std::runtime_error("Encoding '"+name+"' not found!");
}
