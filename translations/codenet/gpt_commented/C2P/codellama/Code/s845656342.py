#include <stdio.h>   # Include standard input-output library
#include <stdlib.h>  # Include standard library for general functions
#include <math.h>    # Include math library (not used in this code)

int main(void) # Main function where execution starts
{
  int x; # Declare an integer variable x

  # Read an integer value from user input and store it in x
  scanf("%d", &x);

  # Check if the value of x is equal to 1
  if(x == 1):
    printf("0\n"); # If x is 1, print "0"
  else:
    printf("1\n"); # If x is not 1, print "1"

  return 0; # Return 0 to indicate successful execution
}

