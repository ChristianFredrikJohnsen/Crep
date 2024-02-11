#include <stdio.h>
#include <string.h>

int main() {
    int value = 41;
    int *ptr = &value;
    int **ptr2 = &ptr;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;
    int ******ptr6 = &ptr5;
    int *******ptr7 = &ptr6;
    int ********ptr8 = &ptr7;
    int *********ptr9 = &ptr8;
    int **********ptr10 = &ptr9;

    printf("Value: %d\n", **********ptr10); // lolz
}

