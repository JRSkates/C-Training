#include <stdio.h>

int main() {
    // Lots of stuff in C is legacy
    // Unions exist to save space
    struct Pet {
        short id;
        // Union will save this as ONE piece of memory
        // This allows you to "save space", the union only takes up
        // x amount of memory, and you access one piece of data at a time
        union {
            Dog;
            Cat;
            Parrot;
        };
    };

    // Structs and unions can be used to access individual bits
    // Bit fields are worth looking into as well

    return 0;
}