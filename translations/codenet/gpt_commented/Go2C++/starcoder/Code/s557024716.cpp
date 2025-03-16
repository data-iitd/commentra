/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

#include <bits/stdc++.h>

using namespace std;

// Constants
const int MOD = 1000000007; // 10^9 + 7

// Function to generate all possible patterns of length k from the set {0, 1, 2, 3}
vector<vector<int>> DuplicatePatterns(int k) {
	vector<vector<int>> patterns; // Slice to hold all patterns
	vector<int> pattern; // Slice to hold a pattern

	// Generate all patterns of length k from the set {0, 1, 2, 3}
	for (int i = 0; i < 4; i++) {
		pattern.push_back(i); // Add the first element
		patterns.push_back(pattern); // Add the first pattern

		// Recursively generate patterns with the new element added
		patterns = DuplicatePatterns(patterns, pattern, k);
	}

	return patterns; // Return all generated patterns
}

// Recursive function to generate patterns
vector<vector<int>> DuplicatePatterns(vector<vector<int>> patterns, vector<int> pattern, int k) {
	if (pattern.size() == k) {
		return patterns; // Return the completed pattern
	}

	for (int i = 0; i < 4; i++) {
		pattern.push_back(i); // Add the new element

		// Recursively generate patterns with the new element added
		patterns.push_back(pattern);
		patterns = DuplicatePatterns(patterns, pattern, k);
	}

	return patterns; // Return all generated patterns
}

// Main function
int main() {
	// Read three integers and the number of patterns
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	// Generate all possible patterns of length k from the set {0, 1, 2, 3}
	vector<vector<int>> patterns = DuplicatePatterns(k);

	// Iterate through each generated pattern
	for (int i = 0; i < patterns.size(); i++) {
		int r = a, g = b, b = c; // Initialize color values for each pattern
		// Apply the pattern to modify the color values
		for (int j = 0; j < patterns[i].size(); j++) {
			if (patterns[i][j] == 0) {
				continue; // Skip if the pattern element is 0
			} else if (patterns[i][j] == 1) {
				r *= 2; // Double the red value
			} else if (patterns[i][j] == 2) {
				g *= 2; // Double the green value
			} else if (patterns[i][j] == 3) {
				b *= 2; // Double the blue value
			}
		}

		// Check if the modified values satisfy the condition
		if (g > r && b > g) {
			cout << "Yes" << endl; // Print "Yes" if the condition is met
			return 0;
		}
	}
	cout << "No" << endl; // Print "No" if no pattern satisfies the condition

	return 0;
}

