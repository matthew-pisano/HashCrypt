//
// Created by matthew on 8/20/23.
//

#include <filesystem>
#include "utils.h"

using namespace utils;

string normalizePath(const string &messyPath) {
    std::filesystem::path path(messyPath);
    std::filesystem::path canonicalPath = std::filesystem::weakly_canonical(path);
    string npath = canonicalPath.make_preferred().string();
    return npath;
}