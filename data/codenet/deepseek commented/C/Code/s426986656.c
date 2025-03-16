#include <stdio.h>  // Include the standard input/output library

int main(void) {
  int A, B, flag = 0;  // Declare integer variables A, B, and flag
  scanf("%d %d", &A, &B);  // Read input values for A and B

  // Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
  for(int i=1; i<=3; ++i) {
    if((A*B*i)%2 == 1) {  // Check if the product is odd
      flag = 1;  // Set flag to 1 if an odd product is found
      break;  // Break out of the loop
    }
  }

  if(flag) printf("Yes\n");  // Print "Yes" if an odd product was found
  else printf("No\n");  // Print "No" if no odd product was found

  return 0;  // Return 0 to indicate successful execution
}