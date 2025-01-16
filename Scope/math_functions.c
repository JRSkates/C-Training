#include <stdio.h>
#include <math.h>

int main() {
    // Math Functions
    // There is also a list of math functions available, 
    // that allows you to perform mathematical tasks on numbers.

    // To use them, you must include the math.h header file in your program:

    // Square Root
    // To find the square root of a number, use the sqrt() function:

    printf("%.2f\n", sqrt(16));

    // Round a Number
    // The ceil() function rounds a number upwards to its nearest integer, 
    // and the floor() method rounds a number downwards to its nearest integer, and returns the result:

    printf("%.2f\n", ceil(1.4));
    printf("%.2f\n", floor(1.4));

    // Power
    // The pow() function returns the value of x to the power of y (xy):

    printf("%.2f\n", pow(4, 3));

    return 0;
}