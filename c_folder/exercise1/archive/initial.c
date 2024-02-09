#include <stdio.h>
#define GREETING "Hello, world!\n"
int main(int argc, char *argv[]) {
    
    #ifdef GREETING
        printf(GREETING);
    #else
        printf("Something else\n");
    #endif
}

// Use makefiles to compile, instead of running commands manually

// Difference between functions declarations and definitions
// Function declaration: tells the compiler about a function's name, return type, and parameters
// Function definition: provides the actual body of the function
// Function definitions should preferable not be in header files.

// pointers and structs are things we should know about
// Heap and valgrind
