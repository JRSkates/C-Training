// Write a program to sort a string array in ascending order.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This is the comparison function that will be passed to qsort. 
// It tells qsort how to compare two elements in the array.
int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
// *(char *)a: Dereferences the casted pointer to retrieve the char value pointed to by a.
// *(char *)b: Dereferences the casted pointer to retrieve the char value pointed to by b.

int main() {
    char str_arr[] = {'h', 'e', 'l', 'l', 'o'};
    int arr_length = sizeof(str_arr) / sizeof(str_arr[0]);

    qsort(str_arr, arr_length, sizeof(char), compare);

    printf("Sorted string array in ascending order:\n");
    for (int i = 0; i < arr_length; i++) {
        printf("%c\n", str_arr[i]);
    }

    return 0;
}

/*
compare function:
The function compare is used as a callback for the qsort function. 
It tells qsort how to compare two elements in the array during sorting. 
Specifically, it compares two strings in lexicographical (dictionary) order.


Key Points:
const void *:

qsort operates on generic data types, so it passes pointers to the elements as void *. 
The void * type means the pointer is not associated with any specific data type.
In this case, a and b are pointers to the elements being compared, and these elements are pointers to strings (char *).

strcmp returns:
A negative value (< 0) if the first string is less than the second string.
0 if the strings are equal.
A positive value (> 0) if the first string is greater than the second string.
qsort uses this value to decide the order of the elements.


*(const char **)a
a is a const void *, meaning it’s a generic pointer.
To use strcmp, you need to tell the compiler that a is a pointer to a char * (i.e., a pointer to a pointer to a character).
(const char **)a casts a to the correct type: a pointer to a char *.
*(const char **)a dereferences this pointer, giving you the actual char * string.


return strcmp(*(const char **)a, *(const char **)b);
The strcmp function compares the two strings pointed to by a and b:
*(const char **)a is the first string.
*(const char **)b is the second string.
The result of strcmp determines the relative order of these strings in lexicographical order.


char *str_arr[] = {"hello", "my", "name", "is", "Jack", "Skates"};
When qsort Calls compare:
First Pair of Strings:

a points to str_arr[0] ("hello").
b points to str_arr[1] ("my").

*(const char **)a → "hello"
*(const char **)b → "my"
strcmp("hello", "my") returns a value < 0 (because "hello" is less than "my").

Result:
"hello" remains before "my" in the array.
Subsequent Comparisons:
qsort continues to call compare for other pairs, using the same logic to determine the order of the strings.

Visualizing Memory
Initial State of str_arr:

Index | Value   | Pointer (Address)
------|---------|------------------
  0   | "hello" | Pointer to "hello"
  1   | "my"    | Pointer to "my"
  2   | "name"  | Pointer to "name"
  3   | "is"    | Pointer to "is"
  4   | "Jack"  | Pointer to "Jack"
  5   | "Skates"| Pointer to "Skates"

qsort passes pointers to the pointers (e.g., &str_arr[0] and &str_arr[1]) to compare.
compare dereferences the pointers twice to access the actual strings for comparison.

Why Double Dereferencing?
The array is an array of pointers (char *), and qsort operates on the pointers to these pointers (void *). To access the actual string:

First Dereference:
(const char **)a: Casts the generic void * to a pointer to a char *.
Second Dereference:
*(const char **)a: Retrieves the char *, which points to the actual string.
Summary
Function Purpose:
compare is a callback function for qsort to compare two strings.
Logic:
Cast void * to const char ** to access the strings.
Use strcmp to compare the strings lexicographically.

return strcmp(*(const char **)a, *(const char **)b);
Dereferences a and b twice to get the strings and compares them using strcmp.
*/