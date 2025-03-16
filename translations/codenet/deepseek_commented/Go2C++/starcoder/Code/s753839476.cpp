#include <bits/stdc++.h>

using namespace std;

// Main function: Reads input values, calculates the minimum difference, and prints the index.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, t, a; cin >> n >> t >> a; // Read values for n, t, and a.
	vector<double> heights(n); // Read a list of heights.
	for (int i = 0; i < n; i++) cin >> heights[i];

	double minDiff = abs(t - heights[0] * 0.006); // Calculate the initial minimum difference.
	int minIdx = 0; // Initialize the index of the minimum difference.
	for (int i = 1; i < n; i++) { // Iterate through the heights starting from the second element.
		double diff = abs(t - heights[i] * 0.006); // Calculate the difference for the current height.
		if (diff < minDiff) { // Update the minimum difference and index if a smaller difference is found.
			minDiff = diff;
			minIdx = i;
		}
	}
	cout << minIdx + 1 << endl; // Print the index (plus one for 1-based indexing).
}

