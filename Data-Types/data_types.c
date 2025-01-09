#include <stdio.h>
#include <stdbool.h> // For boolean data type


int main() {
    // Fundamental Data Types:

    // Int 
    // Signed Integers: Can hold positive and negative values (default for int).
    // Signed Range: -2,147,483,648 to 2,147,483,647
    int x = 10;
    printf("The value of int x is: %d\n", x);

    // Unsigned Int
    // Only hold non-negative values, 
    // but their range is double that of signed integers for the same number of bits.
    // Unsigned Range: 0 to 4,294,967,295
    unsigned int u = 89U; // (cannot hold negative values)
    printf("The value of unsigned int u is: %u\n", u);

    long int li = 37485L; // signed long int
    unsigned long int ul = 37485UL; // unsigned long int (cannot hold negative values)
    printf("The value of signed long int ul is: %ld\n", li);
    printf("The value of unsigned long int ul is: %ld\n", ul);

    // Float
    float y = 3.14;
    printf("The value of the float y is: %.2f\n", y);

    // Double
    double z = 2.71828;
    long double ld = 1.4142156423L; // Extended precision
    printf("The value of double z is: %.6f\n", z);
    printf("The value of double ld is: %.10Lf\n", ld);


    // Character
    char c = 'A';
    printf("The value of character c is: %c\n", c);

    // String
    char str[] = "Hello, World!";
    printf("The value of str is: %s\n", str);

    // Boolean
    bool isTrue = true;
    printf("The value of boolean isTrue is: %s\n", isTrue ? "True" : "False");


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

// gcc -o data_types data_types.c
// ./data_types