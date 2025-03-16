
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

// Function to calculate the absolute value of an integer
int absint(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// Function to read the next integer from the scanner
int getNextInt(ifstream &scanner) {
	int i;
	scanner >> i;
	return i;
}

// Function to read the next int64 from the scanner
int64_t getNextInt64(ifstream &scanner) {
	int64_t i;
	scanner >> i;
	return i;
}

// Function to read the next string from the scanner
string getNextString(ifstream &scanner) {
	string s;
	scanner >> s;
	return s;
}

// Function to create a new bufio.Scanner from a file pointer
ifstream getScanner(ifstream &fp) {
	ifstream scanner(fp);
	scanner.sync_with_stdio(false);
	scanner.tie(0);
	return scanner;
}

// Main function
int main() {
	// Open the standard input as a file
	ifstream fp(stdin);
	// If there is an argument, open the file with that name instead
	if (argc > 1) {
		fp.open(argv[1]);
	}

	// Create a new bufio.Scanner from the file pointer
	ifstream scanner = getScanner(fp);

	// Create a new bufio.Writer for output
	ofstream writer(stdout);

	// Read the first integer from the input
	int n = getNextInt(scanner);

	// Initialize an array 'aa' of size 'n+2'
	int aa[n+2];
	// Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
	int sum = 0;

	// Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
	for (int i = 0; i < n; i++) {
		// Read the next integer from the scanner and store it in 'aa[i+1]'
		aa[i+1] = getNextInt(scanner);
		// Calculate the absolute difference between the current and previous elements and add it to the sum
		sum += absint(aa[i+1] - aa[i]);
	}
	// Calculate the absolute difference between the last two elements and add it to the sum
	sum += absint(aa[n+1] - aa[n]);

	// Iterate through the array 'aa' and print the answer for each subarray
	for (int i = 1; i < n+1; i++) {
		// Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
		int ans = sum - absint(aa[i+1]-aa[i]) - absint(aa[i]-aa[i-1]) + absint(aa[i+1]-aa[i-1]);
		// Write the answer to the output writer
		writer << ans << endl;
	}

	// Flush the buffer to write all the data to the output
	writer.flush();

	return 0;
}

