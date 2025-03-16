
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	// Initialize variables
	int N, K, R, S, P;
	string T;

	// Read input from standard input
	cin >> N >> K >> R >> S >> P;
	cin >> T;

	// Initialize dictionary to store the count of each character
	map<string, int> dict;
	dict["r"] = 0;
	dict["s"] = 0;
	dict["p"] = 0;

	// Initialize boolean arrays to represent the state of each character
	string char;
	bool s[N];
	bool r[N];
	bool p[N];

	// Initialize all characters to be in the 'on' state
	for (int i = 0; i < N; i++) {
		s[i] = true;
	}

	// Iterate through each character in the input string
	for (int i = 0; i < T.length(); i++) {
		// Assign the current character to a variable
		char = T[i];

		// Check if we have reached the window size
		if (i >= K) {
			// If the current character is a substring of the previous K characters, toggle the state of the character
			if (char == T[i - K]) {
				switch (char) {
				case 's':
					// Toggle the state of the character at index i%K
					if (s[i % K]) {
						s[i % K] = false;
						continue;
					}
					else {
						s[i % K] = true;
					}

				case 'r':
					// Toggle the state of the character at index i%K
					if (r[i % K]) {
						r[i % K] = false;
						continue;
					}
					else {
						r[i % K] = true;

					}

				case 'p':
					// Toggle the state of the character at index i%K
					if (p[i % K]) {
						p[i % K] = false;
						continue;
					}
					else {
						p[i % K] = true;

					}
				}

			// If the current character is not a substring of the previous K characters, update the state of the characters accordingly
			}
			else {
				switch (char) {
				case 's':
					// Set the state of the character at index i%K to 'on'
					s[i % K] = true;
				case 'r':
					// Set the state of the character at index i%K to 'on'
					r[i % K] = true;
				case 'p':
					// Set the state of the character at index i%K to 'on'
					p[i % K] = true;
				}

			}
		}

		// Update the dictionary with the count of the current character
		switch (char) {
		case 's':
			dict["s"] = dict["s"] + 1;
		case 'r':
			dict["r"] = dict["r"] + 1;
		case 'p':
			dict["p"] = dict["p"] + 1;
		}
	}

	// Calculate and print the result
	int res = P*dict["r"] + S*dict["p"] + R*dict["s"];
	cout << res << endl;

	return 0;
}

