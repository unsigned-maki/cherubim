//
// Created by Niclas on 02.11.2021.
//

#include "lexer.h"

using namespace std;

namespace cherubim::lexer
{

    CTokenTable g_tokenTable;

    inline char up(char c)
    {
        return (c > 0x60 && c < 0x7B) ? c ^ 0x20 : c;
    }

    void postProcess(string *raw)
    {
        string tmp;
    
        for (string::iterator i = raw->begin(); i < raw->end(); i++)
        {
            if (g_tokenTable.getSynTokens()->find(*i) != g_tokenTable.getSynTokens()->end())
            {
                tmp.push_back(' ');
                tmp.push_back(*i);
                tmp.push_back(' ');
            }
            else if (g_tokenTable.getComplexTokens()->find(make_pair(*i, *(i+1))) != g_tokenTable.getComplexTokens()->end())
            {
                tmp.push_back(' ');
                tmp.push_back(*i);
                tmp.push_back(*(i+1));
                tmp.push_back(' ');
                i++;
            }
            else
                tmp.push_back(*i);
        }

        *raw = tmp;
    }

    vector<string> splitAndClean(string input)
    {
        vector<string> splitted;
        string tmp;

        for (string::iterator i = input.begin(); i < input.end(); i++)
        {
            if (*i == ' ' || *i == '\n' || *i == '\t' || *i == '\b' || *i == '\r')
            {
                splitted.push_back(tmp);
                tmp.clear();
                continue;
            }

            tmp.push_back(up(*i));

            if (!splitted.back().length())
                splitted.pop_back();
        }
        
        return splitted;
    }

    vector<SToken> lex(string input)
    {
        unsigned long idCounter;
        vector<SToken> tokens;
        vector<string> splitInput;

        g_tokenTable = CTokenTable();

        postProcess(&input);
        
        splitInput = splitAndClean(input);

        idCounter = 0;

        for (vector<string>::iterator i = splitInput.begin(); i < splitInput.end(); i++)
        {
            map<string, EToken>::iterator lookup = g_tokenTable.find(*i);

            if (lookup != g_tokenTable.end())
            {
                SToken token = {lookup->first, lookup->second, idCounter};
                tokens.push_back(token);
            }
            else
            {
                SToken token = {*i, ID_IDENTIFIER, idCounter};
                tokens.push_back(token);
            }

            idCounter++;
        }

        return tokens;
    }

}
