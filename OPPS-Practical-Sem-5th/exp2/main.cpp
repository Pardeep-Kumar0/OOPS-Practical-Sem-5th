// main.cpp
// Experiment 2 — C vs C++: compile & call a C function from C++

// Goal: Learn compilation steps and how to call a C function from C++ using extern "C".
#include <iostream>
extern "C" int add(int a, int b); // C linkage for the C function

int main() {
    std::cout << "3 + 5 = " << add(3,5) << '\n';
    return 0;
}




// # compile C then C++ and link
// gcc  -c adder.c    -o adder.o
// g++  -c main.cpp   -o main.o
// g++  main.o adder.o -o prog

// # or one-shot (g++ will call gcc for C file)
// g++ main.cpp adder.c -o prog
// ./prog
// # optional: see preprocessor output
// g++ -E main.cpp -o main.i



//Explanation:
// extern "C" tells the C++ compiler don’t mangle the name — use C linkage so linker finds add.

// Typical compilation stages:

// Preprocess (-E) → compile to assembly (-S) → assemble to object (-c) → link object files.

// Use gcc/g++ -c to make object .o files, then link with g++ so C++ runtime is included.

// Prefer explicit compilation steps when debugging linking/name-mangling issues.