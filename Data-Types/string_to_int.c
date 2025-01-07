#include <stdio.h>

int str_to_unsigned_long_int(char string[]);

int main() {
    str_to_unsigned_long_int("Jack");
}

// Function to convert a string to an unsigned long integer
int str_to_unsigned_long_int(char string[]) {
    // char string[] = "sammy";
    long x = 0;

    for(int i = 0; string[i] != '\0'; i++) {
        x += (long) string[i];
    }

    printf("Long int = %ld", x);
    return 0;
}