

#include <iostream> // Input/output stream for standard input/output
#include <vector> // Vector container for dynamic arrays
#include <unordered_map> // Hashmap for storing intermediate results
#include <algorithm> // Algorithms for sorting and searching
#include <numeric> // Numeric algorithms for accumulation and reduction
#include <functional> // Function objects for function composition
#include <iomanip> // Input/output manipulators for formatting output
#include <limits> // Constants for numeric limits
#include <cmath> // Mathematical functions and constants
#include <cassert> // Assertion macros for debugging
#include <string> // String container and algorithms
#include <cstring> // String manipulation functions
#include <cstdio> // File input/output functions
#include <cstdlib> // General-purpose functions
#include <ctime> // Time-related functions

using namespace std;

// Main function to start the program
int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization between C++ and C IO
    cin.tie(0); // Disable buffering for input stream

    int n, m; // Number of elements in array a and modulus value
    cin >> n >> m; // Read input

    vector<int> a(n); // Initialize array a
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read each element of array a
    }

    unordered_map<int, int> dp; // Hashmap to store intermediate results
    long long ans = 0; // Answer variable
    int base = 0; // Base value for hashmap key

    // Process each element in array a
    for (int i = 0; i < n; i++) {
        // Update base value
        base = (base - a[i] % m + m) % m;

        // Update hashmap with current base and its count
        dp[base + a[i] % m]++;

        // Update answer variable
        ans += dp[base];
    }

    // Print the answer
    cout << ans << endl; // Print the answer

    return 0; // Return success status
}

