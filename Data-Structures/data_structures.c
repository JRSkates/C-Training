#include <stdio.h>

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



    // Strings

    return 0;
}