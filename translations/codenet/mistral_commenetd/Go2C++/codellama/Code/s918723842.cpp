
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Scanner struct represents the input reader.
struct Scanner {
	// bufio.Reader field r is used for reading from the standard input.
	stringstream r;
	// buf string slice buffer is used for storing the input line.
	string buf;
	// p integer p keeps track of the current position in the buffer.
	int p;

	// NewScanner function initializes a new Scanner object with the standard input os.Stdin as the reader.
	Scanner() {
		// Initialize a new stringstream object named rdr with the standard input as the I/O source.
		r = stringstream(cin.rdbuf());
		// Initialize a new Scanner object named s with the rdr as the reader field.
		p = 0;
	}

	// Next method reads the next token from the input, which can be a single word, number, or symbol.
	// It skips leading whitespaces and returns the result as a string.
	string Next() {
		// Set the current position p to the beginning of the buffer if it's at the end.
		pre();
		// Start index of the token in the buffer.
		int start = p;
		// Read the input until a non-whitespace character is found.
		for (; p < buf.size(); p++) {
			// If the current character is a whitespace, break the loop.
			if (buf[p] == ' ') {
				break;
			}
		}
		// Read the token, including the whitespace character if any.
		string result = buf.substr(start, p - start);
		// Increment the current position p.
		p++;
		// Return the result.
		return result;
	}

	// NextLine method reads the next line from the input and returns it as a string.
	string NextLine() {
		// Set the current position p to the beginning of the buffer if it's at the end.
		pre();
		// Start index of the line in the buffer.
		int start = p;
		// Read the input until the end of the line is reached.
		for (; p < buf.size(); p++) {
			// If the current character is a newline character, break the loop.
			if (buf[p] == '\n') {
				break;
			}
		}
		// Read the line, including the newline character if any.
		string result = buf.substr(start, p - start);
		// Increment the current position p.
		p++;
		// Return the result.
		return result;
	}

	// NextInt method reads an integer from the input and returns it.
	int NextInt() {
		// Read the next token as a string.
		string token = Next();
		// Parse the token as an integer and return the result.
		int v;
		istringstream(token) >> v;
		// Return the result.
		return v;
	}

	// NextInt64 method reads a 64-bit integer from the input and returns it.
	int64_t NextInt64() {
		// Read the next token as a string.
		string token = Next();
		// Parse the token as a 64-bit integer and return the result.
		int64_t v;
		istringstream(token) >> v;
		// Return the result.
		return v;
	}

	// NextFloat method reads a floating-point number from the input and returns it.
	double NextFloat() {
		// Read the next token as a string.
		string token = Next();
		// Parse the token as a floating-point number and return the result.
		double v;
		istringstream(token) >> v;
		// Return the result.
		return v;
	}

	// NextIntArray method reads an array of integers from the input and returns it.
	vector<int> NextIntArray() {
		// Read the next line as a string.
		string line = NextLine();
		// Split the line into tokens using spaces as delimiters.
		istringstream ss(line);
		vector<int> tokens;
		int v;
		while (ss >> v) {
			tokens.push_back(v);
		}
		// Return the result.
		return tokens;
	}

	// NextInt64Array method reads an array of 64-bit integers from the input and returns it.
	vector<int64_t> NextInt64Array() {
		// Read the next line as a string.
		string line = NextLine();
		// Split the line into tokens using spaces as delimiters.
		istringstream ss(line);
		vector<int64_t> tokens;
		int64_t v;
		while (ss >> v) {
			tokens.push_back(v);
		}
		// Return the result.
		return tokens;
	}

	// NextMap method reads a map from the input and returns it.
	map<int, bool> NextMap() {
		// Read the next line as a string.
		string line = NextLine();
		// Split the line into tokens using spaces as delimiters.
		istringstream ss(line);
		map<int, bool> mp;
		string token;
		while (ss >> token) {
			int key;
			istringstream(token.substr(0, token.find(":"))) >> key;
			mp[key] = true;
		}
		// Return the result.
		return mp;
	}

	// pre method sets the current position p to the beginning of the buffer if it's at the end.
	void pre() {
		// If the current position p is at the end of the buffer, read the next line.
		if (p >= buf.size()) {
			readLine();
			p = 0;
		}
	}

	// readLine method reads a line from the input and appends it to the buffer.
	void readLine() {
		// Read a line from the input using the bufio.Reader.
		getline(r, buf);
		// Remove the newline character from the line.
		buf.erase(buf.end() - 1);
	}
};

// main function is the entry point of the program.
int main() {
	// Initialize a new Scanner object named sc.
	Scanner sc;
	// Read the height H, width W, and number of obstacles N from the standard input.
	int H = sc.NextInt();
	int W = sc.NextInt();
	int N = sc.NextInt();
	// Calculate the maximum dimension A between H and W.
	int A = max(H, W);
	// Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
	cout << (N + A - 1) / A << endl;
	// End of the code.
	return 0;
}

// max function returns the maximum value between two integers a and b.
int max(int a, int b) {
	// If a is smaller than b, return b.
	if (a < b) {
		return b;
	}
	// Otherwise, return a.
	return a;
}

