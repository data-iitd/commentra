#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	// Declare variables for input values
	int N, K, R, S, P;
	string T;
	
	// Read input values: N (length of string), K (window size), R, S, P (points for each move)
	cin >> N >> K >> R >> S >> P;
	cin >> T;

	// Initialize a dictionary to count occurrences of each move
	map<string, int> dict;
	dict["r"] = 0;
	dict["s"] = 0;
	dict["p"] = 0;
	string char;
	
	// Initialize a vector to track the state of each move within the last K moves
	vector<bool> s(N); // For 's'
	vector<bool> r(N); // For 'r'
	vector<bool> p(N); // For 'p'
	
	// Initialize all moves as available (true)
	for (int i = 0; i < N; i++) {
		s[i] = true;
	}
	copy(r.begin(), s.end(), r.begin()); // Copy the initial state to r
	copy(p.begin(), s.end(), p.begin()); // Copy the initial state to p
	
	// Iterate through each character in the input string T
	for (int i = 0; i < T.length(); i++) {
		char = T[i]; // Get the current character

		// Check if we are within the bounds of K
		if (i >= K) {
			// If the current character is the same as the character K positions back
			if (char == T[i-K]) {
				// Toggle the availability of the move based on the current character
				switch (char) {
				case 's':
					if (s[i%K]) {
						s[i%K] = false; // Mark 's' as used
						continue;
					} else {
						s[i%K] = true; // Mark 's' as available again
					}

				case 'r':
					if (r[i%K]) {
						r[i%K] = false; // Mark 'r' as used
						continue;
					} else {
						r[i%K] = true; // Mark 'r' as available again
					}

				case 'p':
					if (p[i%K]) {
						p[i%K] = false; // Mark 'p' as used
						continue;
					} else {
						p[i%K] = true; // Mark 'p' as available again
					}
				}
			} else {
				// If the current character is different from the character K positions back
				switch (char) {
				case 's':
					s[i%K] = true; // Mark 's' as available
				case 'r':
					r[i%K] = true; // Mark 'r' as available
				case 'p':
					p[i%K] = true; // Mark 'p' as available
				}
			}
		}

		// Count the occurrences of each move
		switch (char) {
		case 's':
			dict["s"] = dict["s"] + 1; // Increment count for 's'
		case 'r':
			dict["r"] = dict["r"] + 1; // Increment count for 'r'
		case 'p':
			dict["p"] = dict["p"] + 1; // Increment count for 'p'
		}
	}

	// Calculate the total score based on the counts and respective points
	int res = P*dict["r"] + S*dict["p"] + R*dict["s"];
	
	// Print the final result
	cout << res << endl;

	return 0;
}

