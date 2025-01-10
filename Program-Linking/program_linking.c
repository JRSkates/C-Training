// Preprocessor Directives
// Preprocessor directives are commands that start with # 
// and are processed before the actual compilation begins.

// Common directives:
// #include: Include header files.
// #define: Define constants/macros.
// #ifdef, #ifndef: Conditional compilation.
// #pragma: Compiler-specific instructions.

#include <stdio.h>
#include "math_operations.h"

#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int main() {
    int result_add = add(5, 2);
    int result_subtract = subtract(5, 2);
    int result_multiply = multiply(5, 2);
    float result_divide = divide(5.0, 2.0);

    printf("Addition: %d\n", result_add);
    printf("Subtraction: %d\n", result_subtract);
    printf("Multiply: %d\n", result_multiply);
    printf("Division: %.2f\n", result_divide);

    // Priting constants from #define
    printf("PI: %f\n", PI);
    printf("Square of 4: %d\n", SQUARE(4));

    return 0;
}

// gcc -o program_linking program_linking.c math_operations.c