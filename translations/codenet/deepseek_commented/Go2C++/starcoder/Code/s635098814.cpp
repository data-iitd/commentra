#include <bits/stdc++.h>

using namespace std;

// Constants
// The code defines constants for MOD and the number of alphabets, which can be used throughout the program.

const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;

// Memoization
// The code uses a memoization array to store counts of each letter.
// This is a common technique in competitive programming to optimize repeated calculations.

int memo[ALPHABET_NUM];
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		getline(cin, str);
		if (str.empty()) {
			break;
		}

		for (int i = 0; i < str.length(); i++) {
			char c = str[i];

			if ('a' <= c && c <= 'z') {
				// toUpper
				// c-('a'-'A')
				memo[c - 'a']++;
			} else if ('A' <= c && c <= 'Z') {
				// toLower
				// c+('a'-'A')
				memo[c - 'A']++;
			} else {
				// stay
				// c
				continue;
			}
		}
	}

	for (int i = 0; i < ALPHABET_NUM; i++) {
		cout << (char)(i + 'a') << " : " << memo[i] << endl;
	}
}

// Loop and Conditionals
// The main function reads input, processes it, and prints the results.
// This is a common structure for programs that need to handle multiple inputs.

