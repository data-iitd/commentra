
// Importing required packages
#include <bits/stdc++.h>

using namespace std;

// Define a custom type 'Block'
struct Block {
	string Value;
	int Len;
};

// Main function starts the execution
int main() {
	// Initialize variables
	int N, K, ans = 0;

	// Read input values for N and K from the standard input
	cin >> N >> K;

	// Initialize a buffer scanner for reading input from the standard input
	string S;
	cin.ignore();
	getline(cin, S);

	// Call the RunLength function to get the run-length encoded blocks
	vector<Block> blocks = RunLength(S);

	// Initialize variables sum, zero and length l
	int sum = 0, zero = 0, l = 0;

	// Loop through all the blocks in the blocks slice
	for (int r = 0; r < blocks.size(); r++) {
		// Increment the sum by the length of the current block
		sum += blocks[r].Len;

		// If the current block's value is '0', increment the zero counter
		if (blocks[r].Value == "0") {
			zero++;
		}

		// While the zero counter is greater than K, subtract the length of the previous block from the sum and decrement the zero counter
		while (K < zero) {
			sum -= blocks[l].Len;
			if (blocks[l].Value == "0") {
				zero--;
			}
			l++;
		}

		// Update the answer with the maximum of the current answer and the sum
		ans = max(ans, sum);
	}

	// Print the final answer
	cout << ans << endl;
}

// RunLength function to get the run-length encoded blocks
vector<Block> RunLength(string s) {
	// If the length of the input string is zero, return an empty slice
	if (s.length() == 0) {
		return vector<Block>{};
	}

	// Initialize the first block with the first character and length one
	Block t = {s[0], 1};

	// Initialize an empty slice to store the blocks
	vector<Block> r;

	// Loop through all the characters in the input string starting from the second character
	for (int i = 1; i < s.length(); i++) {
		// If the current character is the same as the previous character, increment the length of the current block
		if (t.Value == s[i]) {
			t.Len++;
		} else {
			// Add the previous block to the result slice
			r.push_back(t);

			// Initialize a new block with the current character and length one
			t = {s[i], 1};
		}
	}

	// Add the last block to the result slice
	r.push_back(t);

	// Return the result slice
	return r;
}

// End of the code

