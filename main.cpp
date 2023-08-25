#include <iostream>
#include "src/encodings/encoded_io.h"
#include "src/encodings/encodings.h"
#include "lib/CLI11/CLI11.hpp"
#include "src/encodings/io_factory.h"

using namespace utils;

void testReadWrite() {
    PlainReader reader("../data/doc.txt");
    string content = reader.read();
    cout << content << endl;

    PlainWriter writer("../data/doc.txt");
    writer.write(content+"\n\nWow!");

    content = reader.read();
    cout << content << endl;
}

int encodeCommand(const string& inFile, string outFile, const string& encoding, const string& key = "") {
    IOFactory factory = IOFactory();

    if(outFile.empty()) {
        outFile = std::filesystem::path(inFile).string();
        string encExtension = encodingFromName(encoding)->ext();
        if(encExtension.length() > 0) outFile += "." + encodingFromName(encoding)->ext();
    }

    Reader* reader = factory.reader(PlainEncoding().name(), inFile);
    Writer* writer = factory.writer(encoding, outFile);

    writer->write(reader->read(), key);

    delete reader;
    delete writer;

    return 0;
}

int decodeCommand(const string& inFile, string outFile, const string& encoding, const string& key = "") {
    IOFactory factory = IOFactory();

    if(outFile.empty()) {
        outFile = std::filesystem::path(inFile).string();

        string encExtension = encodingFromName(encoding)->ext();
        if(encExtension.length() > 0 && outFile.ends_with(encExtension))
            outFile.substr(0, outFile.length()-encExtension.length()-1);
    }

    Reader* reader = factory.reader(encoding, inFile);
    Writer* writer = factory.writer(PlainEncoding().name(), outFile);

    writer->write(reader->read(key));

    delete reader;
    delete writer;

    return 0;
}

int main(int argc, char** argv) {

    CLI::App app{"Mathesis document encoder-decoder", "MathesisDoc"};

    string inFile;
    string outFile;
    string encoding = "shiftchar";
    string key;

    CLI::App* encode = app.add_subcommand("encode", "Encodes a file");
    encode->add_option("-f,--file,file", inFile, "The file to encode")->required();
    encode->add_option("-o,--out-file", outFile, "The file to output the encoding to");
    encode->add_option("-e,--encoding", encoding, "The encoding to use during execution");
    encode->add_option("-k,--key", key, "The key for the encoding, if applicable");

    CLI::App* decode = app.add_subcommand("decode", "Decodes a file");
    decode->add_option("-f,--file,file", inFile, "The file to decode")->required();
    decode->add_option("-o,--out-file", outFile, "The file to output the decoding to");
    decode->add_option("-e,--encoding", encoding, "The encoding to use during execution");
    decode->add_option("-k,--key", key, "The key for the decoding, if applicable");

    try {
        app.parse(argc, argv);

        if(encode->parsed()) return encodeCommand(inFile, outFile, encoding, key);
        else if(decode->parsed()) return decodeCommand(inFile, outFile, encoding, key);

        cout << app.help() << endl;
    } catch (const CLI::ParseError &e) { return app.exit(e); }
    catch (const runtime_error &e) {
        const CLI::Error cli("Runtime Error", e.what());
        return app.exit(cli);
    }

    return 0;
}
