#include <stdio.h>

int main(void){
  unsigned int a,b;
  scanf("%u %u", &a, &b);  // Read two unsigned integers from standard input

  printf("%u\n", a&b);  // Print the binary AND of a and b
  printf("%u\n", a|b);  // Print the binary OR of a and b
  printf("%u\n", a^b);  // Print the binary XOR of a and b
  
  return 0;
}

