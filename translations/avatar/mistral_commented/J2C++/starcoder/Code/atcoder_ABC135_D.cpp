
#include <bits/stdc++.h>

using namespace std;

// Final constant for the modulus value
const long long MOD = (long long) 1e9 + 7;

// Method to run the program
void run() {
 string s;
 cin >> s;
 long long base = 1;
 vector<vector<long long>> dp(s.length(), vector<long long>(13));

 // Iterate through each character in the string s
 for (int i = 0; i < s.length(); ++i) {
 if (s[s.length() - 1 - i] == '?') { // If the current character is a '?'
 for (int pre = 0; pre < 13; ++pre) { // Iterate through all possible values of pre (from 0 to 12)
 for (int next = 0; next < 10; ++next) { // Iterate through all possible values of next (from 0 to 9)
 dp[i][(base * next + pre) % 13] += // Add the contribution of the current character to the dp array
 (i > 0? dp[i - 1][pre] : // If i is not the first character, add the contribution of the previous character
 (pre == 0? 1 : 0)); // If pre is 0, add a constant value of 1
 dp[i][(base * next + pre) % 13] %= MOD; // Perform modulo operation to keep the result within the range of MOD
 }
 }
 } else { // If the current character is not a '?'
 int next = s[s.length() - 1 - i] - '0'; // Convert the digit character to an integer and subtract '0' to get the actual value
 for (int pre = 0; pre < 13; ++pre) { // Iterate through all possible values of pre (from 0 to 12)
 dp[i][(base * next + pre) % 13] += // Add the contribution of the current character to the dp array
 (i > 0? dp[i - 1][pre] : // If i is not the first character, add the contribution of the previous character
 (pre == 0? 1 : 0)); // If pre is 0, add a constant value of 1
 dp[i][(base * next + pre) % 13] %= MOD; // Perform modulo operation to keep the result within the range of MOD
 }
 }
 base = base * 10 % 13; // Multiply the base by 10 and take the result modulo 13 to update the base for the next character
 }

 // Print the final result
 cout << dp[dp.length - 1][5] << endl;
}

