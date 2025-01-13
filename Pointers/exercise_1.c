// Exercise 1, In a void function, 
// add two values and then print that value in main​

#include <stdio.h>

// The function recieves the two ints to add
// and also a pointer to the address of an 
// empty sum variable
void addTwoValues(int a, int b, int *sum) {
    *sum = a + b;
}

// This acts like a global variable

int main() {
    int num1 = 5;
    int num2 = 10;
    int sum;

    addTwoValues(num1, num2, &sum);
    
    printf("Sum: %d\n", sum);
    return 0;
}