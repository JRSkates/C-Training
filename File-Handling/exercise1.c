// Write a program that create a file and write your name inside.

#include <stdio.h>

int main() {
    FILE *file = fopen("exercise1.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "Jack Skates");

    fclose(file);

    return 0;
}
