
#include <bits/stdc++.h>

using namespace std;

// FastScanner class for reading input
class FastScanner {
private:
	// Input stream
	istream& in;
	// Buffer for storing the input
	char buffer[1024];
	// Length of the current input line
	int length;
	// Current position in the buffer
	int position;

public:
	// Constructor
	FastScanner(istream& stream) : in(stream), length(0), position(0) {
		// Nothing to do
	}

	// Get the next token
	string next() {
		// If the position is at the end of the buffer, read a new line
		if (position >= length) {
			in.getline(buffer, 1024);
			length = in.gcount();
			position = 0;
		}

		// If the position is at the end of the line, return an empty string
		if (position >= length) {
			return "";
		}

		// Find the start of the next token
		int start = position;
		// Find the end of the next token
		while (position < length && buffer[position]!='') {
			position++;
		}

		// Copy the token from the buffer
		string result(buffer + start, position - start);
		// Move the position to the next token
		position++;

		// Return the result
		return result;
	}

	// Get the next line
	string nextLine() {
		// If the position is at the end of the buffer, read a new line
		if (position >= length) {
			in.getline(buffer, 1024);
			length = in.gcount();
			position = 0;
		}

		// If the position is at the end of the line, return an empty string
		if (position >= length) {
			return "";
		}

		// Find the start of the next line
		int start = position;
		// Copy the rest of the line to the buffer
		position = length;
		// Return the line
		return string(buffer + start, length - start);
	}

	// Get the next integer
	int nextInt() {
		// Get the next token
		string token = next();
		// Convert the token to an integer
		int result;
		istringstream(token) >> result;
		// Return the result
		return result;
	}
};

// Main function
int main() {
	// Read three integers from the standard input
	FastScanner scanner(cin);
	int A = scanner.nextInt();
	int B = scanner.nextInt();
	int C = scanner.nextInt();

	// Check if the difference between B and A is equal to the difference between C and B
	if (B - A == C - B) {
		// If it is, print "YES"
		cout << "YES" << endl;
	} else {
		// Otherwise, print "NO"
		cout << "NO" << endl;
	}

	// 