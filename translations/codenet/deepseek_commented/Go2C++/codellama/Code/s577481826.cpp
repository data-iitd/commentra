
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to read a single line of input
string read() {
	string s;
	getline(cin, s);
	return s;
}

int main() {
	// Read the first integer from input
	int a = stoi(read());
	// Read the second integer from input
	int b = stoi(read());

	// Perform addition of the two integers
	int ret = a + b;

	// Check if the result is less than the difference between the two integers
	if (ret < (a - b)) {
		ret = a - b;
	}
	// Check if the updated result is less than the product of the two integers
	if (ret < (a * b)) {
		ret = a * b;
	}

	// Print the final result
	cout << ret << endl;
	return 0;
}

