
#include <bits/stdc++.h>

using namespace std;

// Function to create a new bufio.Scanner from a file pointer
auto getScanner(FILE *fp) {
	return make_shared<bufio::Scanner>(bufio::Scanner(fp));
}

// Function to read the next string from the scanner
string getNextString(shared_ptr<bufio::Scanner> scanner) {
	scanner->Scan();
	return scanner->Text();
}

// Function to read the next integer from the scanner
int getNextInt(shared_ptr<bufio::Scanner> scanner) {
	int i;
	istringstream iss(getNextString(scanner));
	iss >> i;
	return i;
}

// Function to read the next int64 from the scanner
int64_t getNextInt64(shared_ptr<bufio::Scanner> scanner) {
	int64_t i;
	istringstream iss(getNextString(scanner));
	iss >> i;
	return i;
}

// Main function
int main() {
	// Open the standard input as a file
	auto fp = fopen(getenv("INPUT_PATH"), "r");
	// If there is an argument, open the file with that name instead
	if (fp == nullptr) {
		fp = fopen(argv[1], "r");
	}

	// Create a new bufio.Scanner from the file pointer
	auto scanner = getScanner(fp);

	// Create a new bufio.Writer for output
	auto writer = make_shared<bufio::Writer>(bufio::Writer(stdout));

	// Read the first integer from the input
	int n = getNextInt(scanner);

	// Initialize an array 'aa' of size 'n+2'
	vector<int> aa(n+2);
	// Initialize a variable'sum' to store the sum of absolute differences between consecutive elements
	int sum = 0;

	// Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
	for (int i = 0; i < n; i++) {
		// Read the next integer from the scanner and store it in 'aa[i+1]'
		aa[i+1] = getNextInt(scanner);
		// Calculate the absolute difference between the current and previous elements and add it to the sum
		sum += abs(aa[i+1] - aa[i]);
	}
	// Calculate the absolute difference between the last two elements and add it to the sum
	sum += abs(aa[n+1] - aa[n]);

	// Iterate through the array 'aa' and print the answer for each subarray
	for (int i = 1; i < n+1; i++) {
		// Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
		int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
		// Write the answer to the output writer
		fmt::Fprintln(writer, ans);
	}

	// Flush the buffer to write all the data to the output
	writer->Flush();
}

// Function to calculate the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

