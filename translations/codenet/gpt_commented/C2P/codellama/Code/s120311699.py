#include<stdio.h>

int main():
  # Declare three integer variables to hold the input values
  a, b, c = 0, 0, 0

  # Read three integers from user input
  scanf("%d %d %d", &a, &b, &c)

  # Check if the first number is less than the second and the second is less than the third
  if(a < b and b < c):
    # If the condition is true, print "Yes"
    print("Yes\n")
  else:
    # If the condition is false, print "No"
    print("No\n")

  # Return 0 to indicate successful execution of the program
  return 0

