// Exercise 3, Create two pointers to two numbers and swap them 

// void swap(int )

#include <stdio.h>

int main() {
    int num1 = 5;
    int num2 = 10;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    int **ptr3 = &ptr1;
    int **ptr4 = &ptr2;

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    printf("Before swap addresses: ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
    printf("Before swap values: *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);

    int *temp = *ptr3;
    ptr1 = *ptr4;
    ptr2 = temp;
    
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    printf("After swap addresses: ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

    return 0;
}