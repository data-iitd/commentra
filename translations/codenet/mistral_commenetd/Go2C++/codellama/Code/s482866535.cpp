
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get a new scanner from a file pointer
ifstream getScanner(ifstream *fp) {
	ifstream scanner(fp);
	scanner.imbue(locale(locale::classic(), new word_separator_facet));
	return scanner;
}

// Function to read the next string from the scanner
string getNextString(ifstream &scanner) {
	string word;
	scanner >> word;
	return word;
}

// Function to read the next integer from the scanner
int getNextInt(ifstream &scanner) {
	int i;
	scanner >> i;
	return i;
}

// Main function to read input and process it
int main() {
	// Open the standard input stream if no file is provided as an argument
	ifstream fp(0);
	if (argc > 1) {
		// Open the file provided as an argument and use it as the input stream
		fp.open(argv[1]);
	}

	// Initialize a new scanner from the input stream
	ifstream scanner = getScanner(&fp);
	ofstream writer(1);

	// Read the number of test cases from the input
	int n = getNextInt(scanner);

	// Initialize a vector to store the prefix sum of squares of elements
	vector<int> mm(n+1);

	// Initialize a 2D vector to store the dynamic programming table
	vector<vector<int>> dp(n+1, vector<int>(n+1));

	// Read the elements and their prefix sum of squares from the input
	for (int i = 0; i < n; i++) {
		// Read the next integer as the current element
		mm[i+1] = getNextInt(scanner);
		// Read the next integer as the next element's prefix sum of square
		mm[i+1] += mm[i] * mm[i];
	}

	// Process the dynamic programming table for all subarrays of given size
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n-l+1; i++) {
			int j = i + l - 1;
			// Iterate through all subarrays of the current subarray
			for (int k = i; k <= j-1; k++) {
				// Calculate the sum of squares of elements in the current subarray
				int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
				// Update the dynamic programming table if a larger sum is found
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Print the result for the given input
	cout << dp[1][n] << endl;

	// Flush the writer to print the result
	writer.flush();

	// End of the code
	return 0;
}

