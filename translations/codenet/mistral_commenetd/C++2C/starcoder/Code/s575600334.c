#include <stdio.h>

int main(void){
  // Declare unsigned integer variables a and b
  unsigned int a, b;

  // Read integer values of a and b from the standard input
  scanf("%u %u", &a, &b);

  // Print binary representation of bitwise AND of a and b
  printf("%u\n", a & b);

  // Print binary representation of bitwise OR of a and b
  printf("%u\n", a | b);

  // Print binary representation of bitwise XOR of a and b
  printf("%u\n", a ^ b);

  // Return 0 to indicate successful execution of the program
  return 0;
}
