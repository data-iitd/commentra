#include <stdio.h>  // Include header for standard input/output functions
#include <stdlib.h> // Include header for general utilities
#include <limits.h> // Include header for limit values
#include <math.h>   // Include header for mathematical functions
#include <algorithm> // Include header for standard algorithms
#include <cfloat>    // Include header for floating-point limits
#include <complex.h> // Include header for complex number operations
#include <stdbool.h> // Include header for boolean types
#include <stddef.h>  // Include header for standard definitions
#include <stdint.h>  // Include header for fixed-width integers
#include <stdio.h>   // Include header for standard input/output functions
#include <stdlib.h>  // Include header for general utilities
#include <string.h>  // Include header for string operations

typedef long long ll; // Define a type alias for long long
typedef struct { // Define a type alias for a pair of long long
  ll first;
  ll second;
} P;

#define MAX_N 100000 // Define a constant for the maximum number of elements
#define MAX_X 1000000000 // Define a constant for the maximum target value

ll table[MAX_N][MAX_N]; // Declare a 2D array of long long
P roads[MAX_N]; // Declare a array of pairs
P qs[MAX_N]; // Declare a array of pairs

int main() { // Define the main function
  ll N, X; // Declare variables to store the number of elements and the target value
  scanf("%lld %lld", &N, &X); // Read the values of N and X from the standard input

  ll ans = 0; // Initialize the answer variable
  ll min = MAX_X; // Initialize the minimum value variable
  for (int i = 0; i < N; i++) { // Loop through N elements
    ll tmp; // Declare a temporary variable to store each input value
    scanf("%lld", &tmp); // Read the value into the temporary variable
    X -= tmp; // Subtract the value from X
    ans++; // Increment the answer count
    if (tmp < min) min = tmp; // Update the minimum value if the current value is smaller
  }

  ans += X / min; // Calculate the final answer by adding the quotient of X divided by the minimum value

  printf("%lld\n", ans); // Print the final answer to the standard output

  return 0; // Return 0 to indicate successful execution
}
