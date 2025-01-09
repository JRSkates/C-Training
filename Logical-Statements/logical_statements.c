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
    printf("\n");




    // Switch Statements
    // Executes a block of code based on a condition
    int day = 4;

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
            printf("Invalid day number.\n");
    }
    // Thursday
    printf("\n");




    // for loops
    // Executes a block of code a specified number of times
    int sum = 0;

    for (int i = 0; i <= 10; i++) {
        sum += i;
    }
    printf("The sum of numbers from 0 to 10 is: %d\n", sum);
    // The sum of numbers from 0 to 10 is: 55
    printf("\n");

    return 0;
}