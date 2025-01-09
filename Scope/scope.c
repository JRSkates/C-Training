#include <stdio.h>

// Types of Scope:
// Block Scope:
// Variable is accessible only within the block {} in which it is declared.

// Function Scope:
// Applies to labels (used in goto statements). Visible within the function.

// File Scope:
// Variable is accessible throughout the file where it is declared.

// Global Scope: 
// Variable is accessible across multiple files if declared as extern.

// ----------------------------------------------------------------

// Global variable (File Scope)
int global_var = 100;

void scope_example();

int main() {
    scope_example();
    return 0;
}

void scope_example() {
    // Local variable (Block Scope)
    int local_var = 10;
    printf("Local variable: %d\n", local_var);
    printf("Global variable: %d\n", global_var);

    {
        // Block Scope
        int block_var = 5;
        printf("Block variable: %d\n", block_var);
    }

    // block_var is out of scope here
    // printf("%d", block_var); will cause a compilation error
}