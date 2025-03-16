
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Define a helper function for calculating absolute value.
int iabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// Define the solve function to solve the problem.
int solve(int n, vector<int> heights) {
    // Initialize a table t to store the minimum cost to reach each index.
    vector<int> t(n + 1, INT_MAX);
    // Set the initial value of the table to maximum integer.
    for (int i = 0; i < n + 1; i++) {
        t[i] = INT_MAX;
    }
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
            if (prevIndexCost < t[i]) {
                t[i] = prevIndexCost;
            }
            if (prevPrevIndexCost < t[i]) {
                t[i] = prevPrevIndexCost;
            }
        } else {
            // If the difference between previous index is not valid, only update the cost if the current difference is beneficial.
            if (prevIndexCost < t[i]) {
                t[i] = prevIndexCost;
            }
        }
    }

    // Return the minimum cost to reach the last index.
    return t[n - 1];
}

// Define the main function to read input and call the solve function.
int main() {
    // Read the number of test cases and iterate through each test case.
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // Read the number of heights and initialize an array to store them.
        vector<int> heights(n);
        for (int j = 0; j < n; j++) {
            cin >> heights[j];
        }
        // Call the solve function and print the result.
        cout << solve(n, heights) << endl;
    }
    return 0;
}

