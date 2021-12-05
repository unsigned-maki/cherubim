//
// Created by Niclas on 01.11.2021.
//

#ifndef POS1_SYMBOL_H
#define POS1_SYMBOL_H
#include <string>
#include <iostream>

using namespace std;

enum ESymbol
{
    SYM_FUNCTION,
    SYM_LITERAL,
    SYM_NIL
};

namespace cherubim::memory
{

    class CSymbol
    {
        public:            
            ESymbol m_type = SYM_NIL;

    };

    class CSymbolLiteral : public CSymbol
    {
        public:
            CSymbolLiteral(bool literal)
            {
                this->m_literal = literal;
                this->m_type = SYM_LITERAL;
            };
            
            bool m_literal;

            bool get();

            void set(bool literal);
    };

    class CSymbolFunction : public CSymbol
    {
        private:            
        public:
            CSymbolFunction();
    };

}

#endif //POS1_SYMBOL_H
