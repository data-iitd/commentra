
#include <bits/stdc++.h>
using namespace std;

// Define constants for the program.
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = numeric_limits<int64_t>::max();
const int64_t INF_BIT60 = 1LL << 60;

// Declare memoization array and string variable.
int memo[ALPHABET_NUM];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input until EOF.
    while (getline(cin, str)) {
        if (str.empty()) {
            break;
        }
        // Count occurrences of each letter.
        for (char c : str) {
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
        cout << char('a' + i) << " : " << memo[i] << endl;
    }

    return 0;
}

