cmake_minimum_required(VERSION 3.26)
project(mathesisDoc)

set(CMAKE_CXX_STANDARD 23)

add_executable(mathesisDoc main.cpp
        src/plain_io.cpp
        src/base_io.h
        src/utils.cpp
        src/utils.h
        lib/CLI11/CLI11.hpp
        src/io_factory.cpp
        src/io_factory.h
        src/encodings.cpp
        src/encodings.h
        src/plain_io.h
        src/base_io.cpp)
