#include <bits/stdc++.h>

using namespace std;

// Initialize a new scanner to read input from standard input
auto sc = make_shared<stringstream>();

int main() {
	// Initialize the scanner with a specific buffer size
	scanInit();

	// Read the input string
	string s = nextStr();

	// Start checking for the first missing lowercase letter from 'a'
	char c = 'a';

	// Loop through all lowercase letters from 'a' to 'z'
	for (int j = 0; j < 26; j++) {
		bool found = false; // Flag to check if the current letter is found in the input string
		// Check if the current letter exists in the input string
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == c) {
				found = true; // Set the flag to true if the letter is found
				break;
			}
		}
		// If the letter was not found, print it and exit
		if (found == false) {
			cout << c << endl;
			return 0;
		}
		c++; // Move to the next letter
	}

	// If all letters from 'a' to 'z' are found, print "None"
	cout << "None" << endl;
}

// ---- readfunc

// scanInit initializes the scanner with a large buffer to read input efficiently
void scanInit() {
	const int cap = 1000 * 1024; // Define the buffer capacity
	auto buf = make_shared<char[]>(cap); // Create a buffer of the specified capacity
	sc->rdbuf()->pubsetbuf(buf.get(), cap); // Set the scanner's buffer
	sc->str(""); // Set the input string to empty
	sc->clear(); // Clear the error state of the scanner
	return;
}

// nextInt reads the next integer from the input
int nextInt() {
	sc->clear(); // Clear the error state of the scanner
	sc->str(nextStr()); // Set the input string to the next token
	int i; // Declare an integer to store the integer value
	istringstream iss(*sc); // Create a stringstream to read from the input string
	iss >> i; // Read the next token and store it in the integer
	if (iss.fail()) { // Check if there is an error during conversion
		iss.clear(); // Clear the error state of the stringstream
		iss.str(""); // Set the input string to empty
		throw invalid_argument("nextInt(): Failed to read integer"); // Throw an exception
	}
	return i; // Return the integer
}

// nextStr reads the next string from the input
string nextStr() {
	sc->clear(); // Clear the error state of the scanner
	string s; // Declare a string to store the string value
	getline(*sc, s); // Read the next line and store it in the string
	if (sc->fail()) { // Check if there is an error during reading
		sc->clear(); // Clear the error state of the scanner
		sc->str(""); // Set the input string to empty
		throw invalid_argument("nextStr(): Failed to read string"); // Throw an exception
	}
	return s; // Return the string
}

