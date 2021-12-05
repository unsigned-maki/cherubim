//
// Created by Niclas on 01.12.2021.
//

#ifndef POS_CHAIN_H
#define POS_CHAIN_H
#include "../memory/symbol_table.h"

namespace cherubim::parser
{

class CChain {
    public:
        CSymbolTable *m_memory;
        CChain(CSymbolTable *symbolTable);
};

}

#endif //POS_CHAIN_H
