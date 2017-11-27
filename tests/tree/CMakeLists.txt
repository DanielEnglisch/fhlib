cmake_minimum_required(VERSION 3.8)
project(tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp tree.cpp tree.h test.cpp test.h)
add_executable(tree ${SOURCE_FILES})