#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// Define a custom scanner type for reading input efficiently.
class Scanner {
public:
    Scanner(istream& is) : is(is) {}

    int Int() {
        int n;
        is >> n;
        return n;
    }

    vector<int> IntVector(int l) {
        vector<int> sl(l);
        for (int i = 0; i < l; ++i) {
            is >> sl[i];
        }
        return sl;
    }

private:
    istream& is;
};

// Define the solve function to solve the problem.
int solve(int n, const vector<int>& heights) {
    // Initialize a table t to store the minimum cost to reach each index.
    vector<int> t(n + 1, INT_MAX);
    // Set the base case, the cost to reach index 0 is 0.
    t[0] = 0;

    // Iterate through the array from index 1 to n-1.
    for (int i = 1; i < n; ++i) {
        // Calculate the cost to reach index i from the previous index.
        int prevIndexCost = t[i - 1];
        // Update the cost to reach index i if the difference between heights is beneficial.
        int heightsDiff = heights[i] - heights[i - 1];
        prevIndexCost += (heightsDiff < 0) ? -heightsDiff : heightsDiff;

        // Update the cost to reach index i if the difference between previous index is beneficial.
        if (i > 1) {
            int prevPrevIndexCost = t[i - 2];
            heightsDiff = heights[i] - heights[i - 2];
            prevPrevIndexCost += (heightsDiff < 0) ? -heightsDiff : heightsDiff;

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
    // Initialize a scanner to read input from standard input.
    Scanner sc(cin);
    // Read the number of test cases.
    int n = sc.Int();
    for (int i = 0; i < n; ++i) {
        // Read the number of heights and initialize a vector to store them.
        vector<int> heights = sc.IntVector(n);
        // Call the solve function and print the result.
        int ans = solve(n, heights);
        cout << ans << endl;
    }
    return 0;
}
