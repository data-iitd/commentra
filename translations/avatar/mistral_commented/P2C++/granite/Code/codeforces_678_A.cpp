

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read a line of text from the standard input stream and convert it into a vector of strings
	vector<string> input;
	string line;
	getline(cin, line);
	istringstream iss(line);
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(input));

	// Convert the first element of the vector into an integer and store it in vamshi
	int vamshi = stoi(input[0]);

	// Convert the second element of the vector into an integer and store it in z
	int z = stoi(input[1]);

	// Calculate the number of complete divisions of z into vamshi
	// Add 1 to account for the remainder
	// Multiply the result by z
	int result = (vamshi / z + 1) * z;

	// Print the result to the standard output stream
	cout << result << endl;

	return 0;
}

