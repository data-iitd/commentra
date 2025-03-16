#include <stdio.h>

int main (void) {
  // Declare three integer variables A, B, and C
  int A, B, C;

  // Read three integers from user input and store them in A, B, and C
  scanf ("%d %d %d", &A, &B, &C);

  # Check if C is between A and B (A < C < B)
  if (A < C and C < B):
    # If true, print "Yes"
    print ("Yes\n");
  # Check if C is between B and A (A > C > B)
  elif (A > C and C > B):
    # If true, print "Yes"
    print ("Yes\n");
  # If neither condition is met, print "No"
  else:
    print ("No\n");
}

