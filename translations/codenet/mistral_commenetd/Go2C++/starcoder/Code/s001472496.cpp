
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Initialize an empty string variable to store the input string
	string s;

	// Read the input string from the standard input using cin >> s statement
	cin >> s;

	// Initialize two integer variables max_tmp and max with zero values
	int max_tmp = 0;
	int max = 0;

	// Iterate through each character in the input string using a for loop
	for (int i = 0; i < s.length(); i++) {
		// Initialize a boolean variable flag with false value
		bool flag = false;

		// Check the character type using if-else statement
		if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G') {
			// Increment the max_tmp variable by 1 for each valid character encountered
			max_tmp++;
		} else {
			// Set the flag variable to true if the character is not a valid nucleotide
			flag = true;
		}

		// Check if the current character is the last character in the input string
		if (i == s.length() - 1) {
			// Set the flag variable to true if the current character is the last character
			flag = true;
		}

		// If the flag variable is true, then the current character is not a valid nucleotide
		// So, we need to check if the max variable is less than the max_tmp value
		// If yes, then update the max variable with the max_tmp value
		if (flag == true) {
			if (max < max_tmp) {
				max = max_tmp;
			}
			// Reset the max_tmp variable to zero as we have processed the current sequence of valid nucleotides
			max_tmp = 0;
		}
	}

	// Print the maximum length of a valid sequence of nucleotides found in the input string
	cout << max << endl;

	// End of the code
}

