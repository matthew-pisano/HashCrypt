//
// Created by matthew on 8/20/23.
//

#include "plain_io.h"
#include "encodings.h"

PlainReader::PlainReader(std::string filepath) : Reader(filepath) {}
std::string PlainReader::decode(std::string encoded) { return PlainEncoding().decode(encoded); }

PlainWriter::PlainWriter(std::string filepath) : Writer(filepath) {}
std::string PlainWriter::encode(std::string raw) { return PlainEncoding().encode(raw); }
