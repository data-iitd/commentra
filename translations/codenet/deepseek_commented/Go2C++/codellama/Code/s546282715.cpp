
#include <iostream>
#include <map>
#include <string>

using namespace std;

// getNextWord reads the next word from the scanner.
string getNextWord(istream& scanner) {
	string word;
	scanner >> word;
	return word;
}

// getNextInt reads the next word from the scanner and converts it to an integer.
int getNextInt(istream& scanner) {
	int i;
	string word = getNextWord(scanner);
	i = stoi(word);
	return i;
}

// main function starts here
int main() {
	// Determine the input source based on command-line arguments
	istream* fp;
	if (argc > 1) {
		fp = new ifstream(argv[1]);
	} else {
		fp = &cin;
	}

	// Create a new scanner to read from the determined input source
	istream& scanner = *fp;

	// Create a writer to output the result
	ostream& writer = cout;

	// Read the number of elements (n) and the number of restricted positions (m)
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Create a map to store the restricted positions
	map<int, int> aa;
	for (int i = 0; i < m; i++) {
		int ii = getNextInt(scanner);
		aa[ii] = 1;
	}

	// Initialize the dynamic programming array
	int dp[n + 1];
	dp[0] = 1;

	// Fill the dynamic programming array based on restricted positions
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			map<int, int>::iterator it = aa.find(i + ii);
			if (it != aa.end()) {
				continue;
			}
			dp[i + ii] += dp[i];
			dp[i + ii] %= 1000000007;
		}
	}

	// Print the result
	writer << dp[n] << endl;

	// Flush the writer to ensure all data is written to the output
	writer.flush();

	// Close the input file if it was opened
	if (fp != &cin) {
		fp->close();
	}

	return 0;
}

