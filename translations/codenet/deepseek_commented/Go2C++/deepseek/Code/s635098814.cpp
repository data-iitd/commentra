#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

// Constants
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = numeric_limits<long long>::max();
const long long INF_BIT60 = 1LL << 60;

// Memoization
int memo[ALPHABET_NUM];
string str;

// Main Function
void main() {
    while (getline(cin, str)) {
        for (char c : str) {
            if (islower(c)) {
                memo[c - 'a']++;
            } else if (isupper(c)) {
                memo[c - 'A']++;
            }
        }
    }

    for (int i = 0; i < ALPHABET_NUM; i++) {
        cout << char('a' + i) << " : " << memo[i] << endl;
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

