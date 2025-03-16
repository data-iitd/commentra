// This line is a Go generate command to download the problem statement from AtCoder.
// It is not necessary to understand its functionality for the given code.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Define a helper function for calculating absolute value.
int iabs(int x) {
    return (x < 0) ? -x : x;
}

// Define the main function to solve the problem.
int solve(int n, const vector<int>& heights) {
    // Initialize a table t to store the minimum cost to reach each index.
    vector<int> t(n + 1, numeric_limits<int>::max());
    // Set the base case, the cost to reach index 0 is 0.
    t[0] = 0;

    // Iterate through the array from index 1 to n-1.
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach index i from the previous index.
        int prevIndexCost = t[i - 1];
        // Update the cost to reach index i if the difference between heights is beneficial.
        if (heights[i] - heights[i - 1] < 0) {
            prevIndexCost += heights[i] - heights[i - 1];
        } else {
            prevIndexCost -= heights[i] - heights[i - 1];
        }
        // Update the cost to reach index i if the difference between previous index is beneficial.
        if (i - 2 >= 0) {
            int prevPrevIndexCost = t[i - 2];
            if (heights[i] - heights[i - 2] < 0) {
                prevPrevIndexCost += heights[i] - heights[i - 2];
            } else {
                prevPrevIndexCost -= heights[i] - heights[i - 2];
            }
            t[i] = min(t[i], prevIndexCost);
            t[i] = min(t[i], prevPrevIndexCost);
        } else {
            // If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
            t[i] = min(t[i], prevIndexCost);
        }
    }

    // Return the minimum cost to reach the last index.
    return t[n - 1];
}

// Define the main function to read input and call the solve function.
int main() {
    // Read the number of test cases.
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // Read the number of heights and initialize a vector to store them.
        int m;
        cin >> m;
        vector<int> heights(m);
        for (int j = 0; j < m; j++) {
            cin >> heights[j];
        }
        // Call the solve function and print the result.
        int ans = solve(m, heights);
        cout << ans << endl;
    }
}

// <END-OF-CODE>
