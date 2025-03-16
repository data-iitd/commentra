#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long MOD = 1e9 + 7; // Final constant for the modulus value

int main() {
    string input;
    cin >> input; // Read the input string
    int n = input.length();
    vector<vector<long>> dp(n, vector<long>(13, 0)); // Create a 2D vector dp of size n x 13 to store the intermediate results
    long base = 1; // Initialize the base variable to 1

    // Iterate through each character in the string
    for (int i = 0; i < n; ++i) {
        if (input[n - 1 - i] == '?') { // If the current character is a '?'
            for (int pre = 0; pre < 13; ++pre) { // Iterate through all possible values of pre (from 0 to 12)
                for (int next = 0; next < 10; ++next) { // Iterate through all possible values of next (from 0 to 9)
                    dp[i][(base * next + pre) % 13] += // Add the contribution of the current character to the dp array
                        (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0)); // If i is not the first character, add the contribution of the previous character
                    dp[i][(base * next + pre) % 13] %= MOD; // Perform modulo operation to keep the result within the range of MOD
                }
            }
        } else { // If the current character is not a '?'
            int next = input[n - 1 - i] - '0'; // Convert the digit character to an integer
            for (int pre = 0; pre < 13; ++pre) { // Iterate through all possible values of pre (from 0 to 12)
                dp[i][(base * next + pre) % 13] += // Add the contribution of the current character to the dp array
                    (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0)); // If i is not the first character, add the contribution of the previous character
                dp[i][(base * next + pre) % 13] %= MOD; // Perform modulo operation to keep the result within the range of MOD
            }
        }
        base = base * 10 % 13; // Multiply the base by 10 and take the result modulo 13 to update the base for the next character
    }

    // Print the final result
    cout << dp[n - 1][5] << endl;

    return 0;
}

// <END-OF-CODE>
