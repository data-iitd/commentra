
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Generate all possible patterns of length k from the given array [0, 1, 2, 3]
vector<vector<int>> DuplicatePatterns(vector<int> elems, int k) {
	return dupliRec(vector<int>(), elems, k);
}

// DFS function for DuplicatePatterns
vector<vector<int>> dupliRec(vector<int> pattern, vector<int> elems, int k) {
	if (pattern.size() == k) {
		// Return the generated pattern as a slice
		return vector<vector<int>>{pattern};
	}

	vector<vector<int>> res;
	for (int e : elems) {
		// Create a new pattern by appending the current element to the current pattern
		vector<int> newPattern = pattern;
		newPattern.push_back(e);

		// Recursively call the function with the new pattern and the remaining elements
		vector<vector<int>> subPatterns = dupliRec(newPattern, elems, k);

		// Append the sub-patterns to the result
		res.insert(res.end(), subPatterns.begin(), subPatterns.end());
	}

	return res;
}

int main() {
	// Read input values
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	// Generate all possible patterns of length k from the given array [0, 1, 2, 3]
	vector<vector<int>> patterns = DuplicatePatterns(vector<int>{0, 1, 2, 3}, k);

	// Check each generated pattern
	for (vector<int> P : patterns) {
		// Apply bitwise operation to RGB values of the given input
		int r = a, g = b, b = c;
		for (int i = 0; i < P.size(); i++) {
			if (P[i] == 0) {
				continue;
			} else if (P[i] == 1) {
				r *= 2;
			} else if (P[i] == 2) {
				g *= 2;
			} else if (P[i] == 3) {
				b *= 2;
			}
		}

		// Check if the result satisfies the condition g > r and b > g
		if (g > r && b > g) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	// If all patterns are checked and no satisfying pattern is found, print "No"
	cout << "No" << endl;

	return 0;
}

