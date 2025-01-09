#include <stdio.h>

int main(void) {
    // Write a program where you have 2 variables (A and B) initialised as zero, 
    // this program should iterate 20 times, 
    // in each iteration you should increment "A" by 3 and "B" by 7. 
    // The program should print the current values every 5 iterations 
    // and the last values, besides that, 
    // the program should print A if it is an odd number, 
    // and print B if it is an even number.

    int a = 0;
    int b = 0;

    for (int i = 1; i <= 20; i++) {
        a += 3;
        b += 7;

        if (i % 5 == 0) {
            printf("After %d iterations:\n", i);
            printf("A: %d\n", a);
            printf("B: %d\n", b);
        }

        if (a % 2 != 0) {
            printf("At iteration %d, A is odd: %d.\n", i, a);
        }

        if (b % 2 == 0) {
            printf("At iteration %d, B is even: %d\n", i, b);
        }
    }

    return 0;

    //Output:
    // At iteration 1, A is odd: 3.
    // At iteration 2, B is even: 14
    // At iteration 3, A is odd: 9.
    // At iteration 4, B is even: 28
    // After 5 iterations:
    // A: 15
    // B: 35
    // At iteration 5, A is odd: 15.
    // At iteration 6, B is even: 42
    // At iteration 7, A is odd: 21.
    // At iteration 8, B is even: 56
    // At iteration 9, A is odd: 27.
    // After 10 iterations:
    // A: 30
    // B: 70
    // At iteration 10, B is even: 70
    // At iteration 11, A is odd: 33.
    // At iteration 12, B is even: 84
    // At iteration 13, A is odd: 39.
    // At iteration 14, B is even: 98
    // After 15 iterations:
    // A: 45
    // B: 105
    // At iteration 15, A is odd: 45.
    // At iteration 16, B is even: 112
    // At iteration 17, A is odd: 51.
    // At iteration 18, B is even: 126
    // At iteration 19, A is odd: 57.
    // After 20 iterations:
    // A: 60
    // B: 140
    // At iteration 20, B is even: 140
}

// gcc -o loop-exercise loop-exercise.c
// ./loop-exercise