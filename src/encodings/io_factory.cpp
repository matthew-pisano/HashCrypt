//
// Created by matthew on 8/20/23.
//

#include "io_factory.h"
#include "encoded_io.h"

using namespace utils;

Reader* IOFactory::reader(string encodingName, string filename) {
    if(encodingName == PlainEncoding().name())
        return new PlainReader(filename);
    else if(encodingName == ShiftAllEncoding().name())
        return new ShiftAllReader(filename);
    else if(encodingName == ShiftCharEncoding().name())
        return new ShiftCharReader(filename);
    throw runtime_error("Encoding "+encodingName+" not found!");
}

Writer* IOFactory::writer(string encodingName, string filename) {
    if(encodingName == PlainEncoding().name())
        return new PlainWriter(filename);
    else if(encodingName == ShiftAllEncoding().name())
        return new ShiftAllWriter(filename);
    else if(encodingName == ShiftCharEncoding().name())
        return new ShiftCharWriter(filename);
    throw runtime_error("Encoding "+encodingName+" not found!");
}

string IOFactory::encode(string encodingName, const string& raw, const string& key) {
    return writer(encodingName)->encode(raw, key);
}

string IOFactory::decode(string encodingName, const string& encoded, const string& key) {
    return reader(encodingName)->decode(encoded, key);
}

