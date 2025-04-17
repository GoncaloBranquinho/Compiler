cmake_minimum_required(VERSION 3.10)

project(Compiler)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(compiler src/main.cpp src/lexer/lexer.cpp)


