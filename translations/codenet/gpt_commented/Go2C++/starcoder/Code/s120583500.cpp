#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Declare a variable to hold the input string
	string s;
	// Read input from the user
	cin >> s;

	// Initialize a counter for consecutive valid characters and a vector to hold counts
	int count = 0;
	vector<int> counter;

	// If the input string is empty, exit the function
	if (s == "") {
		return 0;
	}

	// Start the counter with an initial value of 0
	counter.push_back(0);
	// Split the input string into a vector of individual characters
	vector<string> li = split(s, "");

	// Iterate over each character in the vector
	for (int i = 0; i < li.size(); i++) {
		// Check if the character is one of the valid DNA bases
		if (li[i] == "A" || li[i] == "C" || li[i] == "G" || li[i] == "T") {
			// Increment the count for consecutive valid characters
			count++;
		} else {
			// If an invalid character is encountered, store the current count
			counter.push_back(count);
			// Reset the count for the next sequence
			count = 0;
		}
	}

	// Append the count of the last sequence of valid characters
	counter.push_back(count);
	// Sort the counts to find the maximum consecutive valid characters
	sort(counter.begin(), counter.end());
	// Print the maximum count of consecutive valid characters
	cout << counter[counter.size() - 1] << endl;
}

