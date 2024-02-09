#include <stdio.h>
#include <wchar.h>
#include <stdbool.h>
#include <string.h>


void pint(const char* description, int value) {
    printf("%s: %d\n", description, value);
}

void pfloat(const char* description, float value) {
    printf("%s: %f\n", description, value);
}

void nline() {
    printf("\n");
}

void printmul(int num) {
    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
    }
}

void printIntArray(int numz[], int lenz) { // lenz is how many elements the array has, which is obtained by doing sizeof(mynumbers)/sizeof(*mynumbers)
    nline();
    printf("Printing array of length: %d\n", lenz);
    printf("Pointer value: %p\n", numz);
    printf("Stride length: %lu\n", sizeof(numz[0]));
    nline();
    for (int i = 0; i < lenz; i++) {
        printf("%d\n", numz[i]);
    }
}

void basicPrinting() {
    printf("Hello, World!\n");
    printf("Programming is fun!\n");
    printf("Not sure if this works\n");
    printf("Inserting \t a tab\n");
    printf("Inserting a backslash \\ \n");
    printf("Inserting a double quote \" \n");

}


void charprocedure() {
    char grade = 'C';
    printf("Your grade is %c\n", grade);
    char name[] = "Christian";
    printf("Your name is %s\n", name);
}

void numeric() {
    double deez = 1.2E5;
    float nuts = 3.4E3;
    printf("Deez nuts: %lf\n", deez + nuts); // The narrowest type is promoted to the widest type, nuts gets promoted to double
    double donald = 1.23456789;
    printf("Donald: %.lf\n", donald); // This is essentially the same as taking the floor of the number
    printf("Donald: %.1lf\n", donald);
    printf("Donald: %.2lf\n", donald);
    printf("Donald: %.4lf\n", donald);
    printf("Donald: %.7lf\n", donald);
    printf("Donald: %.10lf\n", donald);
    
    int donaldo = (int)donald; // Casting from double to int
    printf("Donaldo: %d\n", donaldo);
}

void memzy() {
    int bernard;
    float grete;
    double jakob;
    char alfons;

    printf("%lu\n", sizeof(bernard)); // 4 bytes
    printf("%lu\n", sizeof(grete)); // 4 bytes
    printf("%lu\n", sizeof(jakob)); // 8 bytes
    printf("%lu\n", sizeof(alfons)); // 1 byte

    /*
    alfons = 'à'; // Just avoid these non-ASCII characters
    printf("%lu\n", sizeof(alfons)); // 1 byte, but it's not a standard ASCII character, so we get a warning

    wchar_t alfred = L'à'; // This works, but I am not able to print it
    wprintf(L"%lc\n", alfred);
    */

    char *str = "à";
    printf("%s\n", str);
    printf("%lu\n", sizeof(str)); // 8 bytes
    str = "a";
    printf("%s\n", str);
    printf("%lu\n", sizeof(str)); // 8 bytes

    int frabo = 10.32; // This is a valid statement, but why?
    printf("%d\n", frabo); // 10

    int f = 5;
    int t = 2;
    float result = f / t; // This is usually not what you want
    printf("%f\n", result); // 2.000000
    // In this case, you did integer division, and then promoted the result to a float
    // What you wanted to do was to promote the integers to floats, and then do the division
    
    float correctResult = (float) f / t;
    printf("%f\n", correctResult); // 2.500000
    printf("%.1f\n", (float) f/t); // 2.5
}

void constants() {
    const int theOneNumber = 41;
    printf("%d\n", theOneNumber);
    // theOneNumber = 42; Cannot change read-only variable
    
    const float CONSTANT = 3.1415926535;
    printf("%f\n", CONSTANT); // Just showing that the constant variables should be named in all caps
}

void operations() {
    int a = 5;
    int b = 2;

    int sum = a + b;
    int diff = a - b;
    int prod = a * b;
    float quot = (float) a / b;
    int rem = a % b;

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);
    printf("Quotient: %.2f\n", quot);
    printf("Remainder: %d\n", rem);

    printf("Incremented a: %d\n", ++a);
    printf("Decremnt b after print: %d\n", b--);
    printf("%d\n", a);
    printf("B now has the value 1: %d\n", b);

    printf("The value of a is: %d\n", a);
    printf("a += 3 -> %d\n", a += 3);
    printf("a -= 5 -> %d\n", a -= 5);
    printf("a *= 3 -> %d\n", a *= 3);
    printf("a /= 5 -> %d\n", a /= 5);

    int frank = 5;
    float hoppo = frank / 2.0;
    printf("Frankern: %d\n", frank); // 2
    frank /= 2.432; // You are still doing integer division, I suppose the float is converted to an int
    printf("Frankern: %d\n", frank); // 1
    printf("Hoppo: %f\n", hoppo);


    int brabong = 7;
    brabong %= 4;
    printf("Brabong: %d\n", brabong); // 3.000000
    brabong = 4;
    brabong &= 2;
    printf("Brabong: %d\n", brabong); // 0
    brabong = 4;
    brabong |= 2;
    printf("Brabong: %d\n", brabong); // 6
    int bing = 7;
    int bang = 8;
    int bong = bing | bang;
    printf("Bong: %d\n", bong); // 15

    int x = 3, y = 2;
    printf("Original values: x = %d, y = %d\n", x, y);
    printf("Binary representations: x = 0000 0011, y = 0000 0010\n");
    printf("Bitwise AND: %d, Bitwise OR: %d, Bitwise XOR: %d\n", x & y, x | y, x ^ y);

    int bob = 2;
    printf("Original Bob: %d\n", bob);
    printf("Bob rightshift: %d\n", bob >> 1); // 1
    printf("Bob leftshift: %d\n", bob << 1); // 4

    int sigma = 5;
    printf("Sigma: %d\n", sigma);
    sigma <<= 5;
    printf("Sigma: %d\n", sigma);
    
    int omega = 0x40000000;
    printf("Omega: %d\n", omega);
    omega <<= 1;
    printf("Omega: %d\n", omega);

    long alpha = 0x40000000; // Long can be represented as 32 bits, but modern systems use 64 bits
    long long beta = 0x40000000; // Long long demands 64 bits, even on systems which use 32 bits for long
    printf("Number of bytes: %lu\n", sizeof(alpha));
    printf("Number of bytes: %lu\n", sizeof(beta));
    printf("%ld\n", alpha);

    // logical operators subsection:
    // C actually doesn't have a boolean type, so the operators return 1 for true and 0 for false
    int r = 5, s = 3, t = 3, u = 1, v = 0, w = 0;
    
    printf("r == s: %d\n", r == s);
    printf("s == t: %d\n", s == t);
    printf("r != s: %d\n", s != t);
    printf("r > s: %d\n", r > s);
    printf("r < s: %d\n", r < s);
    printf("r >= s: %d\n", r >= s);
    printf("s <= t: %d\n", s <= t);

    printf("r && s: %d\n", r && s);
    printf("r && v: %d\n", r && v); // 0 means false, so here we get: true and false = false
    printf("r || v: %d\n", r || v); // true or false = true
    printf("w || v: %d\n", w || v); // false or false = false
    printf("!v: %d\n", !v); // not false = true

    pint("Here is r", r);


}

void bools() {

    bool x = true;

    printf("x: %d\n", x);

    int a = 10, b = 9;

    bool someval = a == b;

    printf("a > b: %d\n", a > b);
    printf("Someval: %d\n", someval);
}

void ifelse() {

    int a = 20, b = 18, c = 10;

    if (a > b) {
        printf("a is greater than b\n");
    } else {
        printf("a is not greater than b\n");
    }

    if (c < b < a) {
        printf("Success!\n");
    } else {
        printf("Failure!\n");
    }

    if (c > a) {
        printf("c is greater than a\n");
    } else if (c > b) {
        printf("c is greater than b\n");
    } else {
        printf("c is less than both a and b\n");
    }

    c = 19;
    if (c > a) {
        printf("c is greater than a\n");
    } else if (c > b) {
        printf("c is greater than b\n");
    } else {
        printf("c is less than or equal to both a and b\n");
    }

    (c <= 20) ? printf("c is less than or equal to 20\n") : printf("c is greater than 20\n");

    int day = 8;

    switch (day) {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    case 7:
        printf("Sunday\n");
        break;
    default:
        printf("Invalid day, please enter a number between 1 and 7\n");
    }

    const char* dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    day = 0;


    if (1 <= day && day <= 7) {
        printf("Hello\n");
        printf("%s\n", dayNames[day - 1]);
    } else {
        printf("Invalid day, please enter a number between 1 and 7\n");
    }
    printf("%d\n", true < 0);
    printf("%d\n", true == 2);
    printf("%d\n", true == 1);
    printf("%d\n", true == 0);
}

void whileloop() {

    int i = 0;
    // post-increment
    while (i < 5) {
        printf("i: %d\n", i++);
    }
    
    printf("\n");
    
    // Incrementing before the print (pre-increment)
    i = 0;
    while (i < 5) {
        printf("i: %d\n", ++i);
    }

    // Just an interesting observation:

    int a = 0;
    int b = ++a;
    printf("Pre-increment) a: %d, b: %d\n", a, b); // a: 1, b: 1
    
    a = 0;
    b = a++;
    printf("Post-increment) a: %d, b: %d\n", a, b); // a: 1, b: 0

    // do-while:
    printf("\n");
    i = 0;

    do {
        printf("i: %d\n", i);
        i++;
    }
    while (i < 5);

    nline();

    // The key feature is that this loop will always execute at least once
    i = 8;

    do {
        printf("i: %d\n", i);
        i++;
    }
    while (i < 5);

    nline();

    int dice = 2;

    while (dice <= 6) {
        if (dice < 6) {
            printf("You rolled a %d\n", dice);
        } else {
            printf("YATZY!\n");
        }
        dice++;
    }
}

void forloop() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("i: %d\n", i);
    }

    nline();

    for (i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("i: %d, j: %d\n", i, j);
        }
    }

    /*
    The third argument is implicitly called when the rest of the code in the loop has been executed
    So whether it is i++ or ++i doesn't matter in this case

    while (i < 5) {
        printf("i: %d\n", i);
        i++ or ++i;
    }

    We can see from the while example that whether we use i++ or ++i doesn't matter.
    A similar argument can be made for the for-loop.
    */
    
    for (int k = 0; k < 5; k++) {
        printf("k: %d\n", k);
    }

    for (int k = 0; k < 5; ++k) {
        printf("k: %d\n", k);
    }

    for (int k = 0; k < 100; k += 13) {
        printf("Iteration: %d k: %d\n", k/13 + 1, k);
    }


    for (i = 0; i < 10; i++) { // skips number 4
        if (i == 4) {
            continue;
        }
        printf("i: %d\n", i);
    }

    for (i = 0; i < 10; i++) { // stops at number 7
        if (i == 7) {
            break;
        }
        printf("i: %d\n", i);
    }

}

void arrays() {

    int mynumbers[] = {41, 3, 77, 99, 1};
    printf("%d\n", mynumbers[0]);

    mynumbers[0] = 169;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", mynumbers[i]);
    }

    nline();

    printf("Size and elem_length: %lu, %lu\n", sizeof(mynumbers), sizeof(mynumbers[0]));
    printIntArray(mynumbers, sizeof(mynumbers)/sizeof(mynumbers[0]));

    mynumbers[0] = 169;
    printf("Some undefined behavior:\n");
    for (int i = 5; i < 8; i++) { // Getting some good old undefined behavior
        printf("%d\n", mynumbers[i]);
    } // This type of undefined behavior isn't very harmful, we are just reading memory and interpreting it in a way that doesn't make sense
    // It is like reading a book in chinese, and then trying to interpret it as if it were written in english.
    // You won't destroy the book or anything, but what you are doing is quite meaningless.

    nline();


    int gregor[5]; // Initializing an array with 5 elements, the elements are not initialized, so they contain indeterminate (garbage) values.
    for (int i = 0; i < 5; i++) {
        printf("%d\n", gregor[i]);
    }

    int brebar[5] = {0}; // Initializing an array with 5 elements, and setting all elements to 0
    for (int i = 0; i < 5; i++) {
        printf("%d\n", brebar[i]);
    }

    int habar[5] = {7, 9}; // Inits the first two elements to 7 and 9, and the rest to 0
    for (int i = 0; i < 5; i++) {
        printf("%d\n", habar[i]);
    }
}

void pointers() {
    
    int mynumbers[] = {41, 3, 77, 99, 1};
    
    int *p = mynumbers; // This is the same as p = &mynumbers[0];
    printf("Pointer value: %p\n", p);
    
    int *q = &mynumbers[4]; // This is the same as q = mynumbers + 4;
    printf("Pointer value: %p\n", q);

    // The pointers are giving you memory addresses.
    // We can dereference the pointers to get the values they point to.

    printf("The first element is %d, and the last element is %d\n", *p, *q);

    printf("Distance between pointers: %lu\n", q - p); // 4 elements in range (first, last), which means that the entire array has 5 elements
    printf("Last element is *q: %d, which is the same as *(p + 4): %d\n", *q, *(p + 4));


}


void genericSwap(void *a, void *b, size_t size) {
    /* 
    Some code from GPT4, showing how you can use void pointers to swap the contents of two memory locations
    In this case, we don't really care what the memory addresses are pointing to, we just want to swap the contents
    This omits the problem where we might need to write one swap-function for char, one for int, one for float, etc.
    */
    char buffer[size];
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
}

int swapper() {
    int x = 5, y = 10;
    genericSwap(&x, &y, sizeof(int));
    printf("x = %d, y = %d\n", x, y);

    double p = 1.1, q = 2.2;
    genericSwap(&p, &q, sizeof(double));
    printf("p = %f, q = %f\n", p, q);

    return 0;
}

int main() {
    
    /*
    charprocedure();
    numeric();
    memzy();
    constants();
    operations();
    bools();
    ifelse();
    whileloop();
    forloop();
    pointers();
    arrays();
    */
    
    swapper();

    return 0; // To indicate success
}

/*
New stuff:

Bitwise operations:
x = 3 & 2;

To understand this, we need to look at the binary representations of 3 and 2:
3: 0000 0011
2: 0000 0010

And when we do the bitwise AND operation, we get:
0000 0010
So the output will be 2.

Similarly, we can do the bitwise OR operation:
x = 3 | 2;
3: 0000 0011
2: 0000 0010
Output: 0000 0011
So the output will be 3.

We can also do the bitwise XOR operation:
x = 3 ^ 2;
3: 0000 0011
2: 0000 0010
Output: 0000 0001
So the output will be 1.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Comments:

This array syntax is interesting.
Something about pointers.

I made some mistake where I wrote:
if (1 <= day <= 7) { ... }
In this case, the condition will always be true, because of the way the comparison is evaluated.
You first compare 1 <= day, then you compare (1 <= day) <= 7.

true <= 7 is always true, since 1 is less than 7,
and false <= 7 is always true, since 0 is less than 7.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This is just a simple file which I am attaching at the bottom.
Simple stuff about data types and format specifiers.
*/

int peter;
float myfloat;
char mychar;

void setVariables() {
    int peter;
    float myfloat;
    char mychar;
    peter = 10;
    myfloat = 10.5;
    mychar = 'X';
}

void sum(int a, int b) {
    printf("The sum of %d and %d is %d\n", a, b, a + b);
}

void largesum(int a, int b, int c) {
    printf("%d + %d + %d = %d\n", a, b, c, a + b + c);
}

void preciseCalculation(double a, double b) {
    printf("%lf / %lf = %lf\n", a, b, a / b);
}

int main_numz() {
    setVariables();
    printf("%d\n", peter);
    printf("%f\n", myfloat);
    printf("%c\n", mychar);
    printf("My favorite values are %d, %f, and %c\n", peter, myfloat, mychar);
    int x = 15;
    sum(peter, x);

    int a = 1, b = 2, c = 3;
    largesum(a, b, c);
    a = b = c = 100;
    largesum(a, b, c);
    double d = 10.0, e = 3.0;
    preciseCalculation(8, 3);
    preciseCalculation(d, e);
    return 0; // To indicate success
}

/*
Most common format specifiers:
%d - integer
%f - floating point
%c - character
*/


/*
Different format specifiers:
%c - character
%d - integer
%e - exponential floating point
%f - floating point
%lf - double (long float)
%i - integer
%o - octal
%s - string
%u - unsigned integer
%lu - unsigned long
%x - hexadecimal
%p - pointer
*/