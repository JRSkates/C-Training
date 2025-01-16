#include <stdio.h>

int main() {
    
    int myNumbers[4] = {25, 50, 75, 100};
    int i;

    for (i = 0; i < 4; i++) {
      printf("%d\n", myNumbers[i]);
    }

    // Result:
    // 25
    // 50
    // 75
    // 100

    // Instead of printing the value of each array element, let's print the memory address of each array element:
    for (int i = 0; i < 4; i++) {
      printf("%p\n", &myNumbers[i]);
    }
    
    // Result:
    // 0x16b5bb3f0
    // 0x16b5bb3f4
    // 0x16b5bb3f8
    // 0x16b5bb3fc
    // Note that the last number of each of the elements' memory address is different, with an addition of 4.
    // It is because the size of an int type is typically 4 bytes, remember:

    // Create an int variable
    int myInt;

    // Get the memory size of an int
    printf("%zu\n", sizeof(myInt));
    // Result:
    // 4

    // So from the "memory address example" above, you can see that the compiler reserves 4 bytes of memory for each array element,
    // which means that the entire array takes up 16 bytes (4 * 4) of memory storage:

    // Get the size of the myNumbers array
    printf("%zu\n", sizeof(myNumbers));
    // Result:
    // 16

    // How Are Pointers Related to Arrays
    // Ok, so what's the relationship between pointers and arrays? 
    // Well, in C, the name of an array, is actually a pointer to the first element of the array.
    // Confused? Let's try to understand this better, and use our "memory address example" above again.
    // The memory address of the first element is the same as the name of the array:

    // Get the memory address of the myNumbers array
    printf("%p\n", myNumbers);

    // Get the memory address of the first array element
    printf("%p\n", &myNumbers[0]);
    // Result:
    // 0x16b4473f0
    // 0x16b4473f0

    // This basically means that we can work with arrays through pointers!
    // How? Since myNumbers is a pointer to the first element in myNumbers, you can use the * operator to access it:

    // Get the value of the first element in myNumbers
    printf("%d\n", *myNumbers);

    // Result:
    // 25

    // To access the rest of the elements in myNumbers, you can increment the pointer/array (+1, +2, etc):

    // Get the value of the second element in myNumbers
    printf("%d\n", *(myNumbers + 1));

    // Get the value of the third element in myNumbers
    printf("%d\n", *(myNumbers + 2));

    // Result:
    // 50
    // 75

    // Or loop through it:
    int *ptr = myNumbers;

    for (int i = 0; i < 4; i++) {
      printf("%d\n", *(ptr + i));
    }
    // Result:
    // 25
    // 50
    // 75
    // 100

    // It is also possible to change the value of array elements with pointers:

    // Change the value of the first element to 13
    *myNumbers = 13;

    // Change the value of the second element to 17
    *(myNumbers +1) = 17;

    // Get the value of the first element
    printf("%d\n", *myNumbers);

    // Get the value of the second element
    printf("%d\n", *(myNumbers + 1));

    return 0;
}