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

        insert(make_pair("IF", OP_IF));
        insert(make_pair("IFF", OP_IFF));
        insert(make_pair("NOT", OP_NOT));
        insert(make_pair("AND", OP_AND));
        insert(make_pair("NAND", OP_NAND));
        insert(make_pair("OR", OP_OR));
        insert(make_pair("XOR", OP_XOR));
        insert(make_pair("NOR", OP_NOR));
        insert(make_pair("XNOR", OP_XNOR));
        insert(make_pair("TRUE", LTRL_TRUE));
        insert(make_pair("FALSE", LTRL_FALSE));
        insert(make_pair("T", LTRL_TRUE));
        insert(make_pair("F", LTRL_FALSE));
        insert(make_pair("1", LTRL_TRUE));
        insert(make_pair("0", LTRL_FALSE));
    }

    bool CTokenTable::addSynToken(char token, EToken type)
    {
        m_syntacticTokens.insert(token);
        return insert(make_pair(string(1, token), type)).second;
    }

    bool CTokenTable::addComplexToken(char first, char second, EToken type)
    {
        m_complexTokens.insert(make_pair(first, second));
        return insert(make_pair(string(1, first) + string(1, second), type)).second;
    }

    bool CTokenTable::addCall(string call)
    {
        return insert(make_pair(call, KWD_CALL)).second;
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
