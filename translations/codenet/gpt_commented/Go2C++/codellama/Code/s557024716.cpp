
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to generate all possible patterns of length k from the given elements.
vector<vector<int>> DuplicatePatterns(vector<int> elems, int k) {
	vector<vector<int>> res; // Slice to hold the results
	if (k == 0) {
		res.push_back(vector<int>()); // Add an empty pattern
		return res; // Return the empty pattern
	}

	for (int i = 0; i < elems.size(); i++) {
		int e = elems[i]; // Get the current element
		vector<vector<int>> new_res = DuplicatePatterns(elems, k - 1); // Recursively generate patterns with the new element added
		for (int j = 0; j < new_res.size(); j++) {
			new_res[j].push_back(e); // Add the new element to each pattern
		}
		res.insert(res.end(), new_res.begin(), new_res.end()); // Add the new patterns to the result
	}

	return res; // Return all generated patterns
}

int main() {
	int a, b, c, k; // Variables to hold input values
	cin >> a >> b >> c >> k; // Read three integers and the number of patterns

	vector<int> elems = {0, 1, 2, 3}; // Set of elements to generate patterns from
	vector<vector<int>> patterns = DuplicatePatterns(elems, k); // Generate all possible patterns of length k from the set {0, 1, 2, 3}

	// Iterate through each generated pattern
	for (int i = 0; i < patterns.size(); i++) {
		int r = a, g = b, b = c; // Initialize color values for each pattern
		vector<int> P = patterns[i]; // Get the current pattern
		// Apply the pattern to modify the color values
		for (int j = 0; j < P.size(); j++) {
			if (P[j] == 0) {
				continue; // Skip if the pattern element is 0
			} else if (P[j] == 1) {
				r *= 2; // Double the red value
			} else if (P[j] == 2) {
				g *= 2; // Double the green value
			} else if (P[j] == 3) {
				b *= 2; // Double the blue value
			}
		}

		// Check if the modified values satisfy the condition
		if (g > r && b > g) {
			cout << "Yes" << endl; // Print "Yes" if the condition is met
			return 0; // Return 0
		}
	}
	cout << "No" << endl; // Print "No" if no pattern satisfies the condition

	return 0; // Return 0
}

