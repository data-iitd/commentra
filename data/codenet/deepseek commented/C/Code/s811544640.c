#include <stdio.h>  // Step 1: Include necessary headers

int main(void) {  // Step 2: Define the main function
  int a, b, c;  // Step 3: Declare variables

  scanf("%d %d %d", &a, &b, &c);  // Step 4: Read input values

  if (b > a * c) {  // Step 5: Implement the if-else condition
    printf("%d\n", c);  // If true, print c
  } else {
    printf("%d\n", b / a);  // Otherwise, print b divided by a
  }

  return 0;  // Step 6: Return 0 to indicate successful execution
}