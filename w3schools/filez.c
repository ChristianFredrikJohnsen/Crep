#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n() { // New line
    printf("\n");
}

void errorCheck(short operationReturn) {
    if (operationReturn == 0) {
        printf("Operation successful\n");
    } else {
        printf("Operation failed\n");
    }
}

void printCheck(short operationReturn) {
    if (operationReturn >= 0) {
        printf("Successfully wrote %d characters to file.\n", operationReturn);
    } else {
        printf("Operation failed\n");
    }
}

void fileCreation() {
    
    FILE *myFilePtr = fopen("filetesting.txt", "w"); // Test that it works to create a FILE pointer
    errorCheck(fclose(myFilePtr));

    FILE *rootPtr = fopen("/home/chrisunix/vscode_main/bob.txt", "w");
    printCheck(fprintf(rootPtr, "Hello, World!"));
    errorCheck(fclose(rootPtr));
    
    FILE *fptr = fopen("/home/chrisunix/vscode_main/bob.txt", "a");
    printCheck(fprintf(fptr, "\nChristian Fredrik Johnsen!"));
    errorCheck(fclose(fptr));

    FILE *rptr = fopen("/home/chrisunix/vscode_main/bob.txt", "r");
    char myText[500];

    printf("Here is the text:\n\n");
    while (fgets(myText, sizeof(myText), rptr)) { // fgets returns NULL when it reaches EOF, NULL is 0, 0 is false
        printf("%s", myText);
    }

    n();n(); // New lines

    printf("This is what's inside the char array: %s\n", myText);
    errorCheck(fclose(rptr));




}

int main() {
    fileCreation();
    return 0;
}