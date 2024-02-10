#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold a non-zero element
typedef struct {
    int col;    // Column index of the element
    int value;  // Value of the element
} Element;

int main() {
    int numRows = 5; // Example: 5 rows
    Element *sparseMatrix[5]; // Array of pointers, one for each row

    // Example: Initialize row 2 with 2 non-zero elements
    int row = 2;
    sparseMatrix[row] = (Element *)malloc(2 * sizeof(Element)); // Allocate space for 2 non-zero elements
    sparseMatrix[row][0].col = 3; // Column index of first non-zero element
    sparseMatrix[row][0].value = 42; // Value of first non-zero element
    sparseMatrix[row][1].col = 4; // Column index of second non-zero element
    sparseMatrix[row][1].value = 27; // Value of second non-zero element

    // Print the non-zero elements of the sparse matrix
    printf("Non-zero elements in row %d:\n", row);
    for (int i = 0; i < 2; i++) {
        printf("Col %d: %d\n", sparseMatrix[row][i].col, sparseMatrix[row][i].value);
    }

    // Free allocated memory (important!)
    free(sparseMatrix[row]);

    return 0;
}
