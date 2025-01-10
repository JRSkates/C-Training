#include <stdio.h>

int main() {
    // 2-byte variable Prot initialized to 0xB7B2
    // Composed of three fields:
    // What data type can hold two bytes
    unsigned short Prot = 0xB7B2;

    // structs and unions could be helpful here

    // Extract three fields using bit masking and shifting
    unsigned int Type = (Prot >> 10) & 0x3F;       // Extract 6 bits (Type)
    unsigned int Priority = (Prot >> 7) & 0x07;   // Extract 3 bits (Priority)
    unsigned int ID = Prot & 0x7F;                // Extract 7 bits (ID)

    // Print the values
    printf("Type: %u\n", Type);
    printf("Priority: %u\n", Priority);
    printf("ID: %u\n", ID);

    return 0;
}