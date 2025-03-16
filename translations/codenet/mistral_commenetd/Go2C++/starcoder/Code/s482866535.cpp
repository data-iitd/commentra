#include <bits/stdc++.h>

using namespace std;

// Function to get a new scanner from a file pointer
auto getScanner(FILE *fp) {
	return make_shared<stringstream>(stringstream(ios::in | ios::out));
}

// Function to read the next string from the scanner
auto getNextString(shared_ptr<stringstream> scanner) {
	return getline(*scanner,'','', ios::in | ios::out);
}

// Function to read the next integer from the scanner
auto getNextInt(shared_ptr<stringstream> scanner) {
	return stoi(getNextString(scanner));
}

// Main function to read input and process it
int main() {
	// Open the standard input stream if no file is provided as an argument
	auto fp = fopen(argv[1], "r");
	if (!fp) {
		fp = stdin;
	}

	// Initialize a new scanner from the input stream
	auto scanner = getScanner(fp);
	auto writer = make_shared<stringstream>(stringstream(ios::in | ios::out));

	// Read the number of test cases from the input
	auto n = getNextInt(scanner);

	// Initialize a slice to store the prefix sum of squares of elements
	vector<int> mm(n + 1);

	// Initialize a 2D slice to store the dynamic programming table
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));

	// Read the elements and their prefix sum of squares from the input
	for (int i = 0; i < n; i++) {
		// Read the next integer as the current element
		mm[i + 1] = getNextInt(scanner);
		// Read the next integer as the next element's prefix sum of square
		mm[i + 1] += mm[i] * mm[i];
	}

	// Process the dynamic programming table for all subarrays of given size
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			// Iterate through all subarrays of the current subarray
			for (int k = i; k <= j - 1; k++) {
				// Calculate the sum of squares of elements in the current subarray
				int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
				// Update the dynamic programming table if a larger sum is found
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Print the result for the given input
	cout << dp[1][n] << endl;

	// End of the code


Translate the above C++ code to Python and end with comment "