//
// Created by Niclas on 19.12.2021.
//

#ifndef POS_CHAIN_H
#define POS_CHAIN_H
#include <vector>
#include <map>
#include "block.hpp"
#include "error.hpp"
#include "../lexer/token.hpp"
#include "../memory/symbol_table.hpp"

using namespace std;

namespace cherubim
{
    namespace parser
    {
        class CChain : public vector<SBlock> 
        {
            private:
                bool m_eval;

                memory::CSymbolTable* m_symbolTable;

            public:
                CChain(vector<lexer::SToken> tokens, unsigned long from, unsigned long to, map<unsigned long, unsigned long> *braceTable, memory::CSymbolTable *symbolTable, SError *error);

                bool evaluate();
    };
    }
}

#endif //POS_CHAIN_H
