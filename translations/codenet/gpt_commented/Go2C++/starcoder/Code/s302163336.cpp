#include <bits/stdc++.h>

using namespace std;

int main() {
	// Read the number of elements (n) and the number of comparisons (m)
	int n, m;
	cin >> n >> m;

	// Create a vector to hold the heights and a vector to track which elements are "good"
	vector<int> h(n);
	vector<bool> good(n);

	// Read the heights and initialize the good vector to true
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		good[i] = true;
	}

	// Process each comparison
	for (int i = 0; i < m; i++) {
		int ai, bi;
		cin >> ai >> bi;
		ai--;
		bi--;

		// Compare the heights and update the good vector accordingly
		if (h[ai] > h[bi]) {
			good[bi] = false; // If ai is taller, bi is not "good"
		} else if (h[ai] < h[bi]) {
			good[ai] = false; // If bi is taller, ai is not "good"
		} else {
			// If heights are equal, mark both as not "good"
			good[ai] = false;
			good[bi] = false;
		}
	}

	// Count the number of "good" elements
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (good[i]) {
			ans++; // Increment count for each "good" element
		}
	}

	// Print the result: the number of "good" elements
	cout << ans << endl;
}

