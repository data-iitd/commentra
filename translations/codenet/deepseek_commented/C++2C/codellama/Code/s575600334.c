#include <stdio.h>

// Function to print the binary representation of an integer x with a specified number of bits
void binPrint(unsigned x, int bits){
  for (int i=bits-1; i>=0; i--){
    printf("%d", x&(1<<i)?1:0);
  }
  printf("\n");
}

int main(void){
  unsigned a,b;
  scanf("%u %u", &a, &b);  // Read two unsigned integers from standard input

  binPrint(a&b, 32);  // Print the binary AND of a and b
  binPrint(a|b, 32);  // Print the binary OR of a and b
  binPrint(a^b, 32);  // Print the binary XOR of a and b
  
  return 0;
}

