// Heap vs. Stack
// In C, memory is divided into two key regions for dynamic and automatic memory allocation:
// Heap and Stack.

// What is the Stack?
// Purpose: Used for static (automatic) memory allocation.
// Structure: A Last-In-First-Out (LIFO) memory structure.
// Lifetime: Variables are automatically allocated when a function is called and deallocated when the function exits.
// Location: Managed by the CPU and grows toward lower memory addresses.
// Speed: Access is fast because allocation/deallocation is handled automatically.


// Stack Characteristics:
// Scope: Variables allocated on the stack are local to the function they are declared in.
// Size: Limited in size (e.g., typically a few MB, depending on the system).
// Usage: Suitable for:
// Local variables.
// Function calls and return addresses.


// What is the Heap?
// Purpose: Used for dynamic memory allocation.
// Structure: A large pool of unstructured memory managed by the programmer.
// Lifetime: Variables persist until they are explicitly deallocated (freed).
// Location: Managed by the operating system and grows toward higher memory addresses.
// Speed: Access is slower than the stack because it requires system calls and manual management.


// Heap Characteristics:
// Scope: Variables on the heap are accessible anywhere in the program via pointers.
// Size: Much larger than the stack but still finite.
// Usage: Suitable for:
// Data structures that grow/shrink dynamically (e.g., linked lists, trees).
// Large objects or arrays.


// Key Differences:
// Feature	    Stack	                            Heap
// Allocation	Automatic (managed by the system)	Manual (programmer must manage)
// Lifetime	    Ends when function returns	        Until explicitly freed
// Speed	    Faster	                            Slower
// Size	        Small (e.g., 1–8 MB)	            Large (e.g., system-dependent, GBs)
// Errors	    Stack overflow	                    Memory leaks, fragmentation

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Stack Example:

void stackExample() {
    int a = 10; // Automatically allocated on the stack
    printf("Stack variable a: %d\n", a);
} // 'a' is automatically deallocated here

// Heap Example:

void heapExample() {
    int *p = (int *)malloc(sizeof(int)); // Dynamically allocate memory on the heap
    *p = 20; // Assign value to allocated memory
    printf("Heap variable: %d\n", *p);

    free(p); // Free the memory to prevent memory leaks
}
int main() {
    stackExample();
    heapExample();
    return 0;
}
