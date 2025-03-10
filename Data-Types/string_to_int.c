#include <stdio.h>

// Function to convert a string to an unsigned long integer
int str_to_unsigned_long_int(char string[]) {
    unsigned long x = 0;

    for(int i = 0; string[i] != '\0'; i++) {
        x += (unsigned long) string[i];
    }

    printf("Unsigned Long int = %ld", x);
    return 0;
}

int main() {
    str_to_unsigned_long_int("Jack");
}


// gcc -o string_to_int string_to_int.c
// ./str_to_int