//
// Created by matthew on 8/20/23.
//

#include <cstring>
#include "encoded_io.h"
#include "encodings.h"


using namespace utils;

PlainReader::PlainReader(string filepath) : Reader(filepath) {}

string PlainReader::decode(string encoded, const string &key) { return PlainEncoding().decode(encoded, key); }


PlainWriter::PlainWriter(string filepath) : Writer(filepath) {}

string PlainWriter::encode(string raw, const string &key) { return PlainEncoding().encode(raw, key); }


ShiftAllReader::ShiftAllReader(string filepath) : Reader(filepath) {}

string ShiftAllReader::decode(string encoded, const string &key) { return ShiftAllEncoding().decode(encoded, key); }


ShiftAllWriter::ShiftAllWriter(string filepath) : Writer(filepath) {}

string ShiftAllWriter::encode(string raw, const string &key) { return ShiftAllEncoding().encode(raw, key); }


ShiftCharReader::ShiftCharReader(string filepath) : Reader(filepath) {}

string ShiftCharReader::decode(string encoded, const string &key) { return ShiftCharEncoding().decode(encoded, key); }


ShiftCharWriter::ShiftCharWriter(string filepath) : Writer(filepath) {}

string ShiftCharWriter::encode(string raw, const string &key) { return ShiftCharEncoding().encode(raw, key); }
