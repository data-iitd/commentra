#include <stdio.h>

int main(void) {
  // Declare three integer variables a, b, and c
  int a, b, c;

  // Read three integers from user input
  scanf("%d %d %d", &a, &b, &c);

  // Check if b is greater than the product of a and c
  if (b > a * c) {
    // If true, print the value of c
    printf("%d\n", c);
  } else {
    // If false, print the result of b divided by a
    printf("%d\n", b / a);
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}
