
#include <stdio.h>

// Declare the main function
int main(){
  // Declare and initialize two integer variables, x and a
  int x, a;

  // Read data from the standard input stream and store it into x and a
  scanf("%d %d", &x, &a);

  // Check if x is greater than or equal to a
  int result = (x >= a);

  // Multiply the result by 10
  result *= 10;

  // Print the result to the standard output stream
  printf("%d\n", result);

  // Return 0 to indicate successful execution
  return 0;
}