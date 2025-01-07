#include <stdio.h>
#include <string.h> // For string functions

int main() {
    // Arrays
    // a collection of elements of the same data type
    // stored in contiguous memory locations.

    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]); // Access elements using index
    }
    printf("\n");

    char string_arr[5] = {'1', '2', '3', '4', '5'}; // Single characters
    for (int i = 0; i < 5; i++) {
        printf("%c ", string_arr[i]); // Use %c for characters
    }
    printf("\n");


    // Strings
    // A string in C is a character array ending with a null terminator (\0).

    char str[] = "Hello";  // Automatically adds '\0'

    char str1[20] = "Hello";
    char str2[] = "World";

    strcat(str1, str2);  // Concatenate
    printf("Concatenated: %s\n", str1);

    printf("Length: %lu\n", strlen(str1));  // Length
    printf("Compare: %d\n", strcmp(str1, str2));  // Compare

    return 0;
}