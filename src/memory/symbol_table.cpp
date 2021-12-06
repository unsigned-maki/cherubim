//
// Created by Niclas on 01.11.2021.
//

#include "symbol_table.h"

using namespace std;

namespace cherubim::memory
{

    /**
     * @brief looks up a given symbol name and writes an gives a pointer to it.
     * 
     * @param symbol pointer to a pointer to a CSymbol class, which the pointer to the found symbol will be written to.  
     * @param name symbol name to look up.
     * @return ESymbol type of the symbol that was read, returns SYM_NIL if it's an empty symbol or no symbol was found. 
     */
    
    ESymbol CSymbolTable::read(CSymbol **symbol, string name)
    {
        map<string, CSymbol *>::iterator lookup;

        lookup = find(name);

        if (lookup != end())
        {
            *symbol = lookup->second;
            return lookup->second->m_type;
        }

        *symbol = nullptr;

        return SYM_NIL;
    }

    bool CSymbolTable::write(CSymbol *symbol, string name)
    {
        erase(name);
        return emplace(name, symbol).second;
    }

}
