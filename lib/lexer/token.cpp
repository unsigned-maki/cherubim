//
// Created by Niclas on 01.11.2021.
//

#include "token.h"

using namespace std;

namespace cherubim::lexer
{

    CTokenTable::CTokenTable()
    {    
        addComplexToken(':', '=', OP_DEFINE);

        addSynToken('(', SYN_BRACE_OPEN);
        addSynToken('[', SYN_BRACE_OPEN);
        addSynToken('{', SYN_BRACE_OPEN);
        addSynToken(')', SYN_BRACE_CLOSE);
        addSynToken(']', SYN_BRACE_CLOSE);
        addSynToken('}', SYN_BRACE_CLOSE);
        addSynToken(';', SYN_SEPERATOR);

        emplace("IF", OP_IF);
        emplace("IFF", OP_IFF);
        emplace("NOT", OP_NOT);
        emplace("AND", OP_AND);
        emplace("NAND", OP_NAND);
        emplace("OR", OP_OR);
        emplace("XOR", OP_XOR);
        emplace("NOR", OP_NOR);
        emplace("XNOR", OP_XNOR);
        emplace("TRUE", LTRL_TRUE);
        emplace("FALSE", LTRL_FALSE);
        emplace("T", LTRL_TRUE);
        emplace("F", LTRL_FALSE);
        emplace("1", LTRL_TRUE);
        emplace("0", LTRL_FALSE);
    }

    bool CTokenTable::addSynToken(char token, EToken type)
    {
        m_syntacticTokens.insert(token);
        return emplace(string(1, token), type).second;
    }

    bool CTokenTable::addComplexToken(char first, char second, EToken type)
    {
        m_complexTokens.insert(make_pair(first, second));
        return emplace(string(1, first) + string(1, second), type).second;
    }

    set< pair<char, char> > *CTokenTable::getComplexTokens()
    {
        return &m_complexTokens;
    }

    set<char> *CTokenTable::getSynTokens()
    {
        return &m_syntacticTokens;
    }

}
