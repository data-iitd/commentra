
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// getNextWord reads the next word from the scanner and returns it as a string.
string getNextWord(ifstream &scanner) {
	string word;
	scanner >> word;
	return word;
}

// getNextInt reads the next word from the scanner, converts it to an integer, and returns it.
int getNextInt(ifstream &scanner) {
	int i;
	scanner >> i;
	return i;
}

int main() {
	// Set the input source to standard input; if a file is provided as an argument, open that file.
	ifstream scanner;
	if (argc > 1) {
		scanner.open(argv[1]);
	} else {
		scanner.open("/dev/stdin");
	}

	// Create a buffered writer to output results to standard output.
	ofstream writer;
	writer.open("/dev/stdout");

	// Read the first two integers, n and m, from the input.
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize a map to store the positions that are blocked (not allowed).
	map<int, int> aa;
	for (int i = 0; i < m; i++) {
		// Read each blocked position and mark it in the map.
		aa[getNextInt(scanner)] = 1;
	}

	// Create a dynamic programming array to store the number of ways to reach each position.
	vector<int> dp(n+1);
	dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

	// Iterate through each position from 0 to n.
	for (int i = 0; i < n; i++) {
		// Check the next two positions (i+1 and i+2) to see if they can be reached.
		for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
			if (aa.find(i+ii)!= aa.end()) {
				continue; // If blocked, skip to the next iteration.
			}
			// Update the number of ways to reach position i+ii based on the current position i.
			dp[i+ii] += dp[i];
			dp[i+ii] %= 1000000007; // Ensure the result stays within the modulo limit.
		}
	}

	// Output the total number of ways to reach position n.
	writer << dp[n] << endl;

	// Flush the buffered writer to ensure all output is written.
	writer.flush();

	return 0;
}

