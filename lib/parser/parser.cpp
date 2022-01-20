//
// Created by Niclas on 19.12.2021.
//

#include "parser.hpp"
#include <iostream>

using namespace std;

namespace cherubim
{
    namespace parser
    {

        size_t countTokens(vector<lexer::SToken> tokens, EToken type)
        {
            size_t count;
            count = 0;
            
            for (vector<lexer::SToken>::iterator i = tokens.begin(); i != tokens.end(); i++)
            {
                if (i->m_type == type)
                    count++;
            }
            
            return count;
        }

        bool resolveBraces(list< pair <unsigned long, EToken> > *braces, map<unsigned long, unsigned long> *braceTable, size_t depthLimit)
        {
            for (list< pair <unsigned long, EToken> >::iterator i = braces->begin(); i != braces->end(); i++)
            {
                if (i->second == SYN_BRACE_OPEN && next(i)->second == SYN_BRACE_CLOSE)
                    braceTable->emplace(i->first, next(i)->first);
            }

            for (map<unsigned long, unsigned long>::iterator i = braceTable->begin(); i != braceTable->end(); i++)
            {
                braces->remove(make_pair(i->first, SYN_BRACE_OPEN));
                braces->remove(make_pair(i->second, SYN_BRACE_CLOSE));
            }

            if (braces->size() == 0)
                return true;
            else if (depthLimit == 0)
                return false;
            else
            {
                depthLimit--;
                return resolveBraces(braces, braceTable, depthLimit);
            }
        }

        CChain parse(vector<lexer::SToken> tokens, memory::CSymbolTable *symbolTable)
        {
            list< pair <unsigned long, EToken> > braces;
            map<unsigned long, unsigned long> braceTable;
            SError error;

            error = SError();


            if (countTokens(tokens, SYN_BRACE_OPEN) != countTokens(tokens, SYN_BRACE_CLOSE))
                cout << "";

            for (vector<lexer::SToken>::iterator i = tokens.begin(); i != tokens.end(); i++)
            {
                if (i->m_type == SYN_BRACE_OPEN || i->m_type == SYN_BRACE_CLOSE)
                    braces.push_back(make_pair(i->m_id, i->m_type));
            }

            if (!resolveBraces(&braces, &braceTable, 100))
                cout << "";

            CChain output = CChain(tokens, 0, tokens.size()-1, &braceTable, symbolTable, &error);

            if(!error.m_hit)
                return output;
            else
                cout << "";

            return output;
        }

    }
}
