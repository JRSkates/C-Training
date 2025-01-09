#include <stdio.h>

// A function declaration specifies the function’s name, parameters, and return type
// but does not define its body. It serves as a contract for the function.
// Ensures that the compiler knows the function’s signature before its use.

// return_type function_name(parameters)
void say_hello(char string[]);

int multiply(int a, int b);


int main(void) {
    say_hello("Jack");

    printf("The product of 5 and 7 is: %d\n", multiply(5, 7));

    int result = multiply(12, 34);
    printf("The product of 12 and 34 is: %d\n", result);
}

// Functions are reusable blocks of code that perform a specific task. 
// They are the core of modular programming in C.
void say_hello(char string[]) {
    printf("Hello, %s!\n", string);
};

int multiply(int a, int b) {
    return a * b;
}