
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// getNextWord reads the next word from the scanner.
string getNextWord(ifstream &scanner) {
	string word;
	scanner >> word;
	return word;
}

// getNextInt reads the next word from the scanner and converts it to an integer.
int getNextInt(ifstream &scanner) {
	int i;
	scanner >> i;
	return i;
}

int main() {
	// Determine the input source based on command-line arguments
	ifstream scanner;
	if (argc > 1) {
		scanner.open(argv[1]);
	} else {
		scanner.open("/dev/stdin");
	}

	// Create a writer to output the result
	ofstream writer("/dev/stdout");

	// Read the number of elements (n) and the number of restricted positions (m)
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Create a map to store the restricted positions
	map<int, int> aa;
	for (int i = 0; i < m; i++) {
		int a = getNextInt(scanner);
		aa[a] = 1;
	}

	// Initialize the dynamic programming array
	vector<int> dp(n+1, 0);
	dp[0] = 1;

	// Fill the dynamic programming array based on restricted positions
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
			if (aa.find(i+ii)!= aa.end()) {
				continue;
			}
			dp[i+ii] += dp[i];
			dp[i+ii] %= 1000000007;
		}
	}

	// Print the result
	writer << dp[n] << endl;

	// Flush the writer to ensure all data is written to the output
	writer.flush();

	return 0;
}

