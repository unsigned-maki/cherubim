//
// Created by Niclas on 01.11.2021.
//

#include "symbol.h"

namespace cherubim
{
    namespace memory
    {

        bool CSymbolLiteral::get()
        {
            return m_literal;
        }
        
        void CSymbolLiteral::set(bool literal)
        {
            m_literal = literal;
        }
        
    }
}
