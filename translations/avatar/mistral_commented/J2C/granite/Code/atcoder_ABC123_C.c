

#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library
#include <math.h> // Including the mathematical library

int main() {

  // Reading the first integer input N
  int N;
  scanf("%d", &N);

  // Initializing the minimum integer variable with the first input value
  int min = 0;
  for (int i = 0; i < 5; i++) {
    if (i == 0) { // If it's the first iteration of the loop
      scanf("%d", &min); // Set the minimum value to the current input value
    } else { // Otherwise
      int temp;
      scanf("%d", &temp); // Read the current input value into a temporary variable
      min = (min < temp)? min : temp; // Update the minimum value with the current input value if it's smaller
    }
  }

  // Printing the answer using the printf function
  printf("%d\n", (int)ceil((double)N/min)+4);

  // Returning 0 to indicate successful program execution
  return 0;
}



Translate the above C code to Python and end with comment "