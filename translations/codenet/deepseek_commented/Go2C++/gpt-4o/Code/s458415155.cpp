//go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a"
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate the minimum cost to reach the last stone using dynamic programming.
int solve(int n, const vector<int>& heights) {
    // Initialize the minimum cost array with a large value.
    vector<int> t(n + 1, numeric_limits<int>::max());
    
    // The cost to reach the first stone is 0.
    t[0] = 0;

    // Calculate the minimum cost to reach each stone.
    for (int i = 1; i < n; i++) {
        // Cost to reach the current stone from the previous stone.
        t[i] = min(t[i], t[i - 1] + abs(heights[i] - heights[i - 1]));
        
        // Cost to reach the current stone from two stones back (if possible).
        if (i > 1) {
            t[i] = min(t[i], t[i - 2] + abs(heights[i] - heights[i - 2]));
        }
    }

    // Return the minimum cost to reach the last stone.
    return t[n - 1];
}

// Main function reads input, calls the solve function, and prints the result.
int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int ans = solve(n, heights);
    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
