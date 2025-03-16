#include <stdio.h>  # Step 1: Include the standard input/output library to use printf and scanf functions.

def main ():  # Step 2: Define the main function where the execution of the program begins.
  A, B, C = 0, 0, 0  # Step 3: Declare three integer variables A, B, and C.

  scanf ("%d %d %d", &A, &B, &C)  # Step 4: Use scanf function to read three integers from the user and store them in variables A, B, and C.

  if (A < C and C < B):  # Step 5: Check if the value of C is between A and B using if-else statements.
    printf ("Yes\n")  # Print "Yes" if the condition is true.
  elif (A > C and C > B):  # Check if the value of C is between A and B using if-else statements.
    printf ("Yes\n")  # Print "Yes" if the condition is true.
  else:
    printf ("No\n")  # Print "No" if the condition is false.

