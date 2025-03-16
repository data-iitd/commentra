
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define constants for the program.
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = 1 << 60;
const int INF_BIT60 = 1 << 60;

// Declare memoization array and string variable.
int memo[ALPHABET_NUM];
string str;

int main() {
	// Read input until EOF.
	while (cin >> str) {
		if (str.size() == 0) {
			break;
		}
		// Count occurrences of each letter.
		for (int i = 0; i < str.size(); i++) {
			char c = str[i];

			if ('a' <= c && c <= 'z') {
				// Increment count for lowercase letters.
				memo[c - 'a']++;
			} else if ('A' <= c && c <= 'Z') {
				// Increment count for uppercase letters.
				memo[c - 'A']++;
			} else {
				// Ignore non-alphabet characters.
				continue;
			}
		}
	}

	// Print the count of each letter.
	for (int i = 0; i < ALPHABET_NUM; i++) {
		cout << char(i + 'a') << " : " << memo[i] << endl;
	}
}

// MODはとったか？
// 遷移だけじゃなくて最後の最後でちゃんと取れよ？

