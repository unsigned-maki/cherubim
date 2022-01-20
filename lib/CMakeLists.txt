cmake_minimum_required(VERSION 3.10)

project(Cherubim VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_library(cherubim STATIC parser/block.hpp parser/error.hpp parser/chain.hpp parser/chain.cpp parser/parser.hpp parser/parser.cpp memory/symbol_table.hpp memory/symbol.hpp memory/symbol_table.cpp memory/symbol.cpp lexer/token.cpp lexer/token.hpp lexer/lexer.cpp lexer/lexer.hpp)
