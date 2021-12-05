//
// Created by Niclas on 01.11.2021.
//

#ifndef POS1_SYMBOL_TABLE_H
#define POS1_SYMBOL_TABLE_H
#include <map>
#include <string>
#include "symbol.h"

using namespace std;

namespace cherubim::memory
{

    class CSymbolTable : public map<string, CSymbol *>
    {
        public:
            ESymbol read(CSymbol **symbol, string name);
            void set();
    };

}

#endif //POS1_SYMBOL_TABLE_H
