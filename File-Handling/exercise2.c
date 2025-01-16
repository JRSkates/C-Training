// Write a program that counts the number of words inside a file.

#include <stdio.h>

int main() {
    FILE *file = fopen("exercise2.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int word_count = 0;
    char c;

    // Read each character from the file
    while ((c = fgetc(file))!= EOF) {
        // Check if the character is a space or a new line
        if (c == ' ' || c == '\n') {
            word_count++;
        }
    }

    // Count the final word
    if (word_count > 0 && c != ' ' && c != '\n') {
        word_count++;
    }

    fclose(file);

    printf("Number of words: %d\n", word_count);

    return 0;
}