
#pragma once

#include <cstdio>
#include <vector>
#include <array>
const int defaultCODESIZE = 100;

enum class Tokens{INCREMENT, DECREMENT, ITERATOR_L, ITERATOR_R, BEGIN_LOOP, END_LOOP, OUTPUT, INPUT, UNKNOWN};


class parser {
public:
    explicit parser(FILE *in);
    ~parser();
    std::vector<Tokens> parse();
    [[nodiscard]] int codesize() const;

private:
    //instruction set
    std::array<char, 8> m_instructionset{'.', ',', '[', ']', '>', '<', '+', '-'};
    // tokens
    [[nodiscard]] Tokens command(char c) const;
    //code
    std::vector<Tokens> m_code{};
    int m_codesize{0};
    FILE *m_in;

};


