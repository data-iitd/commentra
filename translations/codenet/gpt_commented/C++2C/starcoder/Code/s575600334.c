#include <stdio.h>

int main(void) {
  // Declare two unsigned integers to hold user input
  unsigned int a, b;
  
  // Read two unsigned integers from standard input
  scanf("%u %u", &a, &b);

  // Print the binary representation of the bitwise AND of a and b
  printf("%u\n", a & b);
  
  // Print the binary representation of the bitwise OR of a and b
  printf("%u\n", a | b);
  
  // Print the binary representation of the bitwise XOR of a and b
  printf("%u\n", a ^ b);
  
  // Return 0 to indicate successful execution
  return 0;
}
