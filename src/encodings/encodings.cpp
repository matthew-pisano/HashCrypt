//
// Created by matthew on 8/20/23.
//


#include <stdexcept>
#include "encodings.h"
#include <unordered_map>

using namespace utils;

map<string, string> encodingMap = {
    { "plain", "" },
    { "shiftall", "akey" },
    { "shiftchar", "ckey" },
};


Encoding* encodingFromName(const string& name) {
    Encoding* encodings[] = {new PlainEncoding(), new ShiftAllEncoding(), new ShiftCharEncoding()};
    string availEncodings;

    for(Encoding* enc : encodings) {
        if (name == enc->name())
            return enc;
        availEncodings += enc->name()+", ";
    }

    throw runtime_error("Encoding '"+name+"' not found!  Available encodings are: "+availEncodings);
}


string PlainEncoding::name() { return "plain"; }
string PlainEncoding::ext() { return encodingMap.at("plain"); }
string PlainEncoding::decode(string encoded, const string& key) { return encoded; }
string PlainEncoding::encode(string raw, const string& key) { return raw; }

string ShiftAllEncoding::name() { return "shiftall"; }
string ShiftAllEncoding::ext() { return encodingMap.at("shiftall"); }
string ShiftAllEncoding::decode(string encoded, const string& key) {
    string decoded;
    int keyHash = abs(static_cast<int>(hash<string>{}(key)) % WCHAR_MAX);

    for (char i : encoded)
        decoded += wchar_t(i-keyHash > 0 ? i-keyHash : i-keyHash+WCHAR_MAX);
    return decoded;
}
string ShiftAllEncoding::encode(string raw, const string& key) {
    string encoded;
    int keyHash = abs(static_cast<int>(hash<string>{}(key)) % WCHAR_MAX);

    for (char i : raw)
        encoded += wchar_t(i+keyHash >= WCHAR_MAX ? i+keyHash : i+keyHash-WCHAR_MAX);
    return encoded;
}

string ShiftCharEncoding::name() { return "shiftchar"; }
string ShiftCharEncoding::ext() { return encodingMap.at("shiftchar"); }
string ShiftCharEncoding::decode(string encoded, const string &key) {
    string decoded;
    ShiftAllEncoding subEncoder = ShiftAllEncoding();

    for(int i=0; i<encoded.length(); i++)
        decoded += subEncoder.decode(encoded.substr(i, 1), key+to_string(i));

    return decoded;
}
string ShiftCharEncoding::encode(string raw, const string &key) {
    string encoded;
    ShiftAllEncoding subEncoder = ShiftAllEncoding();

    for(int i=0; i<raw.length(); i++)
        encoded += subEncoder.encode(raw.substr(i, 1), key+to_string(i));


    return encoded;
}
