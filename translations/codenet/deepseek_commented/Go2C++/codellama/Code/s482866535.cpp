
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// getScanner initializes a new scanner for reading from a file.
ifstream getScanner(string filename) {
	ifstream scanner(filename);
	scanner.sync_with_stdio(false);
	return scanner;
}

// getNextString reads the next word from the scanner.
string getNextString(ifstream &scanner) {
	string word;
	scanner >> word;
	return word;
}

// getNextInt converts the next word from the scanner to an integer.
int getNextInt(ifstream &scanner) {
	string word = getNextString(scanner);
	return stoi(word);
}

// Main function to compute the minimum number of matrix multiplications.
int main() {
	// Initialize scanner and writer for standard input and output.
	ifstream scanner = getScanner("");
	ofstream writer(cout);

	// Read the number of matrices.
	int n = getNextInt(scanner);

	// Initialize arrays for matrix dimensions and dynamic programming.
	vector<int> mm(n+1);
	vector<vector<int>> dp(n+1, vector<int>(n+1));

	// Read matrix dimensions into the mm array.
	for (int i = 0; i < n; i++) {
		mm[i] = getNextInt(scanner);
		mm[i+1] = getNextInt(scanner);
	}

	// Use dynamic programming to compute the minimum number of multiplications.
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n-l+1; i++) {
			int j = i + l - 1;
			for (int k = i; k <= j-1; k++) {
				int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Print the result to the standard output.
	writer << dp[1][n] << endl;

	// Flush the writer to ensure all data is written to the output.
	writer.flush();

	return 0;
}

