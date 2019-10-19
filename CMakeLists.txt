cmake_minimum_required(VERSION 3.15)
project(ascii_trigram_scorer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ascii_trigram_scorer main.cpp countLetters.cpp countLetters.hpp outputLetters.cpp outputLetters.hpp)