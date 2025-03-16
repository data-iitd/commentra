#include <bits/stdc++.h>

using namespace std;

int main() {
	// Set the input stream splitter to split by whitespace
	cin.tie(0)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);

	// Read the number of integers
	int n; cin >> n;
	// Read the integers into a vector
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// Initialize the answer counter
	int ans = 0;

	// Iterate through the vector of integers
	for (int i = 0; i < n; i++) {
		// Set the left and right pointers for the current segment
		int l = i, r = i + 1;

		// Expand the right pointer while the conditions are met
		while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) r++;

		// Increment the answer for each segment found
		ans++;
		// Move the left pointer to the end of the current segment
		i = r;
	}

	// Output the final count of segments
	cout << ans << endl;
	// Flush the output stream to ensure all output is written
	cout.flush();
}

