//
// Created by Niclas on 01.12.2021.
//

#include "chain.h"

namespace cherubim::parser
{

    CChain::CChain(CSymbolTable *symbolTable)
    {
        m_memory = symbolTable;
    }

}
