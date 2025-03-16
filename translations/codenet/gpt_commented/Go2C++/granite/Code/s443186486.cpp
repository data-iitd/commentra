
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int combi(int n, int r) {
	int c = 1;
	// Calculate the combination using the formula C(n, r) = n! / (r! * (n - r)!)
	for (int i = 1; i <= r; i++) {
		c = c * (n - i + 1) / i;
	}
	return c; // Return the calculated combination
}

int main() {
	int n;
	cin >> n; // Read the number of elements

	vector<int> a(n);
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> s(n + 1);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i]; // Calculate cumulative sum
	}

	sort(s.begin(), s.end()); // Sort the prefix sum array

	int ans = 0;
	int count = 0;
	// Iterate through the sorted prefix sums to find duplicates
	for (int i = 0; i < n; i++) {
		if (s[i] == s[i + 1]) {
			count++; // Increment count if current and next sums are equal
		} else if (count > 0) {
			// If we found duplicates, calculate combinations and reset count
			ans += combi(count + 1, 2);
			count = 0; // Reset count for the next unique sum
		}
	}
	// Handle the case where the last sums were duplicates
	if (count > 0) {
		ans += combi(count + 1, 2);
	}

	// Output the total number of pairs of equal sums
	cout << ans << endl; // Output the total number of pairs of equal sums

	return 0;
}

// Translate the above C++ code to Java and end with comment "