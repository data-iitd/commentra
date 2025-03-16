#include <bits/stdc++.h>

using namespace std;

// Block represents a contiguous segment of characters with a specific value and length.
struct Block {
	string Value; // The character value of the block
	int Len; // The length of the block
};

int main() {
	// Read input values for N (length of the string) and K (maximum number of '0's allowed)
	int N, K, ans = 0;
	cin >> N >> K;

	// Read the input string S
	string S;
	cin >> S;

	// Generate run-length encoded blocks from the input string S
	vector<Block> blocks = RunLength(S);

	// Initialize variables for the sliding window approach
	int sum = 0, zero = 0, l = 0;

	// Iterate through the blocks to find the maximum length of segments with at most K '0's
	for (int r = 0; r < blocks.size(); r++) {
		sum += blocks[r].Len; // Add the length of the current block to the sum

		// Count the number of '0' blocks encountered
		if (blocks[r].Value == "0") {
			zero++;
		}

		// If the count of '0' blocks exceeds K, shrink the window from the left
		while (K < zero) {
			sum -= blocks[l].Len; // Subtract the length of the leftmost block from the sum
			if (blocks[l].Value == "0") {
				zero--; // Decrease the count of '0' blocks
			}
			l++; // Move the left pointer to the right
		}

		// Update the answer with the maximum sum found so far
		ans = max(ans, sum);
	}

	// Print the maximum length of segments with at most K '0's
	cout << ans << endl;
}

// RunLength performs run-length encoding on the input string s and returns a slice of Block
vector<Block> RunLength(string s) {
	vector<Block> r; // Slice to hold the resulting blocks
	if (s.empty()) {
		return r; // Return empty slice if input string is empty
	}

	// Initialize the first block with the first character of the string
	Block t = {s[0], 1};
	for (int i = 1; i < s.length(); i++) {
		// If the current character matches the block's value, increase the length
		if (t.Value == s[i]) {
			t.Len++;
		} else {
			// Otherwise, append the current block to the result and start a new block
			r.push_back(t);
			t = {s[i], 1};
		}
	}
	// Append the last block to the result
	r.push_back(t);
	return r; // Return the slice of blocks
}

// Max returns the maximum of two integers
int Max(int a, int b) {
	if (b > a) {
		return b; // Return b if it is greater than a
	}
	return a; // Otherwise, return a
}

