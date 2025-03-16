
#include <iostream>
#include <string>

using namespace std;

int main() {
	// Read the input string.
	string s;
	cin >> s;

	// Initialize the character to check against the string.
	char c = 'a';

	// Iterate through the alphabet to find the first missing character.
	for (int j = 0; j < 26; j++) {
		bool found = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == c) {
				found = true;
				break;
			}
		}
		if (found == false) {
			cout << c << endl;
			return 0;
		}
		c++;
	}

	// If no missing character is found, print "None".
	cout << "None" << endl;
	return 0;
}

