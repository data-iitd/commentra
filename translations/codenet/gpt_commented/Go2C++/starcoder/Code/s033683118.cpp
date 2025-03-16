#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for larger inputs.
static inline istream* getScanner(FILE* fp) {
	istream* scanner = new istream(fp);
	scanner->imbue(locale(""));
	scanner->word_sync(true);
	return scanner;
}

// getNextString retrieves the next string from the scanner.
static inline string getNextString(istream* scanner) {
	string s;
	*scanner >> s;
	return s;
}

// getNextInt converts the next string from the scanner to an integer.
static inline int getNextInt(istream* scanner) {
	int i;
	*scanner >> i;
	return i;
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
static inline int64_t getNextInt64(istream* scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
static inline uint64_t getNextUint64(istream* scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// getNextFloat64 converts the next string from the scanner to a float64.
static inline double getNextFloat64(istream* scanner) {
	double i;
	*scanner >> i;
	return i;
}

int main() {
	// Initialize file pointers for input and output.
	FILE* fp = stdin;
	FILE* wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (const char* env = getenv("MASPY")) {
		fp = fopen(env, "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (const char* env = getenv("MASPYPY")) {
		wfp = fopen(env, "w");
	}

	// Create a scanner for reading input and a writer for output.
	auto scanner = getScanner(fp);
	auto writer = new ostream(wfp);

	// Solve the problem for the first time.
	solve(scanner, writer);

	// If cnt is greater than 0, solve the problem additional times.
	for (int i = 0; i < cnt; i++) {
		*writer << "-----------------------------------" << endl;
		solve(scanner, writer);
	}

	// Flush the writer to ensure all output is written.
	delete writer;
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
static inline void solve(istream* scanner, ostream* writer) {
	int k = getNextInt(scanner); // Read the first integer k.
	int x = getNextInt(scanner); // Read the second integer x.

	string ans = "No"; // Default answer is "No".
	if (k * 500 >= x) { // Check the condition.
		ans = "Yes"; // Update answer to "Yes" if condition is met.
	}
	*writer << ans << endl; // Output the result.
}

