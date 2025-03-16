
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Initialize a new scanner for reading input
Scanner in;

int main() {
	// Read the first two integers from the standard input
	int n = in.Int();
	int k = in.Int();

	// Check if n is divisible by k
	if (n % k == 0) {
		// If it is, print 0
		cout << 0 << endl;
	} else {
		// If not, print 1
		cout << 1 << endl;
	}
}

// Define a new Scanner type
class Scanner {
public:
	// Initialize a new bufio.Scanner instance
	Scanner(int max = 1048576) {
		// Set the buffer size if it's provided
		if (max <= 0) {
			max = 1048576;
		}
		// Set the buffer and return the new Scanner instance
		s.reserve(max);
	}

	// Parse an integer from a string
	int Int() {
		// Read the next token as a string
		s.Scan();
		// Parse the string to an integer and return it
		int i;
		sscanf(s.c_str(), "%d", &i);
		// Return the integer value
		return i;
	}

private:
	// Initialize a new bufio.Scanner instance
	vector<char> s;
	// Set the split function to split on words instead of whitespace
	void Split(const char* delim) {
		s.clear();
		s.reserve(1048576);
		s.push_back(0);
		sscanf(s.c_str(), "%s", s.data());
	}
};

// Print a line with the given arguments
void Pln(const vector<string>& s) {
	// Iterate through the arguments
	for (int i = 0; i < s.size(); i++) {
		// Print the argument
		cout << s[i];
		// If it's not the last argument, print a space
		if (i < s.size() - 1) {
			cout << " ";
		}
	}
	// Print a newline
	cout << endl;
}

