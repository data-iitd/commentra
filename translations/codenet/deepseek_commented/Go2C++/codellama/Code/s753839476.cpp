
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// Main function: Reads input values, calculates the minimum difference, and prints the index.
int main() {
	ios::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams.
	cin.tie(NULL); // Disable flush on newlines for the cin stream.

	int n, t, a; // Declare variables for n, t, and a.
	cin >> n >> t >> a; // Read values for n, t, and a.

	vector<float> heights(n); // Declare a vector of floats for the heights.
	for (int i = 0; i < n; i++) { // Iterate through the heights.
		cin >> heights[i]; // Read a height.
	}

	float minDiff = abs(t - heights[0] * 0.006 - a); // Calculate the initial minimum difference.
	int minIdx = 0; // Initialize the index of the minimum difference.
	for (int i = 1; i < n; i++) { // Iterate through the heights starting from the second element.
		float diff = abs(t - heights[i] * 0.006 - a); // Calculate the difference for the current height.
		if (diff < minDiff) { // Update the minimum difference and index if a smaller difference is found.
			minDiff = diff;
			minIdx = i;
		}
	}
	cout << minIdx + 1 << endl; // Print the index (plus one for 1-based indexing).

	return 0;
}

