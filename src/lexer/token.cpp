//
// Created by Niclas on 01.11.2021.
//

#include <utility>
#include <map>
#include <string>
#include <vector>
#include "token.h"

using namespace std;

namespace lexer
{

c_TokenTable::c_TokenTable()
{
    b_addComplexToken(':', '=', OP_DEFINE);

    b_addSynToken('(', SYN_BRACE_OPEN);
    b_addSynToken('[', SYN_BRACE_OPEN);
    b_addSynToken('{', SYN_BRACE_OPEN);
    b_addSynToken(')', SYN_BRACE_CLOSE);
    b_addSynToken(']', SYN_BRACE_CLOSE);
    b_addSynToken('}', SYN_BRACE_CLOSE);
    b_addSynToken(';', SYN_SEPERATOR);

    insert(make_pair("IF", OP_IF));
    insert(make_pair("IFF", OP_IFF));
    insert(make_pair("T", OP_TOP));
    insert(make_pair("F", OP_BOTTOM));
    insert(make_pair("NOT", OP_NOT));
    insert(make_pair("AND", OP_AND));
    insert(make_pair("NAND", OP_NAND));
    insert(make_pair("OR", OP_OR));
    insert(make_pair("XOR", OP_XOR));
    insert(make_pair("NOR", OP_NOR));
    insert(make_pair("XNOR", OP_XNOR));
    insert(make_pair("TRUE", STM_TRUE));
    insert(make_pair("FALSE", STM_FALSE));
    insert(make_pair("T", STM_TRUE));
    insert(make_pair("F", STM_FALSE));
    insert(make_pair("1", STM_TRUE));
    insert(make_pair("0", STM_FALSE));
}

bool c_TokenTable::b_addSynToken(char token, e_Token type)
{
    st_syntacticTokens.insert(token);
    return insert(make_pair(string(1, token), type)).second;
}

bool c_TokenTable::b_addComplexToken(char first, char second, e_Token type)
{
    st_complexTokens.insert(make_pair(first, second));
    return insert(make_pair(string(1, first) + string(1, second), type)).second;
}

bool c_TokenTable::b_addCall(string call)
{
    return insert(make_pair(call, KWD_CALL)).second;
}

set< pair<char, char> > *c_TokenTable::st_getComplexTokens()
{
    return &st_complexTokens;
}

set<char> *c_TokenTable::st_getSyntacticTokens()
{
    return &st_syntacticTokens;
}

}
