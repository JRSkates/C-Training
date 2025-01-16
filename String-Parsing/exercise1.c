// Write a program to print individual characters of a string in reverse order.

#include <stdio.h>
#include <string.h> // For string functions

int main() {
    char str[] = "My String!";
    int length = strlen(str) - 1;

    for(int i = 0; i < length; i++) {
        printf("%c\n", str[length - i]); // Print characters in reverse order
    }

    return 0;
}