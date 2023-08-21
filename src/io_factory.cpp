//
// Created by matthew on 8/20/23.
//

#include "io_factory.h"
#include "plain_io.h"


Reader* IOFactory::reader(std::string encodingName, std::string filename) {
    if(encodingName == PlainEncoding().name())
        return new PlainReader(filename);
    throw std::runtime_error("Encoding "+encodingName+" not found!");
}

Writer* IOFactory::writer(std::string encodingName, std::string filename) {
    if(encodingName == PlainEncoding().name())
        return new PlainWriter(filename);
    throw std::runtime_error("Encoding "+encodingName+" not found!");
}

std::string IOFactory::encode(std::string encodingName, std::string raw) {
    return writer(encodingName)->encode(raw);
}

std::string IOFactory::decode(std::string encodingName, std::string encoded) {
    return reader(encodingName)->decode(encoded);
}

