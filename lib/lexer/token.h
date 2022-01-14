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
    OP_DEFINE = 0,
    OP_IF = 1,
    OP_IFF = 2,
    OP_NOT = 3,
    OP_AND = 4,
    OP_NAND = 5,
    OP_OR = 6,
    OP_XOR = 7,
    OP_NOR = 8,
    OP_XNOR = 9,
    ID_IDENTIFIER = 10,
    SYN_SEPERATOR = 11,
    SYN_BRACE_OPEN = 12,
    SYN_BRACE_CLOSE = 13,
    LTRL_TRUE = 14,
    LTRL_FALSE = 15
};

namespace cherubim::lexer
{

    struct SToken
    {
        string m_value;
        EToken m_type;
        unsigned long m_id;
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
