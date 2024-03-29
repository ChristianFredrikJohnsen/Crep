#include <stdio.h> // printf, scanf (input/output)
#include <string.h> // strlen, strcpy, strcat, strcmp
#include <wchar.h> // Allows us to print special characters (like the norwegian characters)
#include <locale.h> // Needed for the wchartesting function (Don't know what it does yet)
#include <math.h> // pow, sqrt, abs, ceil, floor, round

void matprint(short mat[][4], short row, short col) {
    printf("Element at point (%d, %d): %d\n", row, col, *(*(mat + row - 1) + col - 1));
}

void nline() {
    printf("\n");
}

void arrays() {

    int mynumbers[5] = {7, 6, 5, 4, 3};

    for (int i = 0; i < 5; i++) {
        printf("%d\n", mynumbers[i]);
    }

    printf("Array size in bytes: %lu\n", sizeof(mynumbers));
    printf("Array size in bytes: %ld\n", sizeof(mynumbers));
    printf("Array size in bytes: %zu\n", sizeof(mynumbers));

    printf("Number of bytes per element: %zu\n", sizeof(*mynumbers));
    printf("Number of bytes per element: %zu\n", sizeof(mynumbers[0])); // *mynumbers and mynumbers[0] are equivalent

    printf("Number of elements in array: %zu\n", sizeof(mynumbers) / sizeof(*mynumbers));


    int *ptr = mynumbers;
    ptr = &mynumbers[2];
    printf("Value of ptr: %d\n", *ptr);
    printf("Value of mynumbers[0]: %d\n", mynumbers[0]);


    short myvalues[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < sizeof(myvalues) / sizeof(*myvalues); i++) {
        printf("%d\n", myvalues[i]);
    }

    int ages[] = {20, 22, 18, 35, 48, 26, 87, 70};

    float avg, sum = 0;
    short length = sizeof(ages) / sizeof(*ages), youngest = *ages, oldest = *ages;
    for (int i = 0; i < length; i++) {
        short e = ages[i];
        if (e < youngest) {
            youngest = e;
        } else if (e > oldest) {
            oldest = e;
        }
        sum += e;
    }

    avg = sum / length;
    printf("Average age is: %.2f, youngest age is %d and oldest age is %d.\n", avg, youngest, oldest);


    short mat[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    printf("Value of mat[1][2]: %d\n", mat[1][2]);
    printf("Value of *mat[1]: %d\n", *mat[1]); 
    printf("Value of mat: %p\n", mat);
    printf("Value of *mat: %p\n", *mat);
    printf("Value of **mat: %d\n", **mat);
    printf("Value of *(*mat + 1): %d\n", *(*(mat + 1) + 1)); // Get element at point (2, 2) [standard matrix notation]
    printf("Value of mat[1][1]: %d\n", mat[1][1]); // Get element at point (2, 3) [standard matrix notation]
    printf("Memory location of second row: %p\n", *(mat + 1));

    matprint(mat, 1, 2);

    for (int i = 0; i < 3; ++i) { // Printing the matrix in row-major order
        for (int j = 0; j < 4; ++j) {
            printf("Row: %d, Column: %d, Value: %d\n", i + 1, j + 1, *(*(mat + i) + j)); // I controls the row, J controls the column
            // Syntax here is equivalent to mat[i][j], but pointers are slicker.
        }
    }

    /* mat[1] gives you a pointer to the first element of the second row.
    By dereferencing it, you get the first element of the second row.
    You could also have written *(*mat + 1)
    */
}

void pointy() {

    short mynumbers[3] = {10, 20, 30};
    short *ptr = mynumbers;
    short *ptr2 = &mynumbers[1];

    printf("Pointer 1 address: %p, Pointer 2 address: %p\n", ptr, ptr2);
    // Each address stores 1 byte of memory (byte addressable memory)
    // Since the array is of type short, each element is 2 bytes long, and we get that the second element is 2 bytes ahead of the first element.
    printf("Number length: %zu, Pointer length: %zu\n", sizeof(*mynumbers), sizeof(ptr));

}

void strengu() {

    char name[] = "Christian Fredrik Johnsen";
    char apple[] = "apple";
    printf("Name: %s\n", name);
    printf("First letter: %c\n", *name);
    name[0] = 'T';
    printf("Name: %s\n", name);

    printf("Letter by letter:\n");
    short name_length = sizeof(name) / sizeof(*name);
    for (int i = 0; i < name_length; i++){
        printf("%c\n", name[i]);
    }   

    short apple_len = sizeof(apple) / sizeof(*apple); // This will include the null terminator
    printf("Length of apple: %d\n", apple_len); // We get len = 6 (5 letters + null terminator)

    // In this case, we need to include the null terminator (Automatically added by the compiler when using string literals)
    char intro[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Pretty terrible way of creating a string, but it is possible.
    printf("%s\n", intro);

    char fname[] = "John";
    char lname[] = "Doe";

    printf("The one and only: %s %s\n", fname, lname);
    printf("Testing out what happens when 'single quotes' are used: %c\n", 'a');
    char singleq = '\'';
    char bong = '"';
    printf("Single quote: %c\n", singleq);
    printf("Double quote: %c\n", bong);

    /*
    Escaping single quote only seems to be necessary when you want to create a character, and the character is a single quote.

    */

    char doublez[] = "We are the so-called \"Norwegians\" from the north.";
    printf("%s\n", doublez);
    char backzy[] = "We like backslashes \\ in our strings, and we also like newlines. \n";
    printf("%s", backzy);

    char strange_string[] = "This is a string with a \0 null terminator in the middle.";
    printf("Length of string, according to strlen: %zu\n", strlen(strange_string)); // strlen stops at the null terminator
    printf("%s\n", strange_string); // Quite funny, the string is cut off at the null terminator.
    // So all the text which comes after the null terminator is quite pointless (usually).

    // C thinks the string is over at the null terminator, but this string has two null terminators.
    printf("Hidden message: %s\n", strange_string + strlen(strange_string) + 1); 

    char strabb[] = "BingBangBong";
    char *ptr = strabb;
    ptr += 4;

    printf("Value of ptr: %c\n", *ptr);
    printf("Value of ptr: %s\n", ptr);

    *ptr = 'X'; // Dereferencing to get the character, and then changing the character.
    ptr += 4;
    // ptr = 'X'; Would just be silly, since you are specifying that the new memory address should be 'X', which doesn't make sense.
    printf("Value of strabb: %s\n", strabb);
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("%zu\n", strlen(alphabet));
    printf("Alphabet length (strlen): %zu\n", strlen(alphabet));
    printf("Alphabet length including null terminator (sizeof): %zu\n", sizeof(alphabet));
    
    
    for (int i = 0; i < strlen(alphabet) - 1; i++) {
        printf("%c-", alphabet[i]);
    }
    printf("%c\n", alphabet[strlen(alphabet) - 1]);


    char bobbo[50] = "Bobbo";
    printf("Length of Bobbo: %zu\n", strlen(bobbo));
    printf("Size of Bobbo: %zu\n", sizeof(bobbo)); // We have assigned 50 bytes to the string, but only 6 bytes are used.

    // char knaker[4] = "Knaker"; This should not be done, since the string is too long for the array.
    char sabb[20] = "Hello "; // We need to allocate extra space so that we can concatenate s2 into s1.
    char subb[] = "World!";
    strcat(sabb, subb);
    printf("Sabb: %s\n", sabb);
    printf("Subb: %s\n", subb);
    printf("strlen(sabb): %zu, sizeof(sabb): %zu\n", strlen(sabb), sizeof(sabb));   

    // char subbu[13] = strcpy(subb, sabb); This will not work, since strcpy doesn't return a value.
    char subbu[13]; // 13 bytes of memory is needed to store the string "Hello World!" (12 characters + null terminator)
    strcpy(subbu, sabb);
    printf("%s\n", subbu);


    char a[] = "Hello";
    char b[] = "Hello";
    char c[] = "World";

    printf("a == b: %d\n", a == b); // This will return 0, since the memory addresses are different.
    printf("strcmp(a, b): %d\n", strcmp(a, b)); // This will return 0, since the strings are equal (no lexigraphical difference)
    printf("strcmp(a, c): %d\n", strcmp(a, c)); // This returns a negative number, since H goes before W in the ASCII table.
}

void wchartesting() {

    /*
    I will need to look at this function at a later stage,
    since I am not quite sure how this syntax works, and why we have these random L's in front of the strings.
    The main thing is that this setup works when you want to print out the special norwegian characters.
    */

    // Set the C locale to the user's default (which should be UTF-8 compliant)
    setlocale(LC_ALL, "");

    wchar_t alphabet[] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
    wprintf(L"%zu\n", wcslen(alphabet));
    wprintf(L"Alphabet length: %zu\n", wcslen(alphabet));
    for (size_t i = 0; i < wcslen(alphabet); i++) {
        wprintf(L"%lc\n", alphabet[i]);
    }
}

void userinput() {
    
    short usernum = 12345;
    int count;


    /*
    
    We have two main candidates for user input:
    - scanf
    - fgets


    */

    printf("Enter a number: ");
    // scanf("%hd", &usernum); // The first argument specifies the type (half decimal), and the second argument specifies the memory address of the variable.
    printf("%hd\n", usernum);
    printf("You entered: %hd\n", usernum);

    short specialnum;
    char specialchar;

    printf("Enter a number and a character: ");
    //scanf("%hd %c", &specialnum, &specialchar);
    printf("Your number was: %hd, and your character was %c\n", specialnum, specialchar);

    char firstname[100];
    char lastname[100];
    char joke[100];
    printf("Enter your first name: ");
    // scanf("%s", firstname);
    printf("Enter your last name: ");
    // scanf("%s", lastname);
    printf("Your full name is: %s %s\n", firstname, lastname);

    printf("Write a funny joke: ");
    // scanf("%s", joke);
    printf("Your joke is: %s\n", joke);

    char trabant[3];
    printf("Try to enter a string which is too long: ");
    // scanf("%s", trabant);
    printf("Your string is: %s\n", trabant);

    char trabi[3];
    printf("Try to enter a string which is too long: ");
    // scanf("%2s", trabi); // %2s specifies that the string should be at most 2 characters long (we need to allocate 1 extra byte for the null terminator)
    printf("Your string is: %s\n", trabi);

    char theRest[100];
    // scanf("%s", theRest);
    printf("The rest of the string is: %s\n", theRest);
    
    char fullName[100];
    printf("Enter your full name: ");
    // fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = 0; // This will remove the newline character from the string.
    printf("Your full name is: %s\n", fullName);

    char extraJoke[100];
    printf("Enter a funny joke: ");
    // fgets(extraJoke, sizeof(extraJoke), stdin);
    extraJoke[strcspn(extraJoke, "\n")] = 0; // Again, we remove the newline character from the string.
    printf("Your joke is: %s\n", extraJoke);

    /*
    Just to show that when you set the buffer size to 5, the string will be cut off at 4 characters.
    This is just something to keep in mind, since when we did scanf with %xs, you needed to have x = buffer size - 1.
    But now when we are working with fgets, you need to have x = buffer size.
    A bit frustrating to work with these two different methods of doing essentially the same thing.
    */


    char bingo[100];
    printf("Enter something: ");
    scanf("%s", bingo);
    printf("Your string is: %s\n", bingo);

    // Everything which is written after a space will be read by the fgets.

    char lastJoke[1000];
    printf("Enter a short joke: ");
    fgets(lastJoke, sizeof(lastJoke), stdin); 
    lastJoke[strcspn(lastJoke, "\n")] = 0;
    printf("Your joke is: %s\n", lastJoke);


    // char bung[10];
    // printf("Please just write something: ");
    // fgets(bung, 10, stdin);
    // bung[strcspn(bung, "\n")] = 0;
    // printf("The string is %s\n", bung);
}

void typetesting() {
    short usernum = 12345;
    printf("usernum: %hd\n", usernum);

    unsigned short usa = 65535;
    printf("usa: %hu\n", usa); // half unsigned

    usernum = 65535; // This will cause undefined behavior, since the number is too large for the short data type.
    printf("usernum: %hd\n", usernum); // This will print -1, since the number is too large for the short data type.
    // You can quickly tell that something has gone wrong, since an unsigned short shall never be negative.
}

void pointz() {

    short myage = 20;
    printf("Value stored: %hd\n", myage);
    printf("Memory address: %p\n", &myage);
    
    short *ptr = &myage;
    printf("Pointer: %p\n", ptr);
    printf("Memory address of short: %p\n", &myage);

    printf("Value stored %hd\n", *ptr);

    short numbers[4] = {25, 50, 75, 100};
    for (int i = 0; i < sizeof(numbers) / sizeof(*numbers); i++) {
        printf("Number number %d: %d\n", i + 1, numbers[i]);
    }

    printf("Printing the numbers using pointers:\n");
    for (int i = 0; i < sizeof(numbers) / sizeof(*numbers); i++) {
        printf("Number number %d: %d\n", i + 1, *(numbers + i));
    }


    for (int i = 0; i < sizeof(numbers) / sizeof(*numbers); i++) {
        printf("Number number %d: %p\n", i + 1, &numbers[i]);
    }



    printf("Number of addresses per element: %zu\n", sizeof(*numbers));
    
    short niceNumbers[4] = {5, 10, 15, 20};
    *niceNumbers = 10;
    *(niceNumbers + 2) = 10;
    printf("%d\n", *niceNumbers);

    for (int i = 0; i < sizeof(niceNumbers) / sizeof(*niceNumbers); i++) {
        printf("Index %d: %d\n", i + 1, niceNumbers[i]);
    }

    printf("Accessing an invalid index: %d\n", niceNumbers[4]); // This will print a random number, since we are accessing memory which is not allocated to the array.

    // Wonder what happens now
    *(niceNumbers + 4) = 10; // Undefined behavior, stack smashing is detected
    printf("%d\n", *(niceNumbers + 4)); // The program terminates before this line is reached.

}


void name(char name[]) {
    printf("Hello %s!\n", name);
}

void nameAge(char name[], short age) {
    printf("Hello %s! You are %hd years old.\n", name, age);
}

void arrayNumz(short numbers[5]) {
    printf("These are your five favorite numbers:\n");
    for (int i = 0; i < 5; i++) {
        printf("Number %hd: %hd\n", i + 1, numbers[i]);
    }
}

short transformation(short number) {
    return number * 2 + 7;
}

short multiplication(short a, short b) {
    return a * b;
}

short division(short, short);

short rangeSum(short, short);

/* 
This is considered good practice, since it becomes easier to get an overview of the functions which are used in the program.
Usually, you would have a program where the functions are declared at the top, so that you can see what functions are used in the program.
When working on a larger project, this can be quite useful.
The declarations would be some sort of "table of contents" for the program.

The setup is:

1) Declarations
2) Main function
3) Definitions (of the functions you declared in the beginning)
*/

void functions() {

    char myName[] = "Christian Fredrik Johnsen";
    short age = 20;
    short myNumbers[5] = {41, 20, 30, 40, 50};

    name(myName);
    nameAge(myName, 20);
    arrayNumz(myNumbers);
    
    short result = transformation(*myNumbers);
    printf("The result is: %hd\n", result);
    printf("%hd * %hd = %hd\n", myNumbers[0], myNumbers[1], multiplication(myNumbers[0], myNumbers[1]));

    printf("%hd / %hd = %hd\n", myNumbers[3], myNumbers[1], division(myNumbers[0], myNumbers[1])); // Integer division
    printf("The sum of all numbers between %hd and %hd is %hd\n", 13, 27, rangeSum(13, 27)); // 13 + 14 + 15 + ... + 27

}

void mathy() {

    /*
    IMPORTANT:
    When compiling the program, you need to link the math library.
    This is because the math library is not included in the standard C library.
    
    The command to compile the program is:
    gcc -o mz mz.c -lm

    The -lm flag is used to link the math library to the program.
    */

    printf("Square root of 25: %f\n", sqrt(25));
    printf("Absolute value of 17: %f\n", sqrt(17));

    float bob = 1.4;

    printf("Ceiling of 1.4: %f\n", ceil(bob));
    printf("Floor of 1.4: %f\n", floor(bob));

    short a = 32, b = 4;
    printf("%hd to the power of %hd: %f\n", a, b, pow(a, b));

    // And there are a lot of math functions, including trigonometric functions, logarithmic functions, etc.
    // The standard stuff you would expect from a math library.
}

int main() {

    /*
    CODE WHICH SHOULD NOT BE EXECUTED:
    
    wchartesting();
    typetesting();

    arrays();
    pointy();
    strengu();
    userinput();
    pointz();
    functions();
    mathy();
    */



    // Must a kernel be "re-programmed" for each new processor it wants to support (processors with different ISAs)?
    // With the 

    return 0;
}

short division(short a, short b) {
    // Calculates the result of a divided by b
    return a / b;
}

short rangeSum(short a, short b) {
    /*
    Just an example of something which can be done recursively
    In this case, it would be more efficient to either use a for loop, or even better,
    the formula for the sum of an arithmetic series.
    
    Calculates the sum of all numbers between a and b (inclusive)
    */
    short sum = 0;
    if (b < a) {
        return -1;
    }
    
    if (a == b) {
        return a;
    } else {
        return a + rangeSum(a + 1, b);
    }
}

/*
COMMENTS:

Arrays always act as pointers, unless one of these three functions are used:
- sizeof
- & (address of)
- [] (subscript operator)

In all other cases, the array name will act as a pointer (pointing to the memory address of the first element of the array).


*/