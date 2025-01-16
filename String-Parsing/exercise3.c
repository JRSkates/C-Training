// Write a program that counts the number of times a word is in a phrase

#include <stdio.h>
#include <string.h>
void to_lowercase(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char str[] = "The is my string my favourite string made for my exercise";
    int count = 0;
    char word[] = "my";

    // copy of the string so we don't modify the original string
    char str_copy[sizeof(str)];
    strcpy(str_copy, str);

    // Convert the string to lowercase for case-insensitive comparison
    to_lowercase(str_copy);

    printf("%s\n", str_copy);

    char *token = strtok(str_copy, " ");

    while (token!= NULL) {
        // printf("%s\n", token);
        if(strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    printf("The word 'my' appears %d times in the given phrase.\n", count);

    return 0;
}