//
// Created by matthew on 8/20/23.
//

#ifndef MATHESISDOC_UTILS_H
#define MATHESISDOC_UTILS_H

#include <string>
#include <iostream>
#include <vector>
#include <map>


namespace utils {
    using std::string, std::to_string, std::cout, std::endl, std::vector, std::map, std::runtime_error, std::hash;
}

/**
 * Normalizes any path to be an absolute path relative to root
 * @param messyPath The input path
 * @return The normalized path
 */
std::string normalizePath(const std::string &messyPath);

#endif //MATHESISDOC_UTILS_H
