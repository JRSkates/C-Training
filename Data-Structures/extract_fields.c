#include <stdio.h>
// Consider that a 2 bytes variable Prot is composed of 3 fields (Type, Priority and ID) 
// Write a program that prints the values of of these 3 fields (Type, Priority and ID) if Prot = 0xB7B2.

// union allows multiple variables to share the same memory location.
union Prot {
    // Writing to rawData affects the underlying memory.
    unsigned short rawData; // 2 bytes (16 bits)
    // The bit fields (ID, Priority, Type) reinterpret portions of the same memory.
    struct {
        unsigned short ID: 7;
        unsigned short Priority: 3;
        unsigned short Type: 6;
    } fields;
    // | 15 14 13 12 11 10 | 9 8 7 | 6 5 4 3 2 1 0 |
    //           Type (6)  | Prio  |     ID (7)    |
    //                        (3)
};

// The compiler aligns the memory layout based on the sizes of the union members.
// The largest member determines the size of the union.

int main() {
    union Prot prot;
    prot.rawData = 0xB7B2; // 0xB7B2 = 1011 0111 1011 0010

    printf("Raw Data: %x\n", prot.rawData); // b7b2
    printf("Type: %d\n", prot.fields.Type); // Type: 45
    printf("Priority: %d\n", prot.fields.Priority); // Priority: 7
    printf("ID: %d\n", prot.fields.ID); // ID: 50

    return 0;
}