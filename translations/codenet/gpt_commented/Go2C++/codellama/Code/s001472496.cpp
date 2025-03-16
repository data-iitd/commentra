#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare a string variable to hold the input
	string s;
	// Read the input string from standard input
	cin >> s;

	// Initialize variables to track the maximum length of valid characters and the current length
	int max_tmp = 0;
	int max = 0;

	// Iterate over each character in the input string
	for (int i = 0; i < s.length(); i++) {
		// Flag to indicate if a non-valid character is encountered
		bool flag = false;

		// Check if the current character is one of the valid DNA bases
		switch (s[i]) {
		case 'A':
		case 'C':
		case 'T':
		case 'G':
			// Increment the temporary count for valid characters
			max_tmp++;
			break;
		default:
			// Set the flag to true if a non-valid character is found
			flag = true;
			break;
		}

		// Check if we are at the last character of the string
		if (i == s.length() - 1) {
			// Set the flag to true to handle the end of the string
			flag = true;
		}

		// If a non-valid character was found or we reached the end of the string
		if (flag == true) {
			// Update the maximum length if the current temporary length is greater
			if (max < max_tmp) {
				max = max_tmp;
			}
			// Reset the temporary length counter
			max_tmp = 0;
		}
	}

	// Print the maximum length of consecutive valid characters found
	cout << max << endl;

	return 0;
}

