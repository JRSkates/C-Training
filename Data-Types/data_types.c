#include <stdio.h>

int main() {
    // Fundamental Data Types:

    // Int 
    int x = 10;
    printf("The value of int x is: %d\n", x);

    // Unsigned Int
    int u = 89U;
    printf("The value of unsigned int u is: %u\n", u);

    long int ul = 37485UL;
    printf("The value of unsigned long int ul is: %ld\n", ul);

    // Float
    float y = 3.14;
    printf("The value of the float y is: %.2f\n", y);

    // Double
    double z = 2.71828;
    printf("The value of double z is: %.6f\n", z);

    // Character
    char c = 'A';
    printf("The value of character c is: %c\n", c);

    // String
    char str[] = "Hello, World!";
    printf("The value of str is: %s\n", str);

    // Boolean
    int isTrue = 1;
    printf("The value of boolean isTrue is: %s\n", isTrue? "True" : "False");


    // Type Casting
    // Allows conversion of one datatype to another
    int a = 10;
    float b = (float) a;
    printf("The value of a (int) converted to float is: %.2f\n", b);

    double c_double = 3.14;
    int d = (int) c_double;
    printf("The value of c_double (double) converted to int is: %d\n", d);


    // Arithmetic Operations
    int add = x + y;
    printf("The value of x + y is: %d\n", add);

    int subtract = x - y;
    printf("The value of x - y is: %d\n", subtract);

    int multiply = x * y;
    printf("The value of x * y is: %d\n", multiply);

    float divide = y / x;
    printf("The value of y / x is: %.2f\n", divide);


    // Increment and Decrement Operations
    int e = 5;
    printf("The value of e before increment is: %d\n", e);
    e++;
    printf("The value of e after increment is: %d\n", e);

    int f = 5;
    printf("The value of f before decrement is: %d\n", f);
    f--;
    printf("The value of f after decrement is: %d\n", f);

    return 0;
}