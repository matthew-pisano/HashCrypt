//
// Created by matthew on 8/20/23.
//

#include "base_io.h"

Reader::Reader(std::string filepath) {
    if(filepath.length() > 0 && filepath.at(0) == '/')
        this->filepath = std::filesystem::path(normalizePath(filepath));
    else
        this->filepath = std::filesystem::current_path() / std::filesystem::path(normalizePath(filepath));

    std::ifstream f(this->filepath.string().c_str());
    if(!f.good()) throw std::runtime_error("File at "+this->filepath.string()+" not found");
}

std::string Reader::read() {
    std::string contents;
    std::ifstream file(filepath.string());

    char curr = file.get();
    while (!file.eof()){
        contents += curr;
        curr = file.get();
    }
    file.close();
    return decode(contents);
}

Writer::Writer(std::string filepath) {
    if(filepath.length() > 0 && filepath.at(0) == '/')
        this->filepath = std::filesystem::path(normalizePath(filepath));
    else
        this->filepath = std::filesystem::current_path() / std::filesystem::path(normalizePath(filepath));
}

void Writer::write(const std::string& content) {
    std::ofstream file(filepath.string());
    file << encode(content);
    file.close();
}
