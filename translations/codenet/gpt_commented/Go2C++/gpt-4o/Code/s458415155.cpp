// https://atcoder.jp/contests/dp/tasks/dp_a
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to compute the minimum cost to reach the last height using dynamic programming.
int solve(int n, const vector<int>& heights) {
    vector<int> t(n, numeric_limits<int>::max()); // Create a vector to store minimum costs.
    t[0] = 0; // The cost to reach the first height is zero.

    for (int i = 1; i < n; ++i) {
        // Calculate the cost to reach the current height from the previous height.
        t[i] = min(t[i], t[i - 1] + abs(heights[i] - heights[i - 1]));
        // Calculate the cost to reach the current height from two heights back.
        if (i > 1) {
            t[i] = min(t[i], t[i - 2] + abs(heights[i] - heights[i - 2]));
        }
    }

    return t[n - 1]; // Return the minimum cost to reach the last height.
}

// Main function to execute the program.
int main() {
    int n;
    cin >> n; // Read the number of heights.
    vector<int> heights(n); // Create a vector to store the heights.
    for (int i = 0; i < n; ++i) {
        cin >> heights[i]; // Read the heights into the vector.
    }
    int ans = solve(n, heights); // Solve for the minimum cost.
    cout << ans << endl; // Print the result.
    return 0;
}

// <END-OF-CODE>
