#include<stdio.h>

// Declare two integer variables A and B
int main()
{
  int A, B;

  // Read the values of A and B from the standard input
  scanf("%d %d", &A, &B);

  // Declare an integer variable C and assign the sum of A and B to it
  int C = A + B;

  // Check if both A and B are not divisible by 3
  if(A%3 != 0 && B%3 != 0)
  {
    // Check if their sum C is also not divisible by 3
    if(C%3 != 0)
    {
      // If all conditions are met, print "Impossible" to the standard output
      printf("Impossible\n");
    }
    else
    {
      // Otherwise, print "Possible" to the standard output
      printf("Possible\n");
    }
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}
