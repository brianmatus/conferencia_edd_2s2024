cmake_minimum_required(VERSION 3.29)
project(blockchain)

set(CMAKE_CXX_STANDARD 20)

add_executable(blockchain main.cpp
        elements/Block.cpp
        elements/Block.hpp
        elements/Blockchain.cpp
        elements/Blockchain.hpp
        libs/sha256.cpp
        libs/sha256.hpp)
