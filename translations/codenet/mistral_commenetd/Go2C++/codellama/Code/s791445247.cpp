
// by syu
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

// Define a new Scanner type
class Scanner {
public:
	// Initialize a new Scanner instance
	Scanner(int max = 1048576) {
		// Set the buffer size if it's provided
		if (max <= 0) {
			max = 1048576;
		}
		// Set the buffer and return the new Scanner instance
		buffer = new char[max];
		bufferSize = max;
	}

	// Parse an integer from a string
	int Int() {
		// Read the next token as a string
		Scan();
		// Parse the string to an integer and return it
		return atoi(token);
	}

	// Check if a byte is a whitespace character
	bool isSpace(char b) {
		// Return true if the byte is a space, newline, carriage return, or tab character
		return b == ' ' || b == '\n' || b == '\r' || b == '\t';
	}

	// Split function for bufio.Scanner to split on words instead of whitespace
	int scanWords(char *data, int max, int atEOF) {
		// Initialize the start index
		int start = 0;
		// Find the first non-whitespace character
		for (start = 0; start < max && isSpace(data[start]); start++) {
			// Do nothing
		}
		// Iterate through the data and find the next whitespace character or end of data
		for (int i = start; i < max; i++) {
			// If the current character is a whitespace character, return the token and advance the index
			if (isSpace(data[i])) {
				return i + 1;
			}
		}
		// If we've reached the end of data and there's still data to read, return the remaining data as the token
		if (atEOF && max > start) {
			return max;
		}
		// Return the start index as the token and the length of the token as the advance value
		return start;
	}

	// Print a line with the given arguments
	void Pln(char *s) {
		// Print the line with the given arguments
		printf("%s\n", s);
	}

	// Read the next token as a string
	void Scan() {
		// Initialize the start index
		int start = 0;
		// Find the first non-whitespace character
		for (start = 0; start < bufferSize && isSpace(buffer[start]); start++) {
			// Do nothing
		}
		// Iterate through the data and find the next whitespace character or end of data
		for (int i = start; i < bufferSize; i++) {
			// If the current character is a whitespace character, return the token and advance the index
			if (isSpace(buffer[i])) {
				// Set the token and advance the index
				token = buffer + start;
				return;
			}
		}
		// If we've reached the end of data and there's still data to read, return the remaining data as the token
		if (bufferSize > start) {
			// Set the token and advance the index
			token = buffer + start;
			return;
		}
		// Return the start index as the token and the length of the token as the advance value
		token = buffer + start;
	}

	// Read the next token as a string
	char *token;

	// Set the buffer and return the new Scanner instance
	char *buffer;

	// Set the buffer size if it's provided
	int bufferSize;
};

// Initialize a new scanner for reading input
Scanner in(1048576);

int main() {
	// Read the first two integers from the standard input
	int n, k;
	n = in.Int();
	k = in.Int();

	// Check if n is divisible by k
	if (n % k == 0) {
		// If it is, print 0
		in.Pln("0");
	} else {
		// If not, print 1
		in.Pln("1");
	}
}

// Print a line with the given arguments
void Pln(char *s) {
	// Print the line with the given arguments
	printf("%s\n", s);
}

// Print a line with the given arguments
void Pln(int s) {
	// Print the line with the given arguments
	printf("%d\n", s);
}

// Print a line with the given arguments
void Pln(double s) {
	// Print the line with the given arguments
	printf("%f\n", s);
}

// Print a line with the given arguments
void Pln(char *s, int i) {
	// Print the line with the given arguments
	printf("%s %d\n", s, i);
}

// Print a line with the given arguments
void Pln(int i, int j) {
	// Print the line with the given arguments
	printf("%d %d\n", i, j);
}

// Print a line with the given arguments
void Pln(double i, double j) {
	// Print the line with the given arguments
	printf("%f %f\n", i, j);
}

// Print a line with the given arguments
void Pln(char *s, double i) {
	// Print the line with the given arguments
	printf("%s %f\n", s, i);
}

// Print a line with the given arguments
void Pln(double i, char *s) {
	// Print the line with the given arguments
	printf("%f %s\n", i, s);
}

// Print a line with the given arguments
void Pln(char *s, char *t) {
	// Print the line with the given arguments
	printf("%s %s\n", s, t);
}

// Print a line with the given arguments
void Pln(char *s, int i, int j) {
	// Print the line with the given arguments
	printf("%s %d %d\n", s, i, j);
}

// Print a line with the given arguments
void Pln(int i, int j, int k) {
	// Print the line with the given arguments
	printf("%d %d %d\n", i, j, k);
}

// Print a line with the given arguments
void Pln(double i, double j, double k) {
	// Print the line with the given arguments
	printf("%f %f %f\n", i, j, k);
}

// Print a line with the given arguments
void Pln(char *s, double i, double j) {
	// Print the line with the given arguments
	printf("%s %f %f\n", s, i, j);
}

// Print a line with the given arguments
void Pln(double i, double j, char *s) {
	// Print the line with the given arguments
	printf("%f %f %s\n", i, j, s);
}

// Print a line with the given arguments
void Pln(char *s, char *t, char *u) {
	// Print the line with the given arguments
	printf("%s %s %s\n", s, t, u);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t) {
	// Print the line with the given arguments
	printf("%s %d %s\n", s, i, t);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i) {
	// Print the line with the given arguments
	printf("%s %s %d\n", s, t, i);
}

// Print a line with the given arguments
void Pln(char *s, int i, int j, int k) {
	// Print the line with the given arguments
	printf("%s %d %d %d\n", s, i, j, k);
}

// Print a line with the given arguments
void Pln(int i, int j, int k, int l) {
	// Print the line with the given arguments
	printf("%d %d %d %d\n", i, j, k, l);
}

// Print a line with the given arguments
void Pln(double i, double j, double k, double l) {
	// Print the line with the given arguments
	printf("%f %f %f %f\n", i, j, k, l);
}

// Print a line with the given arguments
void Pln(char *s, double i, double j, double k) {
	// Print the line with the given arguments
	printf("%s %f %f %f\n", s, i, j, k);
}

// Print a line with the given arguments
void Pln(double i, double j, double k, char *s) {
	// Print the line with the given arguments
	printf("%f %f %f %s\n", i, j, k, s);
}

// Print a line with the given arguments
void Pln(char *s, char *t, char *u, char *v) {
	// Print the line with the given arguments
	printf("%s %s %s %s\n", s, t, u, v);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, int j) {
	// Print the line with the given arguments
	printf("%s %d %s %d\n", s, i, t, j);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, int j) {
	// Print the line with the given arguments
	printf("%s %s %d %d\n", s, t, i, j);
}

// Print a line with the given arguments
void Pln(char *s, int i, int j, char *t) {
	// Print the line with the given arguments
	printf("%s %d %d %s\n", s, i, j, t);
}

// Print a line with the given arguments
void Pln(char *s, char *t, char *u, int i) {
	// Print the line with the given arguments
	printf("%s %s %s %d\n", s, t, u, i);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, char *u) {
	// Print the line with the given arguments
	printf("%s %d %s %s\n", s, i, t, u);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, char *u) {
	// Print the line with the given arguments
	printf("%s %s %d %s\n", s, t, i, u);
}

// Print a line with the given arguments
void Pln(char *s, char *t, char *u, char *v, char *w) {
	// Print the line with the given arguments
	printf("%s %s %s %s %s\n", s, t, u, v, w);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, char *u, int j) {
	// Print the line with the given arguments
	printf("%s %d %s %s %d\n", s, i, t, u, j);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, char *u, int j) {
	// Print the line with the given arguments
	printf("%s %s %d %s %d\n", s, t, i, u, j);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, int j, char *u) {
	// Print the line with the given arguments
	printf("%s %d %s %d %s\n", s, i, t, j, u);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, int j, char *u) {
	// Print the line with the given arguments
	printf("%s %s %d %d %s\n", s, t, i, j, u);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, char *u, char *v) {
	// Print the line with the given arguments
	printf("%s %d %s %s %s\n", s, i, t, u, v);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, char *u, char *v) {
	// Print the line with the given arguments
	printf("%s %s %d %s %s\n", s, t, i, u, v);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, int j, char *u, int k) {
	// Print the line with the given arguments
	printf("%s %d %s %d %s %d\n", s, i, t, j, u, k);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, char *u, int j, char *v) {
	// Print the line with the given arguments
	printf("%s %s %d %s %d %s\n", s, t, i, u, j, v);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, int j, char *u, char *v) {
	// Print the line with the given arguments
	printf("%s %d %s %d %s %s\n", s, i, t, j, u, v);
}

// Print a line with the given arguments
void Pln(char *s, char *t, int i, int j, char *u, char *v) {
	// Print the line with the given arguments
	printf("%s %s %d %d %s %s\n", s, t, i, j, u, v);
}

// Print a line with the given arguments
void Pln(char *s, int i, char *t, char *u, int j, char *v, int k) {
	// Print the line with the gi