//
// Created by Niclas on 01.11.2021.
//

#include "symbol_table.hpp"

using namespace std;

namespace cherubim
{
    namespace memory
    {

        /**
         * @brief looks up a given symbol name and writes an gives a pointer to it.
         * 
         * @param symbol pointer to a pointer to a CSymbol class instance, which the pointer to the found symbol will be written to.  
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

        /**
         * @brief writes a given pointer to a CSymbol class instance to the symbol table using the given symbol name. 
         * 
         * @param symbol pointer to a CSymbol class instance, which will be written to the symbol table
         * @param name symbol name to write to.
         * @return true if the write operation was successful. 
         * @return false if the write operation has failed.
         */

        bool CSymbolTable::write(CSymbol *symbol, string name)
        {
            erase(name);
            return emplace(name, symbol).second;
        }

    }
}
