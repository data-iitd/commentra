
#include <stdio.h>

// Function to print binary representation of a number
void binPrint(int x, int bits){
  // Iterate through each bit starting from the last one
  for (int i = bits - 1; i >= 0; i--){
    // Print the bit value based on the bitwise AND operation with the mask (1<<i)
    printf("%d", (x & (1<<i)? 1 : 0));
  }
  // Print newline character after printing the binary number
  printf("\n");
}

int main(void){
  // Declare unsigned integer variables a and b
  unsigned int a, b;

  // Read integer values of a and b from the standard input
  scanf("%u %u", &a, &b);

  // Print binary representation of bitwise AND of a and b
  binPrint(a & b, 32);

  // Print binary representation of bitwise OR of a and b
  binPrint(a | b, 32);

  // Print binary representation of bitwise XOR of a and b
  binPrint(a ^ b, 32);

  // Return 0 to indicate successful execution of the program
  return 0;
}
