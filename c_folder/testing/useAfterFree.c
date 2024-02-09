#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for an integer
    int *ptr = (int *)malloc(sizeof(int));

    *ptr = 42;
    printf("Value before free: %d\nMemory location: %p\n", *ptr, ptr);

    free(ptr); // The memory location which the pointer was pointing to, is now free to use for other purposes

    printf("Value after free: %d\n", *ptr); // Use after free error, a garbage value will be printed

    return 0; // Should probably return 1, since clearly something is not right.
}
