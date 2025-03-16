
#include <iostream>
#include <string>

using namespace std;

// Initializes the scanner to read from standard input efficiently.
void scanInit() {
	const int cap = 1000 * 1024;
	char buf[cap];
	cin.rdbuf()->pubsetbuf(buf, cap);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	return;
}

// Reads an integer from the input.
int nextInt() {
	int i;
	cin >> i;
	return i;
}

// Reads a string from the input.
string nextStr() {
	string s;
	cin >> s;
	return s;
}

// Main function that executes the program logic.
int main() {
	scanInit();

	// Read the input string.
	string s = nextStr();

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

