#include <stdio.h>

// Storage Classes
// auto: 
// Default for local variables. The variable is stored in memory and has block scope.

// extern:	
// Declares a global variable or function in another file. Used for cross-file access.

// static:	
// Retains the variable's value between function calls (for local variables) 
// or limits scope to the file (for globals).

// register:	
// Suggests storing the variable in a CPU register for faster access. 
// Actual usage depends on the compiler.

// External declaration
// Used to declare a global variable or function in another file.
extern int global_var;
void print_global();

void auto_example();

void static_example();

void register_example();

int main() {
    auto_example();
    print_global();

    static_example();
    static_example();
    static_example();

    register_example();
    return 0;
}

void auto_example() {
    // Default storage class for local variables. Explicit use is rare.
    auto int x = 10; // Same as int x = 10;
    printf("x = %d\n", x);
}

void static_example() {
    // Static Local Variable: Retains its value between function calls.
    static int counter = 0; // Retains value between calls
    counter++;
    printf("Counter: %d\n", counter);
}

// Suggests storing a variable in a CPU register for faster access. 
// The compiler may ignore this suggestion.
void register_example() {
    register int counter = 0; // Suggest storing in a register
    for (int i = 0; i < 10; i++) {
        counter += i;
    }
    printf("Counter: %d\n", counter);
}

// gcc -o storage_classes storage_classes.c global.c 