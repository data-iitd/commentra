
#include <iostream>
#include <string>

using namespace std;

// Function to create a new scanner from a file pointer
istream* getScanner(istream* fp) {
	return fp;
}

// Function to read the next string from the scanner
string getNextString(istream* scanner) {
	string s;
	*scanner >> s;
	return s;
}

// Function to read the next integer from the scanner
int getNextInt(istream* scanner) {
	int i;
	*scanner >> i;
	return i;
}

// Function to read the next integer64 from the scanner
int64_t getNextInt64(istream* scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// Function to read the next uint64 from the scanner
uint64_t getNextUint64(istream* scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// Function to read the next float64 from the scanner
double getNextFloat64(istream* scanner) {
	double i;
	*scanner >> i;
	return i;
}

// Main function
int main() {
	// Open the standard input and output files
	istream* fp = &cin;
	ostream* wfp = &cout;

	// Set the file pointers for reading and writing
	if (getenv("MASPY") == "ますピ") {
		fp = new ifstream(getenv("BEET_THE_HARMONY_OF_PERFECT"));
		int cnt = 2; // Number of test cases to be read
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = new ofstream(getenv("NGTKANA_IS_GENIUS10"));
		int cnt = 1; // Number of test cases to be written
	}

	// Initialize the scanner and writer
	istream* scanner = getScanner(fp);
	ostream* writer = wfp;

	// Solve the problem for the given test cases
	solve(scanner, writer);
	for (int i = 0; i < cnt; i++) {
		*writer << "-----------------------------------" << endl; // Print a separator for each test case
		solve(scanner, writer);
	}

	// Flush the writer to write the output to the file
	writer->flush();

	// Close the file pointers
	if (getenv("MASPY") == "ますピ") {
		fp->close();
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp->close();
	}

	return 0;
}

// Function to solve the problem for a single test case
void solve(istream* scanner, ostream* writer) {
	// Read the input values
	int k = getNextInt(scanner);
	int x = getNextInt(scanner);

	// Initialize the answer
	string ans = "No";

	// Check if the condition is satisfied
	if (k * 500 >= x) {
		ans = "Yes";
	}

	// Print the answer
	*writer << ans << endl;
}

