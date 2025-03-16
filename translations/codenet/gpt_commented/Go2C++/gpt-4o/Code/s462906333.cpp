#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Define a large constant for infinity
const long long inf = 1e14;

// Function to get the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    return min(min(a, b), c);
}

// Main function
int main() {
    // Read the number of elements and the value of x
    int n, x;
    cin >> n >> x;

    // Create a vector to hold the input integers
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Create a copy of the vector a for manipulation
    vector<int> v = a;

    // Initialize the answer to infinity
    long long ans = inf;

    // Iterate over each possible k value
    for (int k = 0; k < n; k++) {
        long long kans = 0; // Initialize the current answer for this k

        // Calculate the minimum values for the current k
        for (int i = 0; i < n; i++) {
            if (i - k < 0) {
                // If i-k is out of bounds, use the wrapped index
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Otherwise, use the normal index
                v[i] = min(v[i], a[i - k]);
            }
            // Accumulate the current answer
            kans += v[i];
        }

        // Update the overall answer with the minimum found so far
        ans = min(ans, kans + k * x);
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
