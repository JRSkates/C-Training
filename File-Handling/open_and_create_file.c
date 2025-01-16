#include <stdio.h>
// Syntax
// FILE *fopen(const char *filename, const char *mode);

// filename: Name of the file to open or create.
// mode: Specifies the purpose of opening the file:

// Mode	    Description
// "r"	    Open for reading (file must exist).
// "w"	    Open for writing (creates or truncates).
// "a"	    Open for appending (creates if missing).
// "r+"	    Open for reading and writing.
// "w+"	    Open for reading and writing (truncates).
// "a+"	    Open for reading and appending.

int main() {
    // Open a file in write mode
    FILE *file = fopen("open_and_create.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("File opened successfully.\n");

    // Close the file
    fclose(file);
    return 0;
}
