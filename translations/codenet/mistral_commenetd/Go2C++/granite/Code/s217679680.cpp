

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to read an array of integers from stdin and return it
vector<int> scanArrayInt() {
	// Initialize an empty vector to store the integers
	vector<int> ret;
	// Read the input line from stdin
	string line;
	getline(cin, line);
	// Split the input line by space
	stringstream ss(line);
	string s;
	while (getline(ss, s,'')) {
		// Convert the string to integer and append it to the vector
		ret.push_back(stoi(s));
	}
	// Return the vector of integers
	return ret;
}

// Function to initialize variables and start the main logic
int main() {
	// Read the array of integers from stdin
	vector<int> arr = scanArrayInt();
	// Initialize variables a and b with the first two elements of the array
	int a = arr[0], b = arr[1];
	// Initialize variables tap and consent with default values
	int tap = 0, consent = 1;
	// Loop until consent is greater than or equal to b
	while (consent < b) {
		// Increment consent by the sum of a and consent minus one
		consent = consent + a - 1;
		// Increment tap by one for each iteration
		tap++;
	}
	// Print the result, i.e., the number of taps required
	cout << tap << endl;
	// End of code
	return 0;
}


