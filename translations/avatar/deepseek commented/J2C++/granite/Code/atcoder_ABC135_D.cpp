
#include <bits/stdc++.h>
using namespace std;

// MOD constant with value 10^9 + 7
const long long MOD = ( long long ) 1e9 + 7 ;

// Main logic of the program
void run() {
    string s;
    cin >> s;

    // 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
    vector<vector<long long>> dp(s.length(), vector<long long>(13));

    // Initialize the base variable to represent the current power of 10
    int base = 1;

    // Loop through the string from the least significant digit to the most significant digit
    for (int i = 0; i < s.length(); ++i) {
        if (s[s.length() - 1 - i] == '?') {
            // If the current character is '?', we iterate through all possible digits (0-9)
            for (int pre = 0; pre < 13; ++pre) {
                for (int next = 0; next < 10; ++next) {
                    dp[i][(base * next + pre) % 13] += (i > 0? dp[i - 1][pre] : (pre == 0? 1 : 0));
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            // If the current character is not '?', we update the dp array based on the actual digit
            int next = s[s.length() - 1 - i] - '0';
            for (int pre = 0; pre < 13; ++pre) {
                dp[i][(base * next + pre) % 13] += (i > 0? dp[i - 1][pre] : (pre == 0? 1 : 0));
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        // Update the base variable to the next power of 10 modulo 13
        base = base * 10 % 13;
    }

    // Print the number of ways to achieve the remainder 5 when the number is divided by 13
    cout << dp[s.length() - 1][5] << endl;
}

int main() {
    run();
    return 0;
}

// Method to print debug information (optional)
void tr(vector<vector<long long>> v) {
    for (auto &row : v) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Method to print debug information (optional)
void tr(vector<long long> v) {
    for (auto &val : v) {
        cout << val << " ";
    }
    cout << endl;
}

// Method to print debug information (optional)
void tr(long long...