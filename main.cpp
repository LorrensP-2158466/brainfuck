#include "Interpreter.h"
#include <fstream>
#include <filesystem>
#include <iostream>

int main() {
    int i = 0;
    FILE *in = fopen("helloworld.txt", "r+");
    Interpreter interpreter{in};
    interpreter.executeProgram();
    fclose(in);
    return EXIT_SUCCESS;
}
