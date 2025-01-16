#include <stdio.h>
#include <string.h>

int main() {
    // Open a file for reading
    FILE *file = fopen("file_to_read.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Store the contents of the file
    char my_string[100];

    // Read the content and store it inside my_string
    fgets(my_string, sizeof(my_string), file);

    // Print the content
    printf("Content of the file:\n%s", my_string);

    // Close the file
    fclose(file);

    return 0;
}