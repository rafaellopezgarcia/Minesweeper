cmake_minimum_required(VERSION 3.8)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Minesweeper.h Cell.hpp Minesweeper.cpp Cell.cpp)
add_executable(Minesweeper ${SOURCE_FILES})