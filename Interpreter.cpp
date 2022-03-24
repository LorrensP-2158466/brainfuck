
#include "Interpreter.h"


Interpreter::Interpreter(FILE *in) : m_parser{new parser{in}}, m_curr_dataptr{0}, m_curr_codeOP{0},
                                     m_datastrip{new int[defaultMEMSIZE]}{
    memset(m_datastrip, 0, sizeof(int)*defaultMEMSIZE);
}

Interpreter::~Interpreter() {
    delete m_parser;
}


void Interpreter::executeProgram() {
    m_code = m_parser->parse();
    while (!endOfProgram()) {
        execudeInstruction(m_code[m_curr_codeOP]);
        ++m_curr_codeOP;
    }
}


void Interpreter::execudeInstruction(instructionCluster instruction) {
    switch (instruction.token){
        case (Tokens::ITERATOR_R):
            m_curr_dataptr += instruction.amount;
            break;
        case (Tokens::ITERATOR_L):
            m_curr_dataptr -= instruction.amount;
            break;
        case (Tokens::INCREMENT):
            m_datastrip[m_curr_dataptr] += instruction.amount;
            break;
        case (Tokens::DECREMENT):
            m_datastrip[m_curr_dataptr] -= instruction.amount;
            break;
        case (Tokens::OUTPUT):
            for (int i = 0; i < instruction.amount; ++i) {
                putc(m_datastrip[m_curr_dataptr], stdout);
            }
            break;
        case (Tokens::INPUT):
            m_datastrip[m_curr_dataptr] = getc(stdin);
            break;
        case (Tokens::BEGIN_LOOP):
            m_loopStack.push(m_curr_codeOP);
            break;
        case (Tokens::END_LOOP):
            executeLoop();
            break;
        default:
            return;
    }
}

void Interpreter::executeLoop() {
    if (!currEmpty())
        m_curr_codeOP = m_loopStack.top()-1;
    m_loopStack.pop();
}






