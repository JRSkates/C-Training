// Write a program to count the total number of words in a string.

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "My String is five words";
    int length = strlen(str) - 1; // length excluding null terminator
    int count = 0;
    char prev;

    for(int i = 0; i < length; i++) {
        if(str[i] == ' ' && prev != ' ') { // 
            count++;
        }
        prev = str[i];
    }
    // increments counter if character is a space
    // also checks if previous character is NOT a space
    // this allows for double spaces

    // strtok can be used here

    printf("Number of words: %d\n", count + 1); // Add one for the last word
    return 0;
}