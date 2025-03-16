// by syu
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

// Initialize a new Scanner for reading input from standard input (cin)
Scanner in(cin, 0);

int main() {
	// Read two integers n and k from the input
	int n, k;
	n = in.Int();
	k = in.Int();
	
	// Check if n is divisible by k
	if (n % k == 0) {
		// If n is divisible by k, print 0
		cout << 0 << endl;
	} else {
		// If n is not divisible by k, print 1
		cout << 1 << endl;
	}
	return 0;
}

// Scanner struct wraps istream for custom input handling
class Scanner {
public:
	Scanner(istream& is, int max) : m_is(is), m_max(max) {
		if (m_max <= 0) {
			m_max = 1048576; // Default buffer size if max is not specified
		}
		m_buf.resize(m_max);
	}
	
	int Int() {
		m_is.getline(&m_buf[0], m_max); // Read the next line of input
		int i = atoi(&m_buf[0]); // Parse the line as an integer
		return i;
	}
	
private:
	istream& m_is;
	int m_max;
	vector<char> m_buf;
};

// isSpace checks if a character is a whitespace character
bool isSpace(char c) {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

// scanWords is a custom split function for the Scanner to tokenize input
int scanWords(char* data, int max, int& start) {
	// Skip leading whitespace
	while (start < max && isSpace(data[start])) {
		start++;
	}
	// Find the end of the next word
	for (int i = start; i < max; i++) {
		if (isSpace(data[i])) {
			return i + 1; // Return the word found
		}
	}
	return start; // Return the current position if no word is found
}

// Pln is a convenience function to print a line to standard output
void Pln(int s) {
	cout << s << endl; // Print the provided argument
}

