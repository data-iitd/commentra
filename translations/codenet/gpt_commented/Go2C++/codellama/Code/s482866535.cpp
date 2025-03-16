
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// getScanner initializes a new scanner for reading input from the provided file pointer.
ifstream getScanner(ifstream *fp) {
	ifstream scanner(fp);
	scanner.setstate(ios::skipws); // Set the scanner to skip whitespace.
	return scanner;
}

// getNextString retrieves the next string from the scanner.
string getNextString(ifstream *scanner) {
	string s;
	*scanner >> s; // Read the next token from the input.
	return s; // Return the scanned text.
}

// getNextInt retrieves the next integer from the scanner.
int getNextInt(ifstream *scanner) {
	int i;
	string s = getNextString(scanner); // Convert the next string to an integer.
	i = stoi(s);
	return i; // Return the integer value.
}

int main() {
	// Determine the input source: standard input or a file specified as a command-line argument.
	ifstream fp;
	if (argc > 1) {
		fp.open(argv[1]); // Open the file if a filename is provided.
	} else {
		fp.open("input.txt"); // Open the default file if no filename is provided.
	}

	// Initialize the scanner for reading input and a writer for output.
	ifstream scanner = getScanner(&fp);
	ofstream writer(cout);

	// Read the number of elements.
	int n = getNextInt(&scanner);
	vector<int> mm(n+1); // Create a vector to hold the input values.
	vector<vector<int>> dp(n+1, vector<int>(n+1)); // Create a 2D vector for dynamic programming.

	// Initialize the 2D vector for dynamic programming.
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0; // Each entry is initialized to zero by default.
		}
	}

	// Read the input values into the mm vector.
	for (int i = 0; i < n; i++) {
		mm[i] = getNextInt(&scanner); // Read the first value.
		mm[i+1] = getNextInt(&scanner); // Read the second value.
	}

	// Perform dynamic programming to calculate the minimum cost.
	for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
		for (int i = 1; i <= n-l+1; i++) { // i is the starting index of the subproblem.
			int j = i + l - 1; // j is the ending index of the subproblem.
			for (int k = i; k <= j-1; k++) { // k is the partition point.
				// Calculate the cost of multiplying the matrices.
				int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
				// Update the dp table with the minimum cost found.
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Output the minimum cost of multiplying the entire sequence of matrices.
	cout << dp[1][n] << endl;

	// Flush the writer to ensure all output is written.
	writer.flush();

	return 0;
}

