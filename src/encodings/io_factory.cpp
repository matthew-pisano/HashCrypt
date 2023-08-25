//
// Created by matthew on 8/20/23.
//

#include "io_factory.h"
#include "encoded_io.h"


Reader* IOFactory::reader(std::string encodingName, std::string filename) {
    if(encodingName == PlainEncoding().name())
        return new PlainReader(filename);
    else if(encodingName == ShiftAllEncoding().name())
        return new ShiftAllReader(filename);
    else if(encodingName == ShiftCharEncoding().name())
        return new ShiftCharReader(filename);
    throw std::runtime_error("Encoding "+encodingName+" not found!");
}

Writer* IOFactory::writer(std::string encodingName, std::string filename) {
    if(encodingName == PlainEncoding().name())
        return new PlainWriter(filename);
    else if(encodingName == ShiftAllEncoding().name())
        return new ShiftAllWriter(filename);
    else if(encodingName == ShiftCharEncoding().name())
        return new ShiftCharWriter(filename);
    throw std::runtime_error("Encoding "+encodingName+" not found!");
}

std::string IOFactory::encode(std::string encodingName, const std::string& raw, const std::string& key) {
    return writer(encodingName)->encode(raw, key);
}

std::string IOFactory::decode(std::string encodingName, const std::string& encoded, const std::string& key) {
    return reader(encodingName)->decode(encoded, key);
}

