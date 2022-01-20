//
// Created by Niclas on 19.12.2021.
//

#ifndef POS_PARSER_H
#define POS_PARSER_H
#include <list>
#include <vector>
#include <map>
#include "chain.hpp"
#include "../lexer/token.hpp"
#include "../memory/symbol_table.hpp"

namespace cherubim
{
    namespace parser
    {

        size_t countTokens(vector<cherubim::lexer::SToken> tokens, EToken type);

        bool resolveBraces(list< pair <int, EToken> > *braces, map<int,int> *resolvedBraces, size_t depthLimit);

        CChain parse(vector<lexer::SToken> tokens, memory::CSymbolTable *symbolTable);

    }
}


#endif //POS_PARSER_H
