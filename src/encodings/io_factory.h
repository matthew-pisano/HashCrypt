//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_IO_FACTORY_H
#define MATHESISDOC_IO_FACTORY_H

#include <string>
#include "base_io.h"
#include "encodings.h"

class IOFactory {

public:
    Reader* reader(std::string encodingName, std::string filename = "");
    Writer* writer(std::string encodingName, std::string filename = "");

    std::string encode(std::string encodingName, const std::string& raw, const std::string& key = "");
    std::string decode(std::string encodingName, const std::string& encoded, const std::string& key = "");
};

#endif //MATHESISDOC_IO_FACTORY_H
