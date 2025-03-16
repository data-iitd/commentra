
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// -----------------------------------------------------------------------------

// IO helper functions

// nextToken and nextLine are function variables that will be initialized 
// by SetInput() and SetUnbufferedInput() for reading input tokens and lines.
function<string()> nextToken;
function<string()> nextLine;

// OutputBuffer holds a buffered writer for output. It must be initialized by SetOutput().
ofstream OutputBuffer;

// OutputWriter holds an io.Writer for output. It must be initialized by SetOutput().
ostream* OutputWriter;

// SetInteractive configures the IO functions for interactive input/output.
void SetInteractive(ostream& w, istream& r) {
	SetUnbufferedInput(r); // Set unbuffered input for reading
	OutputBuffer = nullptr; // No output buffer for interactive mode
	OutputWriter = &w; // Set the output writer
}

// Setup OutputBuffer and OutputWriter for buffered output.
void SetOutput(ostream& w) {
	OutputBuffer.rdbuf(w.rdbuf()); // Initialize the output buffer
	OutputWriter = &OutputBuffer; // Set the output writer to the buffer
}

// Flushes OutputBuffer to ensure all buffered data is written out.
void Flush() {
	if (OutputBuffer.is_open()) {
		OutputBuffer.flush(); // Flush the buffer if it is initialized
	}
}

// IsSpace checks if a byte is a whitespace character.
bool IsSpace(char c) {
	switch (c) {
	case '\t':
	case '\n':
	case '\v':
	case '\f':
	case '\r':
	case ' ':
		return true;
	}
	return false;
}

// IsNewLine checks if a byte is a newline character.
bool IsNewLine(char c) {
	switch (c) {
	case '\n':
	case '\r':
		return true;
	}
	return false;
}

// SetInput initializes the nextToken function with an input buffer.
void SetInput(istream& r) {
	stringstream buf; // Create a new stringstream
	string b; // Buffer to hold input bytes

	int i = 0; // Index for reading from buffer
	// Function to read the next token from the input
	function<string()> rest = [&]() {
		while (i < b.size() && IsSpace(b[i])) {
			i++; // Skip whitespace
		}
		if (i == b.size()) {
			return ""; // Return error if end of buffer is reached
		}
		int j = i;
		while (i < b.size() && !IsSpace(b[i])) {
			i++; // Read until whitespace is found
		}
		return b.substr(j, i - j); // Return the token
	};
	// Function to initialize reading from the input
	function<string()> initial = [&]() {
		copy(istream_iterator<char>(r), istream_iterator<char>(), ostream_iterator<char>(buf)); // Copy input to buffer
		b = buf.str(); // Get bytes from the buffer
		nextToken = rest; // Set nextToken to the rest function
		return rest(); // Read the first token
	};
	nextToken = initial; // Initialize nextToken

	// Function to read the next line from the input
	function<string()> restLn = [&]() {
		while (i < b.size() && IsNewLine(b[i])) {
			i++; // Skip new line characters
		}
		if (i == b.size()) {
			return ""; // Return error if end of buffer is reached
		}
		int j = i;
		while (i < b.size() && !IsNewLine(b[i])) {
			i++; // Read until new line is found
		}
		return b.substr(j, i - j); // Return the line
	};

	// Function to initialize reading lines from the input
	function<string()> initialLn = [&]() {
		copy(istream_iterator<char>(r), istream_iterator<char>(), ostream_iterator<char>(buf)); // Copy input to buffer
		b = buf.str(); // Get bytes from the buffer
		nextLine = restLn; // Set nextLine to the restLn function
		return restLn(); // Read the first line
	};
	nextLine = initialLn; // Initialize nextLine
}

// SetUnbufferedInput configures the nextToken function for unbuffered input.
void SetUnbufferedInput(istream& r) {
	stringstream buf; // Create a new stringstream
	string b; // Buffer to hold input bytes

	int i = 0; // Index for reading from buffer
	// Function to read the next token from the input
	nextToken = [&]() {
		if (i == b.size()) { // If the buffer is empty
			getline(r, b); // Read until newline
			i = 0; // Reset index
			int j = b.size() - 1;
			while (0 <= j && IsSpace(b[j])) {
				j--; // Trim trailing whitespace
			}
			b = b.substr(0, j + 1); // Resize buffer to remove whitespace
		}
		while (i < b.size() && IsSpace(b[i])) {
			i++; // Skip whitespace
		}
		int j = i;
		while (i < b.size() && !IsSpace(b[i])) {
			i++; // Read until whitespace is found
		}
		if (i == j) {
			return ""; // Return error if no token found
		}
		return b.substr(j, i - j); // Return the token
	};
}

// -----------------------------------------------------------------------------

// IO functions

// readb reads the next token and returns it as a byte slice.
string readb() {
	string b = nextToken(); // Read the next token
	return b; // Return the token
}

// reads reads the next token and returns it as a string.
string reads() {
	return readb(); // Convert byte slice to string
}

// readbln reads the next line as a byte slice, excluding the trailing newline.
string readbln() {
	string b = nextLine(); // Read the next line
	return b; // Return the line
}

// readsln reads the next line and returns it as a string.
string readsln() {
	return readbln(); // Convert byte slice to string
}

// readll reads the next token and returns it as an int64.
int64_t readll() {
	int64_t i; // Initialize int64_t
	stringstream ss(reads()); // Create a stringstream from the token
	ss >> i; // Read the token as int64_t
	if (ss.fail()) {
		panic("failed to read int64_t"); // Panic if reading fails
	}
	return i; // Return the parsed int64_t
}

// readi reads the next token and returns it as an int.
int readi() {
	return int(readll()); // Convert int64_t to int
}

// readf reads the next token and returns it as a float64.
double readf() {
	double f; // Initialize float64
	stringstream ss(reads()); // Create a stringstream from the token
	ss >> f; // Read the token as float64
	if (ss.fail()) {
		panic("failed to read float64"); // Panic if reading fails
	}
	return f; // Return the parsed float64
}

// printf writes formatted output to OutputWriter.
void printf(string f, ...) {
	va_list args; // Create a variable argument list
	va_start(args, f); // Initialize the variable argument list
	vfprintf(*OutputWriter, f.c_str(), args); // Write formatted output
	va_end(args); // Clean up the variable argument list
}

// println writes output to OutputWriter without formatting.
void println(string s) {
	*OutputWriter << s << endl; // Write output without formatting
}

// eprintf writes formatted output to stderr.
void eprintf(string f, ...) {
	va_list args; // Create a variable argument list
	va_start(args, f); // Initialize the variable argument list
	vfprintf(stderr, f.c_str(), args); // Write formatted output to stderr
	va_end(args); // Clean up the variable argument list
}

// eprintln writes output to stderr without formatting.
void eprintln(string s) {
	fprintf(stderr, "%s\n", s.c_str()); // Write output without formatting to stderr
}

// debugf writes formatted debug output to stderr if DEBUG is enabled.
void debugf(string f, ...) {
	if (!DEBUG) {
		return; // Do nothing if DEBUG is not enabled
	}
	va_list args; // Create a variable argument list
	va_start(args, f); // Initialize the variable argument list
	vfprintf(stderr, f.c_str(), args); // Write formatted debug output
	va_end(args); // Clean up the variable argument list
}

// debug writes debug output to stderr if DEBUG is enabled.
void debug(string s) {
	if (!DEBUG) {
		return; // Do nothing if DEBUG is not enabled
	}
	fprintf(stderr, "%s\n", s.c_str()); // Write debug output
}

// -----------------------------------------------------------------------------

// Utilities

// sumSlice calculates the sum of a slice of integers.
int sumSlice(vector<int> a) {
	int res = 0; // Initialize result
	for (int v : a) {
		res += v; // Accumulate the sum
	}
	return res; // Return the total sum
}

// sumSlicell calculates the sum of a slice of int64.
int64_t sumSlicell(vector<int64_t> a) {
	int64_t res = 0; // Initialize result
	for (int64_t v : a) {
		res += v; // Accumulate the sum
	}
	return res; // Return the total sum
}

// readInts reads N integers from input and returns the count and the slice.
pair<int, vector<int>> readInts(int N) {
	if (N == 0) {
		N = readi(); // Read N if it is zero
	}
	vector<int> a(N); // Create a slice of integers
	for (int i = 0; i < N; i++) {
		a[i] = readi(); // Read each integer
	}
	return make_pair(N, a); // Return the count and the slice
}

// readIntsll reads N int64 values from input and returns the count and the slice.
pair<int, vector<int64_t>> readIntsll(int N) {
	if (N == 0) {
		N = readi(); // Read N if it is zero
	}
	vector<int64_t> a(N); // Create a slice of int64
	for (int i = 0; i < N; i++) {
		a[i] = readll(); // Read each int64 value
	}
	return make_pair(N, a); // Return the count and the slice
}

// -----------------------------------------------------------------------------

// Simple math functions

const int INF = 1000000007; // Define large prime constants for calculations
const int INF2 = 1000000009;
const int INF3 = 998244353;

// min returns the smaller of two integers.
int min(int a, int b) {
	if (a < b) {
		return a; // Return a if it is smaller
	}
	return b; // Otherwise return b
}

// minll returns the smaller of two int64 values.
int64_t minll(int64_t a, int64_t b) {
	if (a < b) {
		return a; // Return a if it is smaller
	}
	return b; // Otherwise return b
}

// minf returns the smaller of two float64 values.
double minf(double a, double b) {
	if (a < b) {
		return a; // Return a if it is