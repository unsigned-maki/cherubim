//
// Created by Niclas on 19.12.2021.
//

#ifndef POS_BLOCK_H
#define POS_BLOCK_H
#include "../lexer/token.hpp"

enum EBlock
{
    BLOCK_NOP,
    BLOCK_CHAIN,
    BLOCK_DEFINE,
    BLOCK_IF,
    BLOCK_IFF,
    BLOCK_NOT,
    BLOCK_AND,
    BLOCK_NAND,
    BLOCK_OR,
    BLOCK_XOR,
    BLOCK_NOR,
    BLOCK_XNOR,
    BLOCK_IDENTIFIER,    
    BLOCK_STATEMENT
};

struct SBlock
{
    SBlock(EToken type, void *reference)
    {
        this->m_reference = reference;

        switch (type)
        {
        case OP_DEFINE:
            this->m_type = BLOCK_DEFINE;
            break;
        case OP_IF:
            this->m_type = BLOCK_IF;
            break;
        case OP_IFF:
            this->m_type = BLOCK_IFF;
            break;
        case OP_NOT:
            this->m_type = BLOCK_NOT;
            break;
        case OP_AND:
            this->m_type = BLOCK_AND;
            break;
        case OP_NAND:
            this->m_type = BLOCK_NAND;
            break;
        case OP_OR:
            this->m_type = BLOCK_OR;
            break;
        case OP_XOR:
            this->m_type = BLOCK_XOR;
            break;
        case OP_NOR:
            this->m_type = BLOCK_NOR;
            break;
        case OP_XNOR:
            this->m_type = BLOCK_XNOR;
            break;
        case ID_IDENTIFIER:
            this->m_type = BLOCK_IDENTIFIER;
            break;
        case LTRL_TRUE:
        case LTRL_FALSE:
            this->m_type = BLOCK_STATEMENT;
            break;
        default:
            this->m_type = BLOCK_NOP;
            break;
        }
    };
    
    SBlock(EBlock type, void *reference)
    {
        this->m_reference = reference;
        this->m_type = type;
    };

    EBlock m_type;
    
    void *m_reference;
};

#endif //POS_BLOCK_H
