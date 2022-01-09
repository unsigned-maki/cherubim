//
// Created by Niclas on 01.11.2021.
//

#ifndef POS1_TOKEN_H
#define POS1_TOKEN_H
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

enum EToken
{
    KWD_CALL,
    OP_DEFINE,
    OP_IF,
    OP_IFF,
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
    LTRL_TRUE,
    LTRL_FALSE
};

namespace cherubim::lexer
{

    struct SToken
    {
        string m_value;
        EToken m_type;
        unsigned m_id;
    };

    class CTokenTable : public map<string, EToken>
    {
        private:
            set< pair<char, char> > m_complexTokens;

            set<char> m_syntacticTokens;

            bool addSynToken(char token, EToken type);

            bool addComplexToken(char first, char second, EToken type);

        public:        
            CTokenTable();

            bool addCall(string call);

            set< pair<char, char> > *getComplexTokens();
            
            set<char> *getSynTokens();
    };

}

#endif //POS1_TOKEN_H
