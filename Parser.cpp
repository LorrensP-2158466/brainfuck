//
// Created by Lorrens Pantelis on 10/03/2022.
//

#include "Parser.h"
#include "iostream"


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


std::vector<Tokens> parser::parse() {
    char ch;
    int i = 0;
    while ((ch = fgetc(m_in)) != EOF){
        Tokens code = command(ch);
        if (code != Tokens::UNKNOWN) { // filter out unknown operands
            m_code.push_back(code);
            ++m_codesize;
        }
    }
    return m_code;
}






