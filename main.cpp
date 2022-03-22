#include "Interpreter.h"
#include <fstream>
#include <filesystem>

int main() {

    FILE *in = fopen("helloworld.txt", "r+");
    Interpreter interpreter{in};
    interpreter.executeProgram();
    fclose(in);
    return EXIT_SUCCESS;
}
