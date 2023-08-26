# MathesisDoc

A simple document encoder in C++. Documents are encoded based off of hashing with several different algorithms.

## Usage

The `mathesisDoc` executable has two sub-commands, encode and decode. Each of these commands accepts an input file and options for a key and an output file.

## Shift Encoding

Documents encoded with the shift encoding have their characters shifted upward based off of the hash of the key given.

## Character Shift Encoding

Documents encoded in this manner have each of their characters shifted based off of the hash of the character index and the key. This ensures that the contents cannot be decoded by simply guessing the shift value.
