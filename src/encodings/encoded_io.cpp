//
// Created by matthew on 8/20/23.
//

#include <cstring>
#include "encoded_io.h"
#include "encodings.h"

PlainReader::PlainReader(std::string filepath) : Reader(filepath) {}
std::string PlainReader::decode(std::string encoded, const std::string& key) { return PlainEncoding().decode(encoded, key); }

PlainWriter::PlainWriter(std::string filepath) : Writer(filepath) {}
std::string PlainWriter::encode(std::string raw, const std::string& key) { return PlainEncoding().encode(raw, key); }

KeyReader::KeyReader(std::string filepath) : Reader(filepath) {}
std::string KeyReader::decode(std::string encoded, const std::string& key) { return KeyEncoding().decode(encoded, key); }

KeyWriter::KeyWriter(std::string filepath) : Writer(filepath) {}
std::string KeyWriter::encode(std::string raw, const std::string& key) { return KeyEncoding().encode(raw, key); }
