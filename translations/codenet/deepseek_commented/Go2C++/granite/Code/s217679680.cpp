
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> scanArrayInt() {
	string line;
	getline(cin, line); // Read a line of input
	stringstream ss(line); // Create a stringstream from the input line
	vector<int> ret; // Initialize an empty vector to store the integers
	string s; // Initialize a string to store each part of the input
	while (getline(ss, s,'')) { // Split the input by spaces
		ret.push_back(stoi(s)); // Convert each part to an integer and append it to the vector
	}
	return ret; // Return the vector of integers
}

int main() {
	vector<int> arr = scanArrayInt(); // Call the function to get the input array of integers
	int a = arr[0], b = arr[1]; // Extract the two integers from the input array
	int tap = 0; // Initialize the tap counter
	int consent = 1; // Initialize the consent level
	while (consent < b) { // Loop until consent reaches or exceeds b
		consent = consent + a - 1; // Increment consent by a - 1
		tap++; // Increment the tap counter
	}
	cout << tap << endl; // Print the number of taps needed
	return 0;
}

