#include <stdio.h>
#include <stdlib.h>

typedef int *ip; // Cool feature, you can give an alias to a type
void memoryLeak();
void coolFunction();

int main(int argc, char *argv[]) {
    memoryLeak();
    coolFunction();
    return 0;
}


void memoryLeak() {
    short *p = malloc(sizeof(short));
    *p = 5;
    printf("The following is the memory address of p: %p\n", p);
    printf("The short value contained at this address is: %hd\n", *p);
    free(p); // If you comment this line, the memory will not be freed, and the program will have a memory leak
}

void coolFunction() {
    ip p = malloc(sizeof(int)); // Initialize a pointer to an int with the new keyword.
    *p = 41;
    printf("The following is the memory address of p: %p\n", p);
    free(p);
}
