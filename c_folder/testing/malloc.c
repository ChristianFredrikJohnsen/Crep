#include <stdio.h>
#include <stdlib.h>




int main() {
    
    printf("We are now starting to allocate memory for an integer.\n");

    int *ptr = (int *)malloc(sizeof(int));
    printf("Value: %d\nMemory location: %p\n", *ptr, ptr);

    short *pot = (short *)calloc(1, sizeof(short));
    printf("Value: %d\nMemory location: %p\n", *pot, pot);
}






