#include <stdio.h>

int main() {
    // array of chars
    char arr[] = {'M', 'y', ' ', 's', 't', 'r', 'i', 'n', 'g'};
    int length = sizeof(arr) / sizeof(arr[0]);

    // empty string, length of the array plus 1 for null termination
    char string[length + 1];

    // loop through array and assign character to the string
    for(int i = 0; i < length; i++) {
        string[i] = arr[i];
    }

    // add null termination at the end of the string
    string[length] = '\0';

    // print the string
    printf("%s\n", string);

    return 0;
}

// gcc -o char_array_to_string char_array_to_string.c
// ./char_array_to_string