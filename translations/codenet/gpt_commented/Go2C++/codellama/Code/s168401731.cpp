
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// getScanner initializes a new scanner for the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer size.
ifstream getScanner(ifstream *fp) {
	ifstream scanner(*fp);
	scanner.imbue(locale(locale::classic(), new word_separator<char>(word_separator<char>(" \t\n"))));
	scanner.rdbuf()->pubsetbuf(new char[500001], 500000);
	return scanner;
}

// getNextString retrieves the next string from the scanner.
string getNextString(ifstream *scanner) {
	string s;
	*scanner >> s;
	return s;
}

// getNextInt converts the next string from the scanner to an integer.
int getNextInt(ifstream *scanner) {
	string s = getNextString(scanner);
	return stoi(s);
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
int64_t getNextInt64(ifstream *scanner) {
	string s = getNextString(scanner);
	return stoll(s);
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
uint64_t getNextUint64(ifstream *scanner) {
	string s = getNextString(scanner);
	return stoull(s);
}

// getNextFloat64 converts the next string from the scanner to a float64.
double getNextFloat64(ifstream *scanner) {
	string s = getNextString(scanner);
	return stod(s);
}

int main() {
	// Initialize file pointers for input and output.
	ifstream fp(cin);
	ofstream wfp(cout);

	// Check for command line arguments to open input and output files.
	if (argc > 1) {
		fp.open(argv[1]); // Open input file if provided.
		if (argc > 2) {
			wfp.open(argv[2]); // Create output file if provided.
		}
	}

	// Create a scanner for reading input and a writer for output.
	ifstream scanner = getScanner(&fp);
	ofstream writer = getWriter(&wfp);

	// Read the number of integers to process.
	int n = getNextInt(&scanner);

	// Initialize the answer as "second" and check for odd integers.
	string ans = "second";
	for (int i = 0; i < n; i++) {
		int a = getNextInt(&scanner); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	writer << ans << endl;
	writer.flush(); // Ensure all buffered data is written to the output.

	return 0;
}

