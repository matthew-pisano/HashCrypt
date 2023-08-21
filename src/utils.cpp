//
// Created by matthew on 8/20/23.
//

#include <filesystem>
#include "utils.h"

std::string normalizePath(const std::string &messyPath) {
    std::filesystem::path path(messyPath);
    std::filesystem::path canonicalPath = std::filesystem::weakly_canonical(path);
    std::string npath = canonicalPath.make_preferred().string();
    return npath;
}