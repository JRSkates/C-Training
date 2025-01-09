#include <stdio.h>

int main() {
    // Relational Operators
    // Relational operators compare two values 
    // and return a boolean result (true or false).
    int a = 10, b = 20;

    printf("a == b: %d\n", a == b);
    // a == b: 0
    printf("a != b: %d\n", a != b);
    // a != b: 1
    printf("a < b: %d\n", a < b);
    // a < b: 1
    printf("a > b: %d\n", a > b);
    // a > b: 0
    printf("a <= b: %d\n", a <= b);
    // a <= b: 1
    printf("a >= b: %d\n", a >= b);
    // a >= b: 0
    printf("\n");


    // Logical Operators 
    // Logical operators combine or negate boolean expressions
    int c = 10, d = -5;

    printf("(c > 0) && (d > 0): %d\n", (c > 0) && (d > 0));
    // c > 0) && (d > 0): 0
    printf("(c > 0) || (d > 0): %d\n", (c > 0) || (d > 0));
    // (c > 0) || (d > 0): 1
    printf("!(c > 0): %d\n", !(c > 0));
    // !(c > 0): 0

    return 0;
}