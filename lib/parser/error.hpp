//
// Created by Niclas on 10.01.2022.
//

#ifndef POS1_ERROR_H
#define POS1_ERROR_H
#include <string>

using namespace std;

enum EError
{
    ERR_SYNTAX,
    ERR_NAME,
    ERR_FROM_TO
};

struct SError {
    SError()
    {
        this->m_hit = false;
    };
    SError(EError type, string message, long at)
    {
        this->m_type = type;
        this->m_message = message;
        this->m_at = at;
        this->m_hit = true;
    };
    EError m_type;
    string m_message;
    unsigned long m_at;
    bool m_hit;
};

#endif //POS1_ERROR_H
