#include <bits/stdc++.h>

using namespace std;

// Function to read the next word from the scanner
string getNextWord(istringstream &scanner) {
	string word;
	scanner >> word;
	return word;
}

// Function to read the next integer from the scanner
int getNextInt(istringstream &scanner) {
	int i;
	scanner >> i;
	return i;
}

// Main function
int main() {
	// Open the standard input file if the command line argument is provided
	ifstream fp;
	if (argc > 1) {
		fp.open(argv[1]);
	} else {
		fp.open("input.txt");
	}

	// Initialize the scanner and writer
	istringstream scanner(fp.rdbuf());
	ostringstream writer;

	// Read the first two integers from the input
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize an associative array to store the elements
	unordered_map<int, int> aa;
	// Read m elements and store them in the associative array
	for (int i = 0; i < m; i++) {
		int x = getNextInt(scanner);
		aa[x] = 1;
	}

	// Initialize a slice of length n+1 for dynamic programming
	vector<int> dp(n+1, 0);
	// Initialize the first element of the slice
	dp[0] = 1;

	// Iterate through the array from index 0 to n-1
	for (int i = 0; i < n; i++) {
		// Iterate through the prefix sum from i to i+2
		for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
			// Skip if the current index and its sum are already present in the associative array
			unordered_map<int, int>::iterator it = aa.find(i+ii);
			if (it!= aa.end()) {
				continue;
			}
			// Calculate the dynamic programming value for the current index
			dp[i+ii] += dp[i];
			// Perform modulo operation to keep the value within the range of 10^9+7
			dp[i+ii] %= 1000000007;
		}
	}

	// Print the final answer
	writer << dp[n] << endl;

	// Flush the writer buffer
	cout << writer.str();

	return 0;
}

