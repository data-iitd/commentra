
#include <bits/stdc++.h>

using namespace std;

// Function to read an integer from standard input
int nextInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read a string from standard input
string nextStr() {
	string s;
	cin >> s;
	return s;
}

// Main function
int main() {
	// Read the first string from standard input
	string s = nextStr();

	// Initialize variable c with 'a'
	char c = 'a';

	// Check all characters from 'a' to 'z' in the string s
	for (int j = 0; j < 26; j++) {
		// Initialize variable found as false
		bool found = false;

		// Iterate through each character in the string s
		for (int i = 0; i < s.length(); i++) {
			// If current character matches c, set found to true and break the loop
			if (s[i] == c) {
				found = true;
				break;
			}
		}

		// If character c is not found in the string s, print it and return
		if (found == false) {
			cout << c << endl;
			return 0;
		}

		// Increment variable c
		c++;
	}

	// If no character from 'a' to 'z' is found in the string s, print "None"
	cout << "None" << endl;
}

