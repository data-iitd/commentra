
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// iabs returns the absolute value of an integer.
int iabs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// solve calculates the minimum cost to reach the last stone using dynamic programming.
int solve(int n, vector<int> heights) {
	// Initialize the minimum cost array with a large value.
	vector<int> t(n+1, 1000000000);

	// The cost to reach the first stone is 0.
	t[0] = 0;

	// Calculate the minimum cost to reach each stone.
	for (int i = 1; i < n; i++) {
		// Cost to reach the current stone from the previous stone.
		if (t[i-1] + iabs(heights[i]-heights[i-1]) < t[i]) {
			t[i] = t[i-1] + iabs(heights[i]-heights[i-1]);
		}
		// Cost to reach the current stone from two stones back (if possible).
		if (1 < i) {
			if (t[i-2] + iabs(heights[i]-heights[i-2]) < t[i]) {
				t[i] = t[i-2] + iabs(heights[i]-heights[i-2]);
			}
		}
	}

	// Return the minimum cost to reach the last stone.
	return t[n-1];
}

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

