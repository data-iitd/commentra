
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
ifstream getScanner(ifstream *fp) {
	ifstream scanner(fp);
	scanner.setstate(ios::skipws); // Set the scanner to skip whitespace.
	return scanner;
}

// getNextString reads the next word from the scanner and returns it as a string.
string getNextString(ifstream *scanner) {
	string word;
	*scanner >> word; // Read the next token.
	return word; // Return the text of the token.
}

// getNextInt converts the next word from the scanner to an integer and returns it.
int getNextInt(ifstream *scanner) {
	int i;
	string word = getNextString(scanner); // Convert the string to an int.
	i = stoi(word);
	return i; // Return the integer.
}

// getNextInt64 converts the next word from the scanner to an int64 and returns it.
int64_t getNextInt64(ifstream *scanner) {
	int64_t i;
	string word = getNextString(scanner); // Convert the string to an int64.
	i = stoll(word);
	return i; // Return the int64.
}

// getNextUint64 converts the next word from the scanner to a uint64 and returns it.
uint64_t getNextUint64(ifstream *scanner) {
	uint64_t i;
	string word = getNextString(scanner); // Convert the string to a uint64.
	i = stoull(word);
	return i; // Return the uint64.
}

// getNextFloat64 converts the next word from the scanner to a float64 and returns it.
float64_t getNextFloat64(ifstream *scanner) {
	float64_t i;
	string word = getNextString(scanner); // Convert the string to a float64.
	i = stod(word);
	return i; // Return the float64.
}

int main() {
	ifstream fp(cin); // Default input is standard input.
	ofstream wfp(cout); // Default output is standard output.

	// Check for command-line arguments to read from a file and write to a file.
	if (argc > 1) {
		fp.open(argv[1]); // Open the input file if provided.
		if (argc > 2) {
			wfp.open(argv[2]); // Create the output file if provided.
		}
	}

	ifstream scanner = getScanner(&fp); // Initialize the scanner for input.
	ofstream writer(wfp); // Create a buffered writer for output.

	int n = getNextInt(&scanner); // Read the number of integers.
	vector<int> ll(n); // Create a vector to hold the integers.

	// Read n integers from the input.
	for (int i = 0; i < n; i++) {
		ll[i] = getNextInt(&scanner); // Populate the vector with integers.
	}

	sort(ll.begin(), ll.end()); // Sort the vector of integers.

	int ans = 0; // Initialize the answer counter.
	// Iterate through pairs of integers to find valid triplets.
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int l = j + 1; // Start searching for the third element after the second element.
			int r = n; // Set the right boundary for binary search.
			// Perform binary search to find the count of valid third elements.
			while (l < r) {
				int m = (l + r) >> 1; // Calculate the middle index.
				if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element.
					l = m + 1; // Move the left boundary up.
					continue;
				}
				r = m; // Move the right boundary down.
			}
			// Count the number of valid third elements.
			ans += l - (j + 1); // Update the answer with the count of valid triplets.
		}
	}
	writer << ans << endl; // Print the result to the output.

	writer.flush(); // Flush the buffered writer to ensure all output is written.

	return 0;
}

