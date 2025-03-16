
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to read an array of integers from stdin and return it
vector<int> scanArrayInt() {
	// Initialize an empty vector to store the integers
	vector<int> ret;
	// Read the input line from stdin
	string input;
	getline(cin, input);
	// Split the input line by space
	stringstream ss(input);
	string s;
	while (ss >> s) {
		// Convert the string to integer and append it to the vector
		int i = stoi(s);
		ret.push_back(i);
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
		consent += a - 1;
		// Increment tap by one for each iteration
		tap++;
	}
	// Print the result, i.e., the number of taps required
	cout << tap << endl;
	return 0;
}

