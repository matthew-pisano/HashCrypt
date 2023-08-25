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

ShiftAllReader::ShiftAllReader(std::string filepath) : Reader(filepath) {}
std::string ShiftAllReader::decode(std::string encoded, const std::string& key) { return ShiftAllEncoding().decode(encoded, key); }

ShiftAllWriter::ShiftAllWriter(std::string filepath) : Writer(filepath) {}
std::string ShiftAllWriter::encode(std::string raw, const std::string& key) { return ShiftAllEncoding().encode(raw, key); }

ShiftCharReader::ShiftCharReader(std::string filepath) : Reader(filepath) {}
std::string ShiftCharReader::decode(std::string encoded, const std::string &key) { return ShiftCharEncoding().decode(encoded, key); }

ShiftCharWriter::ShiftCharWriter(std::string filepath) : Writer(filepath) {}
std::string ShiftCharWriter::encode(std::string raw, const std::string &key) { return ShiftCharEncoding().encode(raw, key); }
