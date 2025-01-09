#include <stdio.h>

int main(void)
{
   unsigned int    A = -10;
   int             B = 5;
   unsigned int    C = 100;
   
   if(A > B)
   {
       printf("A > B\n");
   }
   else
   {
       printf("B > A\n");        
   }
   
   
   if(A > C)
   {
       printf("A > C\n");
   }
   else
   {
       printf("C > A\n");        
   }
   
   
   if(B > C)
   {
       printf("B > C\n");
   }
   else
   {
       printf("C > B\n");        
   }
   
  return 0;
}

// Predicited output:
// B > A
// C > A
// C > B

// Actual output:
// A > B
// A > C
// C > B

// Explanation
// Unsigned vs. Signed Conversion:

// When comparing an unsigned integer (A or C) with a signed integer (B), 
// the signed integer is converted to unsigned for the comparison.

// Unsigned integers are not allowed to be negative, so when C compiles
// it instead represents the binary value as a positive integer

// -10 is represented in binary using two's complement:

// Start with 10: 00000000 00000000 00000000 00001010.
// Invert all bits: 11111111 11111111 11111111 11110101.
// Add 1: 11111111 11111111 11111111 11110110.
// When stored in an unsigned int, 
// the binary pattern 11111111 11111111 11111111 11110110 is interpreted as:

// 2^32 − 10 = 4294967286

// This explains the output
// A > B = 4294967286 > 5
// A > C = 4294967286 > 100
// C > B = 100 > 5

