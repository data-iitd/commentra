
#include <iostream>
#include <string>

using namespace std;

// getNextString retrieves the next string from the input stream.
string getNextString() {
	string s;
	cin >> s;
	return s;
}

// getNextInt converts the next string from the input stream to an integer.
int getNextInt() {
	return stoi(getNextString());
}

// getNextInt64 converts the next string from the input stream to a 64-bit integer.
int64_t getNextInt64() {
	return stoll(getNextString());
}

// getNextUint64 converts the next string from the input stream to an unsigned 64-bit integer.
uint64_t getNextUint64() {
	return stoull(getNextString());
}

// getNextFloat64 converts the next string from the input stream to a float64.
double getNextFloat64() {
	return stod(getNextString());
}

int main() {
	// Initialize file pointers for input and output.
	FILE *fp = stdin;
	FILE *wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (getenv("MASPY") != NULL && getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (getenv("MASPYPY") != NULL && getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Solve the problem for the first time.
	solve(fp, wfp);

	// If cnt is greater than 0, solve the problem additional times.
	for (int i = 0; i < cnt; i++) {
		fprintf(wfp, "-----------------------------------\n");
		solve(fp, wfp);
	}

	// Flush the writer to ensure all output is written.
	fflush(wfp);
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(FILE *fp, FILE *wfp) {
	int k = getNextInt(); // Read the first integer k.
	int x = getNextInt(); // Read the second integer x.

	string ans = "No"; // Default answer is "No".
	if (k*500 >= x) { // Check the condition.
		ans = "Yes"; // Update answer to "Yes" if condition is met.
	}
	fprintf(wfp, "%s\n", ans.c_str()); // Output the result.
}

