#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // for abs function

using namespace std;

// Function to read the next string from the input
string getNextString() {
	string line;
	getline(cin, line);
	return line;
}

// Function to read the next integer from the input
int getNextInt() {
	return stoi(getNextString());
}

// Function to read the next int64 from the input
int64_t getNextInt64() {
	return stoll(getNextString());
}

int main(int argc, char* argv[]) {
	// Open the standard input as a file
	ifstream fp;
	// If there is an argument, open the file with that name instead
	if (argc > 1) {
		fp.open(argv[1]);
		cin.rdbuf(fp.rdbuf()); // Redirect cin to read from the file
	}

	// Read the first integer from the input
	int n = getNextInt();

	// Initialize an array 'aa' of size 'n+2'
	vector<int> aa(n+2);
	// Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
	int sum = 0;

	// Read the array 'aa' and calculate the sum of absolute differences between consecutive elements
	for (int i = 0; i < n; i++) {
		// Read the next integer from the input and store it in 'aa[i+1]'
		aa[i+1] = getNextInt();
		// Calculate the absolute difference between the current and previous elements and add it to the sum
		sum += abs(aa[i+1] - aa[i]);
	}
	// Calculate the absolute difference between the last two elements and add it to the sum
	sum += abs(aa[n+1] - aa[n]);

	// Iterate through the array 'aa' and print the answer for each subarray
	for (int i = 1; i < n+1; i++) {
		// Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
		int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
		// Print the answer
		cout << ans << endl;
	}

	return 0;
}
