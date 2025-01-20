// Creating Libraries in C
// Libraries in C are reusable collections of functions or code that can be linked to your program. 
// There are two types:

// Static Libraries
// Static libraries are .a files (on Linux/Unix) or .lib files (on Windows).
// The code from the library is copied into your program's executable during the linking phase.
// This makes your executable self-contained, but larger in size.
// Steps to Create a Static Library
// Create C Source Files Write reusable functions in .c files:

// c
// // math_functions.c
// int add(int a, int b) {
//     return a + b;
// }

// int subtract(int a, int b) {
//     return a - b;
// }
// Compile Object Files Compile the .c files into object (.o) files:

// bash
// gcc -c math_functions.c -o math_functions.o
// Create the Static Library Use ar (archive tool) to bundle the object files into a library:

// bash
// ar rcs libmath.a math_functions.o
// Link the Static Library Use the library in a program:

// c
// // main.c
// #include <stdio.h>

// int add(int a, int b);
// int subtract(int a, int b);

// int main() {
//     printf("Sum: %d\n", add(5, 3));
//     printf("Difference: %d\n", subtract(5, 3));
//     return 0;
// }
// Compile with the static library:

// bash
// gcc main.c -L. -lmath -o program
// Here, -L. specifies the library path, and -lmath links libmath.a.

// Shared Libraries
// Shared libraries are .so files (on Linux/Unix) or .dll files (on Windows).
// The library is not copied into the executable but is loaded at runtime.
// This reduces the executable size and allows updates to the library without recompiling.
// Steps to Create a Shared Library
// Create C Source Files Use the same source file as above (math_functions.c).

// Compile Object Files with PIC (Position-Independent Code) Shared libraries 
// require PIC to allow multiple programs to share the library in memory:

// bash
// gcc -c -fPIC math_functions.c -o math_functions.o
// Create the Shared Library Use the -shared option to create the .so file:

// bash
// gcc -shared -o libmath.so math_functions.o
// Link the Shared Library Use the shared library in a program (same main.c as above):

// bash
// gcc main.c -L. -lmath -o program
// Run the program by ensuring the library is in the library path:

// bash
// Copy code
// export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
// ./program