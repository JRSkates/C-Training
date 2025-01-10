#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

// Header files (.h) contain declarations for functions, macros, constants, 
// and types that are shared across multiple .c files.
// They allow for modular programming by separating interface (header) from implementation (.c files).


// #ifndef, #define, #endif: Prevent multiple inclusions (guard macros).
// Place function declarations only

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

#endif // MATH_OPERATIONS_H