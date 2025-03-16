// Package main is the entry point of the program
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize scanner, reader, and writer
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Initialize answer variable
	int ans = 0;

	// Read the number of elements in the array 'a'
	int n;
	cin >> n;

	// Read the array 'a'
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Iterate through the array 'a'
	for (int i = 0; i < n; i++) {
		// Initialize left and right indices
		int l = i, r = i+1;

		// Use a while loop to find the next index 'r' such that the difference between 'a[r]' and 'a[l]' is negative
		while (r+1 < n && (a[r]-a[l])*(a[r+1]-a[r]) >= 0) {
			r++;
		}

		// Increment the answer variable
		ans++;

		// Update the index 'i' to 'r' for the next iteration
		i = r;
	}

	// Print the answer
	cout << ans << endl;

	return 0;
}

