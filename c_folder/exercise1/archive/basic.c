#include <stdio.h>



int main() {
    printf("Hello, world!\n"); 
    /*
    Valgrind says that 1024 bytes are allocated, when printf is called.
    This is independent of the length of the string you are printing.
    I have no clue why this is the case.
    */ 
    return 0;
}
