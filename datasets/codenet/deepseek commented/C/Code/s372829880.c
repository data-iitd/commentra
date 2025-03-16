#include <stdio.h>  // Include the standard input/output library

int main(){  // Define the main function
  int x, a;  // Declare integer variables
  scanf("%d %d", &x, &a);  // Read input values
  printf("%d\n", (x >= a) * 10);  // Perform a comparison and multiplication, then print the result
  return 0;  // Return from main
}
