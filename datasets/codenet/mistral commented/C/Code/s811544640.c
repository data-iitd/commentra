
#include <stdio.h>

// Declare three integer variables 'a', 'b', and 'c'
int main(void) {
  int a, b, c;

  // Read three integers from the standard input using scanf()
  scanf("%d %d %d", &a, &b, &c);

  // Check if the condition 'b > a * c' is true
  if (b > a * c) {
    // If the condition is true, print the value of 'c'
    printf("%d\n", c);
  } else {
    // If the condition is false, calculate the integer division of 'b' by 'a'
    // and print the result
    printf("%d\n", b / a);
  }

  // Return 0 to indicate successful execution of the program
  return 0;
}