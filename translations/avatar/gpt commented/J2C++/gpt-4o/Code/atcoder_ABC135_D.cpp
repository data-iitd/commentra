#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long MOD = 1e9 + 7;

int main() {
    // Read the input string
    string s;
    cin >> s;

    // Initialize a 2D vector for dynamic programming to store results
    vector<vector<long>> dp(s.length(), vector<long>(13, 0));

    // Variable to keep track of the base value for calculations
    int base = 1;

    // Iterate through the characters of the input from the last to the first
    for (int i = 0; i < s.length(); ++i) {
        // Check if the current character is a '?', which can be any digit
        if (s[s.length() - 1 - i] == '?') {
            // Loop through all possible previous remainders
            for (int pre = 0; pre < 13; ++pre) {
                // Loop through all possible next digits (0-9)
                for (int next = 0; next < 10; ++next) {
                    // Update the dp array for the current position and remainder
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                    // Ensure the result stays within the MOD limit
                    dp[i][(base * next + pre) % 13] %= MOD;
                }
            }
        } else {
            // If the character is a digit, convert it to an integer
            int next = s[s.length() - 1 - i] - '0';
            // Loop through all possible previous remainders
            for (int pre = 0; pre < 13; ++pre) {
                // Update the dp array for the current position and remainder
                dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0));
                // Ensure the result stays within the MOD limit
                dp[i][(base * next + pre) % 13] %= MOD;
            }
        }
        // Update the base value for the next iteration (moving to the next digit)
        base = base * 10 % 13;
    }

    // Output the result, which is the number of ways to form a number divisible by 13
    cout << dp[dp.size() - 1][5] << endl;

    return 0;
}

// <END-OF-CODE>
