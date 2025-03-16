#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// getNextWord reads the next word from the scanner and returns it as a string.
string getNextWord(istream &in) {
	string word;
	in >> word;
	return word;
}

// getNextInt reads the next word from the scanner, converts it to an integer, and returns it.
int getNextInt(istream &in) {
	int i;
	in >> i;
	return i;
}

int main() {
	// Set the input source to standard input; if a file is provided as an argument, open that file.
	istream *in = &cin;
	ifstream ifile;
	if (argc > 1) {
		ifile.open(argv[1]);
		in = &ifile;
	}

	// Create a new scanner to read from the input source and configure it to split input into words.
	istream_iterator<string> begin(*in);
	istream_iterator<string> end;
	istream_iterator<string> it(begin);
	istream_iterator<string> eof;
	istringstream iss;
	iss.str(string(it, eof));
	iss.clear();
	istream_iterator<string> word_it(iss);
	istream_iterator<string> word_eof;

	// Create a buffered writer to output results to standard output.
	ostream *out = &cout;
	ofstream ofile;
	ofile.open("output.txt");
	out = &ofile;

	// Read the first two integers, n and m, from the input.
	int n = getNextInt(iss);
	int m = getNextInt(iss);

	// Initialize a map to store the positions that are blocked (not allowed).
	map<int, int> aa;
	for (int i = 0; i < m; i++) {
		// Read each blocked position and mark it in the map.
		int blocked = getNextInt(iss);
		aa[blocked] = 1;
	}

	// Create a dynamic programming array to store the number of ways to reach each position.
	vector<int> dp(n + 1, 0);
	dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

	// Iterate through each position from 0 to n.
	for (int i = 0; i < n; i++) {
		// Check the next two positions (i+1 and i+2) to see if they can be reached.
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			map<int, int>::iterator it = aa.find(i + ii); // Check if the next position is blocked.
			if (it!= aa.end()) {
				continue; // If blocked, skip to the next iteration.
			}
			// Update the number of ways to reach position i+ii based on the current position i.
			dp[i + ii] += dp[i];
			dp[i + ii] %= 1000000007; // Ensure the result stays within the modulo limit.
		}
	}

	// Output the total number of ways to reach position n.
	*out << dp[n] << endl;

	// Flush the buffered writer to ensure all output is written.
	ofile.close();
}

