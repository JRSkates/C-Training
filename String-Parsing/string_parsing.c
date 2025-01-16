#include <stdio.h>
#include <string.h> // For string functions

int main() {
    // String Parsing in C
    // Strings in C are arrays of characters terminated by a null character (\0).
    // String parsing involves operations like copying, concatenation, comparison, searching, and tokenization.

    // ----------------------------------------------------------------------
    // strcpy and strncpy
    // Copies one string into another.

    // strcpy: Copies the entire source string (including the null terminator) into the destination.
    char src1[] = "Hello, World!";
    char dest1[50]; // Ensure destination has enough space
    strcpy(dest1, src1);
    printf("strcpy: %s\n", dest1);

    // strncpy: Copies up to n characters. If n > length of source, it fills the rest with null characters.
    char src2[] = "C Programming";
    char dest2[10];
    strncpy(dest2, src2, 10); // Copies only the first 10 characters
    dest2[9] = '\0'; // Ensure null termination (good practice)
    printf("strncpy: %s\n", dest2);

    // Key Notes:
    // strcpy does not check for buffer overflow. Always ensure the destination buffer is large enough.
    // strncpy is safer because you can limit the number of characters, but always null-terminate explicitly if needed.
    // Use strncpy when working with fixed-size buffers.

    // ----------------------------------------------------------------------
    // strcat and strncat
    // Concatenates (joins) two strings.

    // strcat: Appends the source string to the destination string.
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("strcat: %s\n", str1);

    // strncat: Appends up to n characters from the source string to the destination.
    char str3[50] = "Hello, ";
    char str4[] = "C Programming";
    strncat(str3, str4, 5); // Appends the first 5 characters of str4
    printf("strncat: %s\n", str3);

    // Key Notes:
    // strcat does not check for buffer overflow, so ensure the destination has enough space.
    // strncat is safer because you can limit the number of characters appended.

    // ----------------------------------------------------------------------
    // strcmp and strncmp
    // Compares two strings lexicographically (based on ASCII values).

    // strcmp: Compares two strings.
    char comp1[] = "Hello";
    char comp2[] = "World";
    int result = strcmp(comp1, comp2);
    if (result == 0) {
        printf("strcmp: Strings are equal.\n");
    } else if (result < 0) {
        printf("strcmp: '%s' is less than '%s'.\n", comp1, comp2);
    } else {
        printf("strcmp: '%s' is greater than '%s'.\n", comp1, comp2);
    }

    // strncmp: Compares up to n characters of two strings.
    char comp3[] = "Hello";
    char comp4[] = "Help";
    int result2 = strncmp(comp3, comp4, 3); // Compare first 3 characters
    if (result2 == 0) {
        printf("strncmp: First 3 characters are equal.\n");
    } else if (result2 < 0) {
        printf("strncmp: '%s' is less than '%s'.\n", comp3, comp4);
    } else {
        printf("strncmp: '%s' is greater than '%s'.\n", comp3, comp4);
    }

    // Key Notes:
    // strcmp returns:
    //   0: Strings are equal.
    //  <0: First string is less than the second.
    //  >0: First string is greater than the second.
    // strncmp allows you to compare a specific number of characters.

    // ----------------------------------------------------------------------
    // strstr
    // Finds the first occurrence of a substring in a string.

    char haystack[] = "C Programming is fun!";
    char needle[] = "Programming";
    char *substr = strstr(haystack, needle);
    if (substr != NULL) {
        printf("strstr: Found substring '%s' at position: %ld\n", needle, substr - haystack);
    } else {
        printf("strstr: Substring not found.\n");
    }

    // Key Notes:
    // strstr returns a pointer to the first occurrence of the substring or NULL if not found.

    // ----------------------------------------------------------------------
    // strtok
    // Tokenizes a string by splitting it into substrings based on a set of delimiters.

    char text[] = "C,Programming,is,fun!";
    char *token = strtok(text, ","); // Split by comma
    while (token != NULL) {
        printf("strtok: %s\n", token);
        token = strtok(NULL, ","); // Continue splitting
    }

    // Key Notes:
    // strtok modifies the original string by inserting null terminators ('\0').
    // Successive calls to strtok require NULL as the first argument.

    // ----------------------------------------------------------------------
    // strlen
    // Returns the length of a string (excluding the null terminator).

    char example[] = "Hello, World!";
    size_t len = strlen(example);
    printf("strlen: The length of '%s' is %lu.\n", example, len);

    // Key Notes:
    // strlen does not include the null terminator in the count.
    // Always ensure the string is properly null-terminated before using strlen.

    return 0;
}
