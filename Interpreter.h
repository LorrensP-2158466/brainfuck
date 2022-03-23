

#pragma once
#include "Parser.h"
#include <stack>

const int defaultMEMSIZE = 3000; // default length of the data strip where brainfuck operates on

class Interpreter {
public:
    explicit Interpreter(FILE *in);
    ~Interpreter();
    void executeProgram(); // loops over program and executes it

private:
    int m_curr_dataptr; // current position where the program points to
    int *m_datastrip;
    int m_curr_codeOP;
    std::vector<instructionCluster> m_code; // the array where brainfuck works on
    std::stack<int> m_loopStack;  // a stack to handle loops
    parser *m_parser{}; // the parser

    void execudeInstruction(instructionCluster instruction); // execute instruction
    void executeLoop(); // checks loop condition and changes according to it
    bool currEmpty(){
        return (m_datastrip[m_curr_dataptr] == 0);
    }
    bool endOfProgram(){
        return (m_curr_codeOP > m_parser->codesize());
    }
};

