//
// Created by Niclas on 02.11.2021.
//

#ifndef POS_LEXER_H
#define POS_LEXER_H
#include <iostream>
#include "token.h"

namespace cherubim::lexer
{
    extern vector<SToken> lex(string input);
}

#endif //POS_LEXER_H