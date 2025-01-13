// Exercise 1, In a void function, 
// add two values and then print that value in main​

#include <stdio.h>

void addTwoValues(int a, int b) {
    int sum = a + b;
    printf("Sum: %d\n", sum);
}

int main(void) {
    int num1 = 5;
    int num2 = 10;

    addTwoValues(num1, num2);

    return 0;
}