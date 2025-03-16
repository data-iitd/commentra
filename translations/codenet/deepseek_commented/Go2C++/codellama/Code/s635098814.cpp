
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int ALPHABET_NUM = 26;
const int INF_INT64 = 1LL << 60;
const int INF_BIT60 = 1LL << 60;

int memo[ALPHABET_NUM];
string str;

int main() {
	while (cin >> str) {
		if (str.size() == 0) {
			break;
		}
		for (int i = 0; i < str.size(); i++) {
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
		cout << char(i + 'a') << " : " << memo[i] << endl;
	}
}

// Constants
// The code defines constants for MOD and the number of alphabets, which can be used throughout the program.

// Memoization
// The code uses a memoization array to store counts of each letter.
// This is a common technique in competitive programming to optimize repeated calculations.

// Loop and Conditionals
// The main function reads input, processes it, and prints the results.
// This is a common structure for programs that need to handle multiple inputs.


