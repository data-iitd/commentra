// Importing necessary headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Constants and variables declaration
const long long inf = 1e14;

// Function to read an integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Main function
int main() {
    // Reading input
    int n = readInt();
    int x = readInt();

    // Initializing arrays
    vector<int> a(n);
    vector<int> v(n, 0);

    // Initializing answer variable
    long long ans = inf;

    // Iterating through all possible subarrays
    for (int k = 0; k < n; k++) {
        // Initializing variable to store sum of subarray elements
        long long kans = 0;

        // Iterating through all elements of the subarray
        for (int i = 0; i < n; i++) {
            // Checking if current index is out of bounds for subarray
            if (i - k < 0) {
                // Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i - k]);
            }

            // Adding current element to the sum of subarray
            kans += v[i];
        }

        // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans + k * x);
    }

    // Printing the answer
    cout << ans << endl;

    return 0;
}

// Helper functions
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to check if a given number is inside a given range
bool in(int c, int a, int z) {
    return c >= a && c < z;
}

// Function to convert boolean value to integer
int btoi(bool b) {
    return b ? 1 : 0;
}

// Function to convert integer value to boolean
bool itob(int a) {
    return a != 0;
}

// <END-OF-CODE>
