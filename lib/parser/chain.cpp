//
// Created by Niclas on 19.12.2021.
//

#include "chain.hpp"

namespace cherubim
{
    namespace parser 
    {

        CChain::CChain(vector<lexer::SToken> tokens, unsigned long from, unsigned long to, map<unsigned long, unsigned long> *braceTable, memory::CSymbolTable *symbolTable, SError *error)
        {
            lexer::SToken current;
            lexer::SToken previous;
            lexer::SToken next;

            this->m_symbolTable = symbolTable;

            if (from >= to)
                *error = SError(ERR_FROM_TO, "From lower than to.", current.m_id);

            if (from > tokens.size()-1 || to > tokens.size()-1)
                *error = SError(ERR_FROM_TO, "Indexes exceed token list.", current.m_id);

            for (size_t i = from; i != to+1; i++)
            {
                if (error->m_hit)
                    break;
                
                current = tokens.at(i);
                previous = (i) ? tokens.at(i-1) : lexer::SToken{"NIL", NIL, ULONG_MAX};
                next = (i == to) ? tokens.at(i+1) : lexer::SToken{"NIL", NIL, ULONG_MAX};

                switch (current.m_type)
                {
                case SYN_BRACE_OPEN:
                    if (braceTable->find(current.m_id) != braceTable->end()) {
                        i = braceTable->find(current.m_id)->second;
                        push_back(SBlock(BLOCK_CHAIN, new CChain(tokens, current.m_id, braceTable->find(current.m_id)->second, braceTable, this->m_symbolTable, error)));
                    }
                    else
                        *error = SError(ERR_SYNTAX, "Brace opened but not enclosed.", current.m_id);
                    break;
                case LTRL_TRUE:
                case LTRL_FALSE:
                    if ((previous.m_type <= SYN_BRACE_OPEN || previous.m_type == NIL) && (next.m_type <= ID_IDENTIFIER || next.m_type == SYN_BRACE_CLOSE || next.m_type == NIL))
                        push_back(SBlock(current.m_type, new bool(current.m_type == LTRL_TRUE)));
                    else
                        *error = SError(ERR_SYNTAX, "Illegal token.", current.m_id);
                    break;
                case OP_IF:
                case OP_IFF:
                case OP_AND:
                case OP_NAND:
                case OP_OR:
                case OP_XOR:
                case OP_NOR:
                case OP_XNOR:
                    if ((previous.m_type >= SYN_BRACE_CLOSE || previous.m_type == NIL) && (next.m_type >= LTRL_TRUE || next.m_type == SYN_BRACE_OPEN || next.m_type == NIL))
                        push_back(SBlock(current.m_type, nullptr));
                    else
                        *error = SError(ERR_SYNTAX, "Illegal token.", current.m_id);
                    break;
                case OP_NOT:
                    if ((previous.m_type <= OP_XNOR || previous.m_type == NIL) && (next.m_type == ID_IDENTIFIER || next.m_type == SYN_BRACE_OPEN || next.m_type >= LTRL_TRUE || next.m_type == NIL))
                        push_back(SBlock(current.m_type, nullptr));
                    else
                        *error = SError(ERR_SYNTAX, "Illegal token.", current.m_id);
                    break;
                case ID_IDENTIFIER:
                    if ((previous.m_type <= ID_IDENTIFIER || previous.m_type == SYN_BRACE_OPEN || previous.m_type == NIL) && (next.m_type <= ID_IDENTIFIER || previous.m_type == SYN_BRACE_CLOSE || next.m_type == NIL))
                        push_back(SBlock(current.m_type, new string(current.m_value)));
                    else
                        *error = SError(ERR_SYNTAX, "Illegal token.", current.m_id);
                    break;
                default:
                    *error = SError(ERR_SYNTAX, "Undefinied token.", current.m_id);
                    break;
                }
            }
        }

        bool CChain::evaluate()
        {
            return m_eval;
        }

    }
}