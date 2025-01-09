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
    printf("\n");
    


    // Conditional Statements
    // Exectues a block of code if the condition is true
    int num = 10;

    if (num > 0) {
        printf("The number is positive.\n");
    }
    // The number is positive.

    int num_two = -5;

    if (num_two > 0) {
        printf("The number is positive.\n");
    } else {
        printf("The number is non-positive.\n");
    }
    // The number is non-positive.

    return 0;
}