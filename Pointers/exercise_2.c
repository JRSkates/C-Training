// Exercise 2, Create a function which takes two pointers to integers 
// and swaps the values they are pointing to, 
// without changing the original memory of the two integers

#include <stdio.h>

void swap(int **ptr1, int **ptr2) {
    int *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    // XOR
    // *ptr1 = *ptr1^*ptr2;
    // *ptr2 = *ptr1^*ptr2;
    // *ptr1 = *ptr1^*ptr2;
}

int main() {
    int num1 = 5;
    int num2 = 10;

    int *ptr1 = &num1;
    int *ptr2 = &num2;
  
    printf("Before swap:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("values at pointers: *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
    printf("addresses before swap: *ptr1 = %p, *ptr2 = %p\n", &ptr1, &ptr2);

    swap(&ptr1, &ptr2);

    printf("After swap:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
    printf("values at pointers after swap: *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
    printf("addresses after swap: *ptr1 = %p, *ptr2 = %p\n", &ptr1, &ptr2);

    return 0;
}

