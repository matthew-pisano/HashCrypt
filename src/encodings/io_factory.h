//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_IO_FACTORY_H
#define MATHESISDOC_IO_FACTORY_H

#include <string>
#include "base_io.h"
#include "encodings.h"

using namespace utils;

class IOFactory {

public:
    Reader* reader(string encodingName, string filename = "");
    Writer* writer(string encodingName, string filename = "");

    string encode(string encodingName, const string& raw, const string& key = "");
    string decode(string encodingName, const string& encoded, const string& key = "");
};

#endif //MATHESISDOC_IO_FACTORY_H
