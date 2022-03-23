
#pragma once

#include <cstdio>
#include <vector>
#include <array>

enum class Tokens{INCREMENT, DECREMENT, ITERATOR_L, ITERATOR_R, BEGIN_LOOP, END_LOOP, OUTPUT, INPUT, UNKNOWN};
typedef struct instructionCluster{
    int amount;
    Tokens token;
}instructionCluster;

class parser {
public:
    explicit parser(FILE *in);
    ~parser();
    std::vector<instructionCluster> parse();
    [[nodiscard]] int codesize() const;

private:
    //instruction set
    std::array<char, 8> m_instructionset{'.', ',', '[', ']', '>', '<', '+', '-'};
    // tokens
    [[nodiscard]] Tokens command(char c) const;
    //code
    std::vector<instructionCluster> m_code{};
    int m_codesize{0};
    FILE *m_in;

};


