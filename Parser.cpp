//
// Created by Lorrens Pantelis on 10/03/2022.
//

#include "Parser.h"


parser::parser(FILE *in) : m_in{in}{
}

parser::~parser() {
    m_codesize = 0;
}


Tokens parser::command(char c) const{
    switch (c) {
        case '>':
            return Tokens::ITERATOR_R;
        case '<':
            return  Tokens::ITERATOR_L;
        case '+':
            return Tokens::INCREMENT;
        case '-':
            return  Tokens::DECREMENT;
        case '.':
            return  Tokens::OUTPUT;
        case ',':
            return  Tokens::INPUT;
        case '[':
            return  Tokens::BEGIN_LOOP;
        case ']':
            return  Tokens::END_LOOP;
        default:
            return  Tokens::UNKNOWN;
    }


}

int parser::codesize() const{
    return m_codesize;
}


std::vector<instructionCluster> parser::parse() {
    char ch;
    while ((ch = (char)fgetc(m_in)) != EOF){
        Tokens code{command(ch)};
        if (code != Tokens::UNKNOWN){ // filter unknown operands
            instructionCluster instr;
            instr.token = code;
            int count = 1;
            Tokens tmpcode{command((char)fgetc(m_in))};
            while (tmpcode == code) {
               ++count;
               tmpcode = command((char)fgetc(m_in));
            }
            fseek(m_in, -1, SEEK_CUR); // put reader 1 step back to read tmpcode again
            instr.amount = count;
            m_code.push_back(instr);
            ++m_codesize;
        }
    }
    return m_code;
}






