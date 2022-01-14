cmake_minimum_required(VERSION 3.10)

project(Cherubim VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_library(cherubim STATIC memory/symbol_table.h memory/symbol.h memory/symbol_table.cpp memory/symbol.cpp lexer/token.cpp lexer/token.h lexer/lexer.cpp lexer/lexer.h)
