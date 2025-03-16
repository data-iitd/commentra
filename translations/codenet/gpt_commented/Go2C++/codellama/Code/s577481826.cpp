
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// Set the scanner to split input by whitespace (words)
	string line;
	getline(cin, line);
	stringstream ss(line);
	int a, b;
	ss >> a >> b;

	// Initialize ret with the sum of a and b
	int ret = a + b;

	// Check if ret is less than the difference of a and b
	if (ret < (a - b)) {
		ret = a - b; // Update ret to the difference if it's smaller
	}
	// Check if ret is less than the product of a and b
	if (ret < (a * b)) {
		ret = a * b; // Update ret to the product if it's smaller
	}

	// Print the final result
	cout << ret << endl;

	return 0;
}

