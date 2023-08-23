cmake_minimum_required(VERSION 3.26)
project(mathesisDoc)

set(CMAKE_CXX_STANDARD 23)

add_executable(mathesisDoc main.cpp
        src/encodings/encoded_io.cpp
        src/encodings/base_io.h
        src/utils.cpp
        src/utils.h
        lib/CLI11/CLI11.hpp
        src/encodings/io_factory.cpp
        src/encodings/io_factory.h
        src/encodings/encodings.cpp
        src/encodings/encodings.h
        src/encodings/encoded_io.h
        src/encodings/base_io.cpp)
