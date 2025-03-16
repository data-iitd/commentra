#include <stdio.h>  // Include the standard input/output library

int main() {  // Define the main function
  long long int a, b, c;  // Declare variables to store the input values
  scanf("%lld %lld %lld", &a, &b, &c);  // Read three long long integers from the user

  long long int d = c - a - b;  // Calculate the difference between c and the sum of a and b
  if ((d > 0) && ((4 * a * b) < d * d))  // Check if the difference is positive and satisfies the specific condition
    printf("Yes\n");  // Print "Yes" if the condition is met
  else
    printf("No\n");  // Print "No" otherwise

  return 0;  // Return 0 to indicate successful program termination
}
