#include <limits.h> // Include header for limit values
#include <math.h>   // Include header for mathematical functions
#include <stdio.h>  // Include header for standard input/output functions
#include <stdlib.h> // Include header for general utilities
#include <algorithm> // Include header for standard algorithms
#include <cfloat>    // Include header for floating-point limits
#include <complex>   // Include header for complex number operations
#include <functional> // Include header for functional programming
#include <iostream>  // Include header for input/output streams
#include <map>       // Include header for associative arrays
#include <queue>     // Include header for queue operations
#include <set>       // Include header for set operations
#include <stack>     // Include header for stack operations
#include <string>    // Include header for string operations
#include <unordered_map> // Include header for unordered associative arrays
#include <vector>    // Include header for vector operations

using namespace std; // Use the standard namespace

typedef long long ll; // Define a type alias for long long
typedef unsigned long long ull; // Define a type alias for unsigned long long
typedef pair<ll, ll> P; // Define a type alias for a pair of long long

vector<vector<ll> > table; // Declare a 2D vector of long long
vector<P> roads; // Declare a vector of pairs
vector<P> qs; // Declare a vector of pairs

int main() { // Define the main function
  ll N, X; // Declare variables to store the number of elements and the target value
  cin >> N >> X; // Read the values of N and X from the standard input

  ll ans = 0; // Initialize the answer variable
  ll min = 1000000000; // Initialize the minimum value variable
  for (int i = 0; i < N; i++) { // Loop through N elements
    ll tmp; // Declare a temporary variable to store each input value
    cin >> tmp; // Read the value into the temporary variable
    X -= tmp; // Subtract the value from X
    ans++; // Increment the answer count
    if (tmp < min) min = tmp; // Update the minimum value if the current value is smaller
  }

  ans += X / min; // Calculate the final answer by adding the quotient of X divided by the minimum value

  cout << ans << endl; // Print the final answer to the standard output

  return 0; // Return 0 to indicate successful execution
}

