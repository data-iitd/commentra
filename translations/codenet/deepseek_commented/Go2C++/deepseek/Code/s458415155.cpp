#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Function to read integers from standard input.
vector<int> readInts(int n) {
    vector<int> ints(n);
    for (int i = 0; i < n; ++i) {
        cin >> ints[i];
    }
    return ints;
}

// Function to calculate the minimum cost to reach the last stone using dynamic programming.
int solve(int n, const vector<int>& heights) {
    // Initialize the minimum cost array with a large value.
    vector<int> t(n, INT_MAX);

    // The cost to reach the first stone is 0.
    t[0] = 0;

    // Calculate the minimum cost to reach each stone.
    for (int i = 1; i < n; ++i) {
        // Cost to reach the current stone from the previous stone.
        if (t[i-1] + abs(heights[i] - heights[i-1]) < t[i]) {
            t[i] = t[i-1] + abs(heights[i] - heights[i-1]);
        }
        // Cost to reach the current stone from two stones back (if possible).
        if (i > 1 && t[i-2] + abs(heights[i] - heights[i-2]) < t[i]) {
            t[i] = t[i-2] + abs(heights[i] - heights[i-2]);
        }
    }

    // Return the minimum cost to reach the last stone.
    return t[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights = readInts(n);
    int ans = solve(n, heights);
    cout << ans << endl;
    return 0;
}

