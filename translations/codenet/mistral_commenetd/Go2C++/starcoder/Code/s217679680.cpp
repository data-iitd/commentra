
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
	string inputLine;
	getline(cin, inputLine);
	// Create a stringstream object
	stringstream ss(inputLine);
	// Iterate through each element in the input line
	while (ss.good()) {
		// Read the next element from the stringstream object and convert it to integer
		int i;
		ss >> i;
		// Append the integer to the vector
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
		consent = consent + a - 1;
		// Increment tap by one for each iteration
		tap++;
	}
	// Print the result, i.e., the number of taps required
	cout << tap << endl;
	return 0;
}

