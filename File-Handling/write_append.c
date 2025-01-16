#include <stdio.h>

int main() {
    // Open a file in write mode
    FILE *file = fopen("write_file.txt", "w");
    
    // Write to the file with fprintf
    fprintf(file, "Writing to this file...\n");

    // Close the file once done
    fclose(file);


    // Open a file to append
    FILE *file_two = fopen("append_file.txt", "a");

    // Append to the file with fprintf
    fprintf(file_two, "\nAdding this text with append");

    // Close the file once done
    fclose(file_two);
}