#include <stdio.h>

// Declare three integer variables A, B, and C
int main (void) {
  int A, B, C;

  // Read three integers from the standard input using scanf function
  scanf ("%d %d %d", &A, &B, &C);

  // Check if A is less than C and C is less than B
  if (A < C && C < B) {
    // If condition is true, print "Yes" to the standard output
    printf ("Yes\n");
  } // End of first if block

  // Else if condition checks if A is greater than C and C is greater than B
  else if (A > C && C > B) {
    // If condition is true, print "Yes" to the standard output
    printf ("Yes\n");
  } // End of second if block

  // Else condition is executed when neither first nor second condition is true
  else {
    // If condition is false, print "No" to the standard output
    printf ("No\n");
  } // End of else block
} // End of main function