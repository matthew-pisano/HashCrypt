//
// Created by matthew on 8/20/23.
//

#include "encodings/base_io.h"


using namespace utils;

Reader::Reader(string filepath) {
    if (!filepath.empty() && filepath.at(0) == '/')
        this->filepath = std::filesystem::path(normalizePath(filepath));
    else
        this->filepath = std::filesystem::current_path() / std::filesystem::path(normalizePath(filepath));

    std::ifstream f(this->filepath.string().c_str());
    if (!f.good()) throw runtime_error("File at " + this->filepath.string() + " not found");
}

string Reader::read(const string& key) {
    string contents;
    std::ifstream file(filepath.string());

    char curr = file.get();
    while (!file.eof()) {
        contents += curr;
        curr = file.get();
    }
    file.close();
    return decode(contents, key);
}

Writer::Writer(string filepath) {
    if (!filepath.empty() && filepath.at(0) == '/')
        this->filepath = std::filesystem::path(normalizePath(filepath));
    else
        this->filepath = std::filesystem::current_path() / std::filesystem::path(normalizePath(filepath));
}

void Writer::write(const string& content, const string& key) {
    std::ofstream file(filepath.string());
    file << encode(content, key);
    file.close();
}
