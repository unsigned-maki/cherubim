//
// Created by Niclas on 01.11.2021.
//

#ifndef POS1_SYMBOL_TABLE_H
#define POS1_SYMBOL_TABLE_H
#include <map>
#include <string>
#include "symbol.hpp"

using namespace std;

namespace cherubim
{
    namespace memory
    {
        class CSymbolTable : public map<string, CSymbol *>
        {
            public:
                ESymbol read(CSymbol **symbol, string name);
                
                bool write(CSymbol *symbol, string name);
        };
    }
}

#endif //POS1_SYMBOL_TABLE_H
