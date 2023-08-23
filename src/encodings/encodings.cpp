//
// Created by matthew on 8/20/23.
//


#include <stdexcept>
#include <map>
#include "encodings.h"
#include <unordered_map>
#include <climits>

// TODO: add file header for encoding instead of file extension
std::map<std::string, std::string> encodingMap = {
    { "plain", "txt" },
    { "key", "matkey" },
};

std::string PlainEncoding::name() { return "plain"; }
std::string PlainEncoding::ext() { return encodingMap.at("plain"); }
std::string PlainEncoding::decode(std::string encoded, const std::string& key) { return encoded; }
std::string PlainEncoding::encode(std::string raw, const std::string& key) { return raw; }

std::string KeyEncoding::name() { return "key"; }
std::string KeyEncoding::ext() { return encodingMap.at("key"); }
std::string KeyEncoding::decode(std::string encoded, const std::string& key) {
    std::string decoded;
    int keyHash = abs(static_cast<int>(std::hash<std::string>{}(key)) % WCHAR_MAX);

    for (char i : encoded)
        decoded += wchar_t(i-keyHash > 0 ? i-keyHash : i-keyHash+WCHAR_MAX);
    return decoded;
}
std::string KeyEncoding::encode(std::string raw, const std::string& key) {
    std::string encoded;
    int keyHash = abs(static_cast<int>(std::hash<std::string>{}(key)) % WCHAR_MAX);

    for (char i : raw)
        encoded += wchar_t(i+keyHash >= WCHAR_MAX ? i+keyHash : i+keyHash-WCHAR_MAX);
    return encoded;
}


Encoding* encodingFromName(std::string name) {
    if(name == PlainEncoding().name())
        return new PlainEncoding();
    else if(name == KeyEncoding().name())
        return new KeyEncoding();

    std::string availEncodings;
    for ( const auto &myPair : encodingMap ) {
        availEncodings += myPair.first+", ";
    }
    throw std::runtime_error("Encoding '"+name+"' not found!  Available encodings are: "+availEncodings);
}
