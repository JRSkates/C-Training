#include <stdio.h>

int sum_of_three(int a, int b, int c);

int main() {
    int num1 = 5;
    int num2 = 10;
    int num3 = 15;

    int result = sum_of_three(num1, num2, num3);
    printf("The sum of %d, %d, and %d is: %d\n", num1, num2, num3, result);

    return 0;
}

// Function to calculate the sum of three numbers
int sum_of_three(int a, int b, int c) {
    return a + b + c;
}

// gcc -o sum_of_numbers sum_of_numbers.c
// ./sum_of_three 