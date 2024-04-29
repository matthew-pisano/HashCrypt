#include <iostream>

#include "CLI11/CLI11.hpp"
#include "encodings/encoded_io.h"
#include "encodings/encodings.h"
#include "encodings/io_factory.h"


using namespace utils;


/**
 * The functionality for the encode command.  Encodes the given file with the given arguments and saves it
 * @param inFile The path to the input file
 * @param outFile The path to the output file
 * @param encoding The encoding to use
 * @param key The key to use in the encoding
 * @return The exit code
 */
int encodeCommand(const string& inFile, string outFile, const string& encoding, const string& key = "") {
    IOFactory factory = IOFactory();

    if (outFile.empty()) {
        outFile = std::filesystem::path(inFile).string();
        string encExtension = encodingFromName(encoding)->ext();
        if (!encExtension.empty()) outFile += "." + encodingFromName(encoding)->ext();
    }

    Reader* reader = factory.reader(PlainEncoding().name(), inFile);
    Writer* writer = factory.writer(encoding, outFile);

    writer->write(reader->read(), key);

    delete reader;
    delete writer;

    return 0;
}

/**
 * The functionality for the decode command.  Decoded the given file with the given arguments and saves it
 * @param inFile The path to the input file
 * @param outFile The path to the output file
 * @param encoding The encoding to use
 * @param key The key to use in the encoding
 * @return The exit code
 */
int decodeCommand(const string& inFile, string outFile, const string& encoding, const string& key = "") {
    IOFactory factory = IOFactory();

    if (outFile.empty()) {
        outFile = std::filesystem::path(inFile).string();

        string encExtension = encodingFromName(encoding)->ext();
        if (!encExtension.empty() && outFile.ends_with(encExtension))
            outFile.substr(0, outFile.length() - encExtension.length() - 1);
    }

    Reader* reader = factory.reader(encoding, inFile);
    Writer* writer = factory.writer(PlainEncoding().name(), outFile);

    writer->write(reader->read(key));

    delete reader;
    delete writer;

    return 0;
}

int main(int argc, char** argv) {

    CLI::App app{"Hash-Based document encoder-decoder", "hcrypt"};
    app.require_subcommand(1);

    string inFile;
    string outFile;
    string encoding = "shiftchar";
    string key;

    app.add_option("-o,--out-file", outFile, "The file to output the encoded or decoded text to");
    app.add_option("-e,--encoding", encoding, "The encoding to use during execution")->default_val("shiftchar");
    app.add_option("-k,--key", key, "The key for the encoding or decoding, if applicable")->default_val("");

    CLI::App* encode = app.add_subcommand("encode", "Encodes a file");
    encode->fallthrough();
    encode->add_option("file", inFile, "The input file to encode")->required();

    CLI::App* decode = app.add_subcommand("decode", "Decodes a file");
    decode->fallthrough();
    decode->add_option("file", inFile, "The input file to decode")->required();

    try {
        app.parse(argc, argv);

        if (encode->parsed()) encodeCommand(inFile, outFile, encoding, key);
        else decodeCommand(inFile, outFile, encoding, key);
    } catch (const CLI::ParseError& e) { return app.exit(e); }
    catch (const runtime_error& e) {
        const CLI::Error cli("Runtime Error", e.what());
        return app.exit(cli);
    }

    return 0;
}
