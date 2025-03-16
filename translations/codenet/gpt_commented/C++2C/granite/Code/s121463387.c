
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
  // Declare variables for input number 'n' and current number 'x'
  int n, x;
  char s[100];

  // Read the upper limit 'n' from user input
  scanf("%d", &n);

  // Loop through numbers from 1 to n
  for(int i = 1; i <= n; i++){
    x = i; // Assign the current number to 'x'
    sprintf(s, "%d", x); // Convert 'x' to string for digit analysis

    // Check if 'x' is divisible by 3 or ends with the digit 3
    if(x % 3 == 0 || s[strlen(s)-1] == '3'){
      printf(" %d", i); // Print the number if condition is met
      continue; // Skip to the next iteration
    }
    else {
      // Get the number of digits in 'x'
      int k = strlen(s);
      // Loop through each digit of 'x' from the most significant to the least
      while(k > 0){
        k = k - 1; // Decrease the digit index
        int j = pow(10, k); // Calculate the place value for the current digit
        // Check if the current digit is 3
        if((x / j) % 10 == 3){
          printf(" %d", i); // Print the number if it contains the digit 3
          break; // Exit the loop as we found a 3
        }
      }
    }
  }
  
  printf("\n"); // Print a newline after all numbers are processed

  return 0; // Return success
}
