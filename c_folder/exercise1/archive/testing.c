#include <stdio.h>

void stackSmash();
void redeclaration();

int main(int argc, char *argv[]) {
    printf("Hello, world!\n");
    short a = 3, b = 0;

    redaclaration();
    stackSmash();
    printf("%d\n", a / b); // Exception
    
    return 0;
}

void stackSmash() {
    short a[3];
    a[3] = 0; // Exception
}

void redeclaration() {
    int a = 3;
    int a = 4; // Error
}