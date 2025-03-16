#include<stdio.h>

int main(void)
{
  // Declare two integer variables to hold user input
  int a, b;

  // Read the first integer from user input
  scanf("%d", &a);
  
  // Read the second integer from user input
  scanf("%d", &b);
  
  // Check if the product of a and b is even
  if((a * b) % 2 == 0) {
    // If the product is even, print "Even"
    printf("Even\n");
  } else {
    // If the product is odd, print "Odd"
    printf("Odd\n");
  }
  
  // Return 0 to indicate successful completion of the program
  return 0;
}

