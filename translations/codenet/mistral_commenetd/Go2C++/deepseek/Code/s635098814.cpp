#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Define constants for the program.
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = 1LL << 60;

// Declare memoization array and string variable.
int memo[ALPHABET_NUM];
string str;

int main() {
    // Read input until EOF.
    while (getline(cin, str)) {
        for (char c : str) {
            if ('a' <= c && c <= 'z') {
                // Increment count for lowercase letters.
                memo[c - 'a']++;
            } else if ('A' <= c && c <= 'Z') {
                // Increment count for uppercase letters.
                memo[c - 'A']++;
            }
        }
    }

    // Print the count of each letter.
    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << char(i + 'a') << " : " << memo[i] << endl;
    }

    return 0;
}
