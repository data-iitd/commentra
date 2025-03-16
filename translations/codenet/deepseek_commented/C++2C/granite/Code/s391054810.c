
#include <stdio.h>

int main()
{
  // Include the necessary header files for input and output operations
  int h, w, hh, ww;
  
  // Declare integer variables to store input values
  scanf("%d %d %d %d", &h, &w, &hh, &ww);
  
  // Read values from the standard input and store them in the variables
  printf("%d\n", (h-hh) * (w-ww));
  
  // Perform arithmetic operation to calculate the area of a rectangle
  // Output the result to the standard output
  return 0;
  
  // Indicate that the program ended successfully
}

