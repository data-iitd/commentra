#include <limits.h> // Include the limits header file for INT_MAX, etc.
#include <math.h>   // Include the math header file for mathematical functions.
#include <stdio.h>  // Include the standard input/output header file.
#include <stdlib.h> // Include the standard library header file.
#include <algorithm> // Include the algorithm header file for sorting and other utility functions.
#include <cfloat>    // Include the cfloat header file for floating-point constants.
#include <complex.h> // Include the complex header file for complex numbers.
#include <stdbool.h> // Include the stdbool header file for boolean types.
#include <stddef.h>  // Include the stddef header file for standard definitions.
#include <stdint.h>  // Include the stdint header file for fixed-width integers.
#include <stdio.h>   // Include the standard input/output header file again.

typedef long long ll; // Define a new type alias for long long integers.
typedef struct { // Define a new type alias for pairs of long long integers.
    ll first;
    ll second;
} P;

P* roads; // Declare a pointer to a vector of pairs named "roads".
P* qs;    // Declare a pointer to a vector of pairs named "qs".

int main() { // Start of the main function.
  ll N, X; // Declare two long long integers named "N" and "X".

  scanf("%lld %lld", &N, &X); // Read two integers from the standard input stream and assign them to "N" and "X" respectively.

  ll ans = 0; // Initialize an integer variable named "ans" to zero.
  ll min = 1000000000; // Initialize an integer variable named "min" to a large value.

  roads = (P*)malloc(N * sizeof(P)); // Allocate memory for the "roads" vector.
  qs = (P*)malloc(N * sizeof(P));    // Allocate memory for the "qs" vector.

  for (int i = 0; i < N; i++) { // Start of a for loop that iterates from 0 to N-1.
    ll tmp; // Declare a long long integer variable named "tmp".

    scanf("%lld", &tmp); // Read an integer from the standard input stream and assign it to "tmp".

    X -= tmp; // Subtract "tmp" from "X".
    ans++; // Increment "ans" by 1.

    roads[i].first = tmp; // Assign "tmp" to the first element of the "roads" vector.
    roads[i].second = i;  // Assign the index "i" to the second element of the "roads" vector.

    if (tmp < min) min = tmp; // If "tmp" is smaller than the current minimum value, update the minimum value.
  }

  ans += X / min; // Divide "X" by the minimum value and add the quotient to "ans".

  printf("%lld\n", ans); // Output the value of "ans" to the standard output stream.

  free(roads); // Free the allocated memory for the "roads" vector.
  free(qs);    // Free the allocated memory for the "qs" vector.

  return 0; // End of the main function with a return value of 0.
}
