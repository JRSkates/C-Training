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



    
    // Unions
    // union is a user-defined data type
    // Contains elements of the different data types just like structure.
    // unlike structures, all the members in the C union are stored in the same memory location.
    // Due to this, only one member can store data at the given point in time.

    union Data {
        int num;
        char ch;
        float flt;
    };

    union Data data;

    data.num = 10;
    printf("Integer value: %d\n", data.num);

    data.ch = 'A';
    printf("Character value: %c\n", data.ch);

    data.flt = 3.14;
    printf("Float value: %.2f\n", data.flt);

    // Key Notes:
    // Unions can be used to store different data types in memory.
    // Access members using union name (e.g., data.num).
    // Unions are useful when you want to save memory and only need to 
    // store one value at a time.




    // Typedef
    // typedef is a keyword in C that allows you to create a new name (alias)
    // for an existing data type.

    typedef unsigned int uint;
    uint my_uint = 10;
    printf("Unsigned integer value: %u\n", my_uint);

    typedef long long ll;
    ll my_ll = 10000000000;
    printf("Long long integer value: %lld\n", my_ll);

    // You can use typedef to define an alias for a structure
    typedef struct Food {
        char name[50];
        float price;
    } food;

    food my_food = {"Pizza", 15.99};
    printf("Food name: %s\n", my_food.name);
    printf("Food price: %.2f\n", my_food.price);

    // Key Notes:
    // Typedef is useful when you want to make your code more readable and maintainable.
    // Typedef allows you to create a new data type by using an existing data type.
    // Use typedef keyword before struct definition to create a new data type.




    // Bit Fields
    // Bit fields are a feature of C that allows you to define variables
    // with a specified number of bits.

    struct BitStatus {
        unsigned int isVisible : 1;  // 1 bit
        unsigned int isEditable : 1; // 1 bit
        unsigned int isDeleted : 1;  // 1 bit
    };

    struct BitStatus fileStatus = {1, 0, 1}; // Initialize bit fields

    printf("Visible: %d\n", fileStatus.isVisible);
    printf("Editable: %d\n", fileStatus.isEditable);
    printf("Deleted: %d\n", fileStatus.isDeleted);


    // Key Notes:
    // Bit fields are useful when you want to save memory by using fewer bytes 
    // to store a variable.
    // Bit fields are declared within a structure or union.



    // Bit Masks
    // Bit masks are a technique used in programming to manipulate and 
    // access specific bits in a variable.

    int x = 9;             // 0000 1001
    int mask = 1 << 2;     // 0000 0100 (Shift 1 left by 2 positions)
    x = x | mask;          // 0000 1001 | 0000 0100 = 0000 1101
    printf("%d\n", x);     // Output: 13

    // Key Notes:
    // Bit masks are used to manipulate and access specific bits in a variable.
    // Bit masks are used when you want to set, clear, or toggle specific bits.
    // Bit masks are typically used in bitwise operations to manipulate binary data.

    return 0;
}

// gcc -o data_structures data_structures.c
// ./data_structures