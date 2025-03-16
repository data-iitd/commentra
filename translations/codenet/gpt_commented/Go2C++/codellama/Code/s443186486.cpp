
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read the number of elements
	int n;
	cin >> n;

	// Initialize a vector to hold the input integers
	vector<int> a(n);
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Create a prefix sum array to store cumulative sums
	vector<int> s(n+1);
	for (int i = 0; i < n; i++) {
		s[i+1] = s[i] + a[i]; // Calculate cumulative sum
	}

	// Sort the prefix sum array
	sort(s.begin(), s.end());

	// Initialize variables to count pairs of equal sums
	int ans = 0;
	int count = 0;
	// Iterate through the sorted prefix sums to find duplicates
	for (int i = 0; i < n; i++) {
		if (s[i] == s[i+1]) {
			count++; // Increment count if current and next sums are equal
		} else if (count > 0) {
			// If we found duplicates, calculate combinations and reset count
			ans += combi(count+1, 2);
			count = 0; // Reset count for the next unique sum
		}
	}
	// Handle the case where the last sums were duplicates
	if (count > 0) {
		ans += combi(count+1, 2);
	}

	// Output the total number of pairs of equal sums
	cout << ans << endl;

	return 0;
}

// Function to calculate combinations C(n, r)
int combi(int n, int r) {
	int c = 1;
	// Calculate the combination using the formula C(n, r) = n! / (r! * (n - r)!)
	for (int i = 1; i <= r; i++) {
		c = c * (n - i + 1) / i;
	}
	return c; // Return the calculated combination
}

