#include <bits/stdc++.h>

using namespace std;

// Function to create a new scanner from a file pointer
auto getScanner(FILE* fp) {
	return make_shared<stringstream>(stringstream(ios::in | ios::out));
}

// Function to read the next string from the scanner
auto getNextString(shared_ptr<stringstream> scanner) {
	return getline(*scanner, *scanner->rdbuf()).str();
}

// Function to read the next integer from the scanner
auto getNextInt(shared_ptr<stringstream> scanner) {
	int i;
	*scanner >> i;
	return i;
}

// Function to read the next integer64 from the scanner
auto getNextInt64(shared_ptr<stringstream> scanner) {
	int64_t i;
	*scanner >> i;
	return i;
}

// Function to read the next uint64 from the scanner
auto getNextUint64(shared_ptr<stringstream> scanner) {
	uint64_t i;
	*scanner >> i;
	return i;
}

// Function to read the next float64 from the scanner
auto getNextFloat64(shared_ptr<stringstream> scanner) {
	double i;
	*scanner >> i;
	return i;
}

// Main function
int main() {
	// Open the standard input and output files
	auto fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	auto wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");

	// Set the file pointers for reading and writing
	if (fp == nullptr || wfp == nullptr) {
		return 1;
	}

	// Initialize the scanner and writer
	auto scanner = getScanner(fp);
	auto writer = make_shared<ostream>(wfp);

	// Solve the problem for the given test cases
	solve(scanner, writer);

	// Flush the writer to write the output to the file
	writer->flush();
}

// Function to solve the problem for a single test case
void solve(shared_ptr<stringstream> scanner, shared_ptr<ostream> writer) {
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

