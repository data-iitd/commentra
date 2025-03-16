#include <stdio.h>

int main(void) {
  # Declare three integer variables a, b, and c
  a, b, c = int(input()), int(input()), int(input())

  # Check if b is greater than the product of a and c
  if b > a * c:
    # If true, print the value of c
    print(c)
  else:
    # If false, print the result of b divided by a
    print(b / a)

  # Return 0 to indicate successful execution of the program
  return 0
}

