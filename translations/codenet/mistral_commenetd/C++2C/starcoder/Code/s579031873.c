#include <limits.h> // Include the limits header file for INT_MAX, etc.
#include <math.h>   // Include the math header file for mathematical functions.
#include <stdio.h>  // Include the standard input/output header file.
#include <stdlib.h> // Include the standard library header file.
#include <algorithm> // Include the algorithm header file for sorting and other utility functions.
#include <cfloat>    // Include the cfloat header file for floating-point constants.
#include <complex>   // Include the complex header file for complex numbers.
#include <functional> // Include the functional header file for function objects.
#include <iostream>  // Include the iostream header file for input/output streams.
#include <map>       // Include the map header file for associative arrays.
#include <queue>     // Include the queue header file for FIFO queues.
#include <set>       // Include the set header file for sets.
#include <stack>     // Include the stack header file for LIFO stacks.
#include <string>    // Include the string header file for strings.
#include <unordered_map> // Include the unordered_map header file for hash-based associative arrays.
#include <vector>    // Include the vector header file for dynamic arrays.

using namespace std; // Use the standard namespace for convenience.

typedef long long ll; // Define a new type alias for long long integers.
typedef unsigned long long ull; // Define a new type alias for unsigned long long integers.
typedef pair<ll, ll> P;   // Define a new type alias for pairs of long long integers.

vector<vector<ll> > table; // Declare a 2D vector named "table".
vector<P> roads;          // Declare a vector of pairs named "roads".
vector<P> qs;            // Declare a vector of pairs named "qs".

int main() { // Start of the main function.
  ll N, X; // Declare two long long integers named "N" and "X".

  scanf("%lld %lld", &N, &X); // Read two integers from the standard input stream and assign them to "N" and "X" respectively.

  ll ans = 0; // Initialize an integer variable named "ans" to zero.
  ll min = 1000000000; // Initialize an integer variable named "min" to a large value.

  for (int i = 0; i < N; i++) { // Start of a for loop that iterates from 0 to N-1.
    ll tmp; // Declare a long long integer variable named "tmp".

    scanf("%lld", &tmp); // Read an integer from the standard input stream and assign it to "tmp".

    X -= tmp; // Subtract "tmp" from "X".
    ans++; // Increment "ans" by 1.

    if (tmp < min) min = tmp; // If "tmp" is smaller than the current minimum value, update the minimum value.
  }

  ans += X / min; // Divide "X" by the minimum value and add the quotient to "ans".

  printf("%lld\n", ans); // Output the value of "ans" to the standard output stream.

  return 0; // End of the main function with a return value of 0.
}

