#include <stdio.h>
#include <stdlib.h>


int main() {

    short *ptr[5];
    
    printf("Size of pointer: %lu\n", sizeof(ptr)); // Returns 40, since we have 5 pointers, and each pointer is 8 bytes long
    printf("\nYou should probably not initialize simple short arrays like this, because you don't get the maximum spatial locality\n\n");
    for (int i = 0; i < 5; i++) {
        ptr[i] = (short *)malloc(sizeof(short));
        *ptr[i] = 42;
        printf("Value and memory location: %d | %p\n", *ptr[i], ptr[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("Number %d: %d\n", i + 1, *ptr[i]);
    }

    return 0;
}
