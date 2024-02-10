#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n() { // New line
    printf("\n");
}

/*
NOTE:
A struct definition is treated similarly to a variable declaration. It is not until a variable of the struct type is declared that memory is allocated for the struct.
The syntax from variable declaration is also inherited, which is why we need a semicolon at the end of the struct definition.
To me it still seems redundant, but the idea is that you should always have a semicolon after a declaration, and this struct is a declaration.
*/
struct myFavorites {
    short myNum;
    char myLetter;
    char myName[50];
};

// Alternative way to define a struct:
struct myFavorites2 {short myNum; char myLetter; char myName[50];};

/* 
An example of a struct definition.
This actually makes it more clear to me why you need the semicolon at the end of the struct definition.
Since you can actually declare a variable of the struct type in the same line as the struct definition,
and you must be able to know if that variable is connected to the struct, or if it is a separate variable.

This might not be a bulletproof argument, but I can at least understand that there is some logic behind it.
*/
struct myFavorites3 {short myNum; char myLetter; char myName[50];} 
    chrisFavs = {41, 'C', "Christian"}, 
    bobFavs = {24, 'B', "Bob"},
    aliceFavs = {21, 'A', "Alice"},
    dwayneFavs = {30, 'D', "Dwayne"},
    elizabethFavs = {28, 'E', "Elizabeth"};

enum Level { // The values of an enum are integers, and the first value is 0 by default (auto-incremented by 1 for each value after the first one)
        LOW,
        MEDIUM,
        HIGH
    };

enum MachineLearning { // You can also assign values to the enum values
    DENSE_NEURAL_NETWORK = 1,
    CONVOLUTIONAL_NEURAL_NETWORK = 3,
    RECURRENT_NEURAL_NETWORK = 7,
    TRANSFORMER = 15
};

void favStruct();

void arrayTesting();

void modifyArray(int *arr);

void arrayModz();

void testStruct3();

void mlName(enum MachineLearning model);

void enumz();


int main() {

    /*
    Functions which shouldn't be run:
    
    arrayTesting();
    arrayModz();
    favStruct();
    testStruct3();
    */

    enumz();




    return 0;
}





void favStruct() {
    
    struct myFavorites myFavs;

    myFavs.myNum = 41;
    myFavs.myLetter = 'C';
    strcpy(myFavs.myName, "Christian");
    printf("My favorites are %hd and %c\n", myFavs.myNum, myFavs.myLetter);

    struct myFavorites chrisFavs = {41, 'C', "Christian"}; // Instantiate a struct with values
    printf("My favorites are %hd, %c and %s\n", chrisFavs.myNum, chrisFavs.myLetter, chrisFavs.myName);
    printf("My name is %s\n", chrisFavs.myName);

    struct myFavorites bobFavs;
    bobFavs = chrisFavs; // Bob is a fan of Christian
    printf("Bob's favorites are %hd, %c and %s\n", bobFavs.myNum, bobFavs.myLetter, bobFavs.myName);

    strcpy(bobFavs.myName, "Bob"); // Bob is now a fan of himself
    bobFavs.myNum = 24;
    bobFavs.myLetter = 'B'; // The relationship between Bob and Christian is over
    printf("Bob's favorites are %hd, %c and %s\n", bobFavs.myNum, bobFavs.myLetter, bobFavs.myName);
}

void testStruct3() {
    /*
    I thought this was interesting, you can declare a struct and instantiate some variables of that struct type in the same line.
    So I am just retrieving information about the variables which were declared up top.
    */
    printf("Chris' favorites are %hd, %c and %s\n", chrisFavs.myNum, chrisFavs.myLetter, chrisFavs.myName);
    printf("Bob's favorites are %hd, %c and %s\n", bobFavs.myNum, bobFavs.myLetter, bobFavs.myName);
    printf("Alice's favorites are %hd, %c and %s\n", aliceFavs.myNum, aliceFavs.myLetter, aliceFavs.myName);
    printf("Dwayne's favorites are %hd, %c and %s\n", dwayneFavs.myNum, dwayneFavs.myLetter, dwayneFavs.myName);
    printf("Elizabeth's favorites are %hd, %c and %s\n", elizabethFavs.myNum, elizabethFavs.myLetter, elizabethFavs.myName);
}

void arrayTesting() {
    
    int myArray[5] = {1, 2, 3, 4, 5};
    int rattata[5] = {7, 8, 9, 10, 11};
    
    int *ptr = myArray;
    printf("The first element of ptr is %d\n", *ptr);
    ptr = rattata;
    printf("The first element of ptr is %d\n", *ptr);

    // myArray = rattata; // This is not allowed, arrays are not assignable
}


void arrayModz() { // This function and the one below are here just to show that you can change the memory location of a pointer to an array, but you can't change the memory location of the array itself.
    
    int myArray[5] = {1, 2, 3, 4, 5};

    modifyArray(myArray);

    for (int i = 0; i < sizeof(myArray) / sizeof(*myArray); i++) {
        printf("The value of myArray[%d] in the original function is %d\n", i, myArray[i]);
    }
}


void modifyArray(int *arr) {

    int *ptr = arr;
    int newArr[5] = {10, 15, 20, 25, 30};
    arr = newArr; 
    for (int i = 0; i < 5; i++) {
        printf("The value of arr[%d] is %d\n", i, arr[i]);
    }

    for (int i = 0; i < 5; i++) { // Actually modifies the array
        ptr[i] = newArr[i];
    }

}


void enumz() { // Enumerations are a way to create a new data type in C

    enum Level myLevel = LOW;
    enum Level bobLevel;
    bobLevel = MEDIUM;
    printf("My level is %d\n", myLevel);
    printf("Bob's level is %d\n", bobLevel);

    enum MachineLearning myML = DENSE_NEURAL_NETWORK;
    printf("My machine learning model is %d\n", myML);

    enum MachineLearning bobML = TRANSFORMER;
    printf("Bob's machine learning model is %d\n", bobML);

    enum MachineLearning aliceML = RECURRENT_NEURAL_NETWORK;
    n();
    printf("The ID of Alice's machine learning model is %d\n", aliceML);
    printf("The name of Alice's machine learning model is:\n");
    mlName(aliceML);
}

void mlName(enum MachineLearning model) {
    
    switch (model) {
        
        case DENSE_NEURAL_NETWORK:
            printf("Dense Neural Network\n");
            break;
        
        case CONVOLUTIONAL_NEURAL_NETWORK:
            printf("Convolutional Neural Network\n");
            break;
        
        case RECURRENT_NEURAL_NETWORK:
            printf("Recurrent Neural Network\n");
            break;
        
        case TRANSFORMER:
            printf("Transformer\n");
            break;
    }
}
