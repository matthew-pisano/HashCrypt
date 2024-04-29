cmake_minimum_required(VERSION 3.26)
project(hcrypt)

set(CMAKE_CXX_STANDARD 23)

include_directories(include lib)

add_executable(hcrypt src/main.cpp
        src/encodings/encoded_io.cpp
        include/encodings/base_io.h
        src/utils.cpp
        include/utils.h
        lib/CLI11/CLI11.hpp
        src/encodings/io_factory.cpp
        include/encodings/io_factory.h
        src/encodings/encodings.cpp
        include/encodings/encodings.h
        include/encodings/encoded_io.h
        src/encodings/base_io.cpp)
