//
// Created by Niclas on 02.11.2021.
//

#ifndef POS_LEXER_H
#define POS_LEXER_H
#include "token.h"

namespace cherubim::lexer
{
    vector<s_Token> v_lex(string input);
}

#endif //POS_LEXER_H
