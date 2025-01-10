#include <stdio.h>
#include "math_operations.h"

int main() {
    int result_add = add(5, 2);
    int result_subtract = subtract(5, 2);
    int result_multiply = multiply(5, 2);
    float result_divide = divide(5.0, 2.0);

    printf("Addition: %d\n", result_add);
    printf("Subtraction: %d\n", result_subtract);
    printf("Multiply: %d\n", result_multiply);
    printf("Division: %.2f\n", result_divide);

    return 0;
}

// gcc -o program_linking program_linking.c math_operations.c