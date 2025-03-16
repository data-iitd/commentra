#include <iostream>
#include <string>

using namespace std;

int main() {
	// Read a string from standard input
	string s;
	cin >> s;

	// Initialize variables to keep track of the maximum lengths
	int max_tmp = 0;
	int max = 0;

	// Iterate over each character in the string
	for (int i = 0; i < s.length(); i++) {
		bool flag = false;
		// Check if the character is one of 'A', 'C', 'T', 'G'
		switch (s[i]) {
		case 'A':
		case 'C':
		case 'T':
		case 'G':
			// Increment the temporary maximum length counter
			max_tmp++;
		default:
			// Set the flag to true if the character is not 'A', 'C', 'T', 'G'
			flag = true;
		}

		// At the end of the loop, if the flag is true, update the overall maximum length
		if (i == s.length() - 1) {
			flag = true;
		}
		if (flag == true) {
			if (max < max_tmp) {
				max = max_tmp;
			}
			// Reset the temporary maximum length counter
			max_tmp = 0;
		}
	}

	// Print the value of the overall maximum length
	cout << max << endl;

	return 0;
}

