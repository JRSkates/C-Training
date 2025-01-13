// Pointers Overview
// A pointer in C is a variable that stores the memory address of another variable. Pointers provide flexibility in how we manipulate memory and pass information.



#include <stdio.h>

// Function to print a message
void greet() {
    printf("Hello, World!\n");
}

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

int main() {
    // 1. Variable Pointers
    // Variable pointers are pointers that hold the address of a variable.

    // Key Points:
    // A pointer variable is declared using the * operator.
    // The & operator gives the address of a variable.
    // The * operator (dereferencing) accesses the value 
    // at the address stored in a pointer.

    int A = 100; // A is a normal variable
    int *B = &A; // B is a pointer variable, pointing at the memory address of A

    int num = 42;
    int *ptr = NULL;       // Declare a pointer to an int

    ptr = &num;     // Store the address of num in ptr

    printf("Value of num: %d\n", num);       // Output: 42
    printf("Address of num: %p\n", &num);    // Address of num
    printf("Value at address ptr points to: %d\n", *ptr); // Dereference ptr

    // Pointer Declaration: int *ptr; declares ptr as a pointer to an integer.
    // Initialization: A pointer should always be initialized before dereferencing.
    // NULL Pointer: A pointer can be initialized to NULL to indicate it points to nothing.

    // Function pointers are pointers that store the address of a function.

    // Key Points:
    // Functions in C have addresses just like variables.
    // Function pointers allow us to call functions indirectly.


    void (*func_ptr1)();        // Pointer to a function with no parameters and no return value
    int (*func_ptr2)(int, int); // Pointer to a function taking two ints and returning an int

    func_ptr1 = greet;          // Assign address of greet to func_ptr1
    func_ptr2 = add;            // Assign address of add to func_ptr2

    func_ptr1();                // Call the function via pointer
    printf("Sum: %d\n", func_ptr2(5, 7)); // Call add via pointer

    // You don't need the & operator to assign a function to a function pointer 
    // (e.g., func_ptr = function;).
    // You can call a function using (*func_ptr)(args) or simply func_ptr(args).

    return 0;
}
