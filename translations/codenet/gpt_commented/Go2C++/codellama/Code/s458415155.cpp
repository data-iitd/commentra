
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// iabs returns the absolute value of an integer.
int iabs(int x) {
    if (x < 0) {
        return -x; // Return the negation if x is negative.
    }
    return x; // Return x if it is non-negative.
}

// solve computes the minimum cost to reach the last height using dynamic programming.
int solve(int n, vector<int> heights) {
    vector<int> t(n+1, INT_MAX); // Create a vector to store minimum costs.
    t[0] = 0; // The cost to reach the first height is zero.
    for (int i = 1; i < n; i++) {
        // Calculate the cost to reach the current height from the previous height.
        if (t[i-1] + iabs(heights[i]-heights[i-1]) < t[i]) {
            t[i] = t[i-1] + iabs(heights[i]-heights[i-1]); // Update the cost if it's lower.
        }
        // Calculate the cost to reach the current height from two heights back.
        if (1 < i) {
            if (t[i-2] + iabs(heights[i]-heights[i-2]) < t[i]) {
                t[i] = t[i-2] + iabs(heights[i]-heights[i-2]); // Update the cost if it's lower.
            }
        }
    }

    return t[n-1]; // Return the minimum cost to reach the last height.
}

int main() {
    int n; // The number of heights.
    cin >> n; // Read the number of heights.
    vector<int> heights(n); // Create a vector to store the heights.
    for (int i = 0; i < n; i++) {
        cin >> heights[i]; // Read the heights into the vector.
    }
    int ans = solve(n, heights); // Solve for the minimum cost.
    cout << ans << endl; // Print the result.
    return 0;
}

