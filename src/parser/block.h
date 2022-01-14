//
// Created by Niclas on 19.12.2021.
//

#ifndef POS_BLOCK_H
#define POS_BLOCK_H

enum EBlock
{
    BLOCK_CHAIN,
    BLOCK_IDENTIFIER,
    BLOCK_TRUE,
    BLOCK_FALSE
};

struct SBlock
{
    SBlock(EBlock type, void *reference)
    {
        this->m_type = type;
        this->m_reference = reference; 
    };
    EBlock m_type;
    void *m_reference;
};

#endif //POS_BLOCK_H
