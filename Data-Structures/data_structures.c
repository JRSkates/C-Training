#include <stdio.h>
#include <string.h> // For string functions

int main() {
    // Arrays
    // a collection of elements of the same data type
    // stored in contiguous memory locations.

    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]); // Access elements using index
    }
    printf("\n");

    char string_arr[5] = {'1', '2', '3', '4', '5'}; // Single characters
    for (int i = 0; i < 5; i++) {
        printf("%c ", string_arr[i]); // Use %c for characters
    }
    printf("\n");

    // Key Notes:
    // Indexing starts at 0.
    // Out-of-bound access causes undefined behavior.
    // Arrays can store primitive types (int, char, etc.) or complex types (struct, union).




    // Strings
    // A string in C is a character array ending with a null terminator (\0).

    char str[] = "Hello";  // Automatically adds '\0'

    char str1[20] = "Hello";
    char str2[] = "World";

    strcat(str1, str2);  // Concatenate
    printf("Concatenated: %s\n", str1);

    printf("Length: %lu\n", strlen(str1));  // Length
    printf("Compare: %d\n", strcmp(str1, str2));  // Compare

    // Key Notes:
    // Functions: strlen(), strcpy(), strcat(), strcmp().
    // Strings require #include <string.h> for operations.




    // Structs
    // A struct is a user-defined data type that can contain multiple data members.

    struct Student {
        int id;
        char name[50];
        float marks;
    };

    struct Student student1 = {1, "John Doe", 85.5};
    printf("Student ID: %d\n", student1.id);
    printf("Student Name: %s\n", student1.name);
    printf("Student Marks: %.2f\n", student1.marks);

    struct Person {
        char name[50];
        int age;
        float height;
    };

    struct Person p1 = {"Alice", 25, 5.6};

    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Height: %.1f\n", p1.height);

    // Key Notes:
    // Structures can contain various data types (int, char, float, etc.).
    // Access members using dot operator (e.g., student1.name).




    // Enums
    // An enum is a set of named integer constants

    // Enums are meant to make your code easier to read, write, 
    // and maintain by giving meaningful names to sets of related constants 
    // (instead of just numbers).

    enum Status { FAILURE, SUCCESS };
    enum Status status = SUCCESS;

    if (status == SUCCESS) {
        printf("Success\n");
    } else if (status == FAILURE) {
        printf("Failure\n");
    }

    enum Offices {OESTERLY, BRENTWOOD, LEEDS};   

    enum Offices my_office = BRENTWOOD;

    if (my_office == BRENTWOOD) {
        printf("I work in the Brentwood office.\n");
    } else {
        printf("I don't work in the Brentwood office.\n");
    }

    // Key Notes:
    // Enums can be used to define named integer constants.
    // Access members using enum name (e.g., RED).
    // Enums are useful when you want to represent a fixed set of related values.
    // Enums are not available in C++, but they can be used in C.

    return 0;
}

// gcc -o data_structures data_structures.c
// ./data_structures