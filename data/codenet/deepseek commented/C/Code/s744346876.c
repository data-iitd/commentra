#include <stdio.h> // Include the standard input/output header

int main(void){ // Define the main function
  int A, B; // Declare two integer variables A and B
  scanf("%d %d", &A, &B); // Read two integers from the user and store them in A and B
  if(A < 10 && B < 10) printf("%d\n", A * B); // Check if both A and B are less than 10, if true, print the multiplication result
  else printf("-1\n"); // If the condition is false, print -1
  return 0; // Return 0 to indicate successful execution
}
