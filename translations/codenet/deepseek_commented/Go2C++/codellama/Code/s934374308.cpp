
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int N, K, R, S, P;
	string T;
	cin >> N >> K >> R >> S >> P;
	cin >> T;

	// Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
	map<string, int> dict;
	dict["r"] = 0;
	dict["s"] = 0;
	dict["p"] = 0;
	// Initialize a string to store the current character
	string char;
	// Initialize a boolean slice to keep track of the availability of each choice for each player
	bool s[N];
	// Initialize all elements of the slice to true
	for (int i = 0; i < N; i++) {
		s[i] = true;
	}
	// Create copies of the slice for 'r', 'p'
	bool r[N];
	bool p[N];
	for (int i = 0; i < N; i++) {
		r[i] = s[i];
		p[i] = s[i];
	}

	// Iterate over each character in the string T
	for (int i = 0; i < T.length(); i++) {
		char = T[i];
		// Check if the current index is greater than or equal to K
		if (i >= K) {
			// Check if the last K characters are the same as the current character
			if (char == T[i-K]) {
				// Update the availability of the choice based on the current character
				switch (char) {
				case 's':
					if (s[i%K]) {
						s[i%K] = false;
						continue;
					} else {
						s[i%K] = true;
					}
				case 'r':
					if (r[i%K]) {
						r[i%K] = false;
						continue;
					} else {
						r[i%K] = true;
					}
				case 'p':
					if (p[i%K]) {
						p[i%K] = false;
						continue;
					} else {
						p[i%K] = true;
					}
				}
			} else {
				// Set the availability of the choice based on the current character
				switch (char) {
				case 's':
					s[i%K] = true;
				case 'r':
					r[i%K] = true;
				case 'p':
					p[i%K] = true;
				}
			}
		}
		// Update the counts in the dictionary based on the current character
		switch (char) {
		case 's':
			dict["s"] = dict["s"] + 1;
		case 'r':
			dict["r"] = dict["r"] + 1;
		case 'p':
			dict["p"] = dict["p"] + 1;
		}
	}

	// Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
	int res = P*dict["r"] + S*dict["p"] + R*dict["s"];
	// Print the result
	cout << res << endl;

	return 0;
}

