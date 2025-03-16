#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // Declare variables to store input and intermediate results
  int n, x;
  char s[10];

  // Read the value of n from standard input
  scanf("%d", &n);

  // Loop through numbers from 1 to n
  for(int i = 1; i <= n; i++) {
    // Initialize x with the current number i and convert it to a string
    x = i;
    sprintf(s, "%d", x);

    // Check if the number is divisible by 3 or ends with 3
    if(x % 3 == 0 || x % 10 == 3) {
      printf(" %d", i); // Output the number if the condition is met
      continue;
    } else {
      // Check each digit of the number to see if it contains 3
      int k = strlen(s);
      while(k > 0) {
        k = k - 1;
        int j = pow(10, k);
        if((x / j) % 10 == 3) {
          printf(" %d", i); // Output the number if '3' is found in any digit
          break;
        }
      }
    }
  }

  // Output a newline character at the end of the program
  printf("\n");

  return 0;
}
