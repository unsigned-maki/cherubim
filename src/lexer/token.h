//
// Created by Niclas on 01.11.2021.
//

#ifndef POS1_TOKEN_H
#define POS1_TOKEN_H
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

enum e_Token {
    KWD_CALL,
    OP_DEFINE,
    OP_IF,
    OP_IFF,
    OP_TOP,
    OP_BOTTOM,
    OP_NOT,
    OP_AND,
    OP_NAND,
    OP_OR,
    OP_XOR,
    OP_NOR,
    OP_XNOR,
    ID_IDENTIFIER,
    SYN_SEPERATOR,
    SYN_BRACE_OPEN,
    SYN_BRACE_CLOSE,
    STM_TRUE,
    STM_FALSE
};

struct s_Token
{
    string value;
    e_Token type;
};

namespace cherubim::lexer
{

class c_TokenTable : public map<string, e_Token>
{
    private:
        set< pair<char, char> > st_complexTokens;

        set<char> st_syntacticTokens;

        bool b_addSynToken(char token, e_Token type);

        bool b_addComplexToken(char first, char second, e_Token type);
    public:        
        c_TokenTable();

        bool b_addCall(string call);

        set< pair<char, char> > *st_getComplexTokens();
        
        set<char> *st_getSyntacticTokens();
};

}

#endif //POS1_TOKEN_H
