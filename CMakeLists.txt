cmake_minimum_required(VERSION 3.21)
project(project)

set(CMAKE_CXX_STANDARD 20)
add_executable(project
        main.cpp
        Interpreter.cpp
        Interpreter.h Parser.cpp Parser.h)
