// %d or %i	   Integer (decimal)	                printf("%d", 10);	    10
// %u	       Unsigned integer	                    printf("%u", 10);	    10
// %f	       Floating-point (decimal notation)	printf("%f", 3.14);	    3.140000
// %e or %E	   Scientific notation (exponent)	    printf("%e", 3.14);	    3.140000e+00
// %g or %G	   Shorter of %f or %e format	        printf("%g", 3.14);	    3.14
// %c	       Character	                        printf("%c", 'A');	    A
// %s	       String	                            printf("%s", "Hello");	Hello
// %p	       Pointer address	                    printf("%p", ptr);	    0x7ffee6
// %%	       Prints % itself	                    printf("%%");	        %

#include <stdio.h>

int main() {

    // Integers
    int x = 42;
    printf("Number: %d\n", x);
    // Output   Number: 42

    // Floating-point numbers
    float y = 3.14159;
    printf("Decimal: %.2f\n", y);
    // Output   Decimal: 3.14

    // Characters
    char c = 'A';
    printf("Character: %c\n", c);
    // Output   Character: A

    // Strings
    char str[] = "Hello, World!";
    printf("String: %s\n", str);
    // Output   String: Hello, World!

    // Pointers
    int* ptr = &x;
    printf("Pointer: %p\n", ptr);
    // Output   Pointer: 0x7ffee6

    // Formatted Alignment:
    printf("|%-10s|%10s|\n", "left", "right");
    // Output   |left      |     right|

    // Padded Numbers: 
    printf("|%05d|\n", 7);
    // Output   |00007|

    // New line and tab
    printf("Line 1\nLine 2\tTabbed\n");


    return 0;
}

// gcc -o printf printf.c
// ./print

