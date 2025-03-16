#include <stdio.h>

# Declare three integer variables A, B, and C
int main (void) {
  int A, B, C;

  # Read three integers from the standard input using scanf function
  scanf ("%d %d %d", &A, &B, &C);

  # Check if A is less than C and C is less than B
  if (A < C and C < B):
    # If condition is true, print "Yes" to the standard output
    print ("Yes\n");

  # Else if condition checks if A is greater than C and C is greater than B
  elif (A > C and C > B):
    # If condition is true, print "Yes" to the standard output
    print ("Yes\n");

  # Else condition is executed when neither first nor second condition is true
  else:
    # If condition is false, print "No" to the standard output
    print ("No\n");
} # End of main function

