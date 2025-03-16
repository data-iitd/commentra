
#include <stdio.h>
#include <stdlib.h>

int main() {
 // Initialize the scanner to read input from standard input
 int n;
 scanf("%d", &n);
 char s[n + 1];
 scanf("%s", s);

 // Initialize a 2D array dp of size (n+1) x 2 to store the prefix sums
 int dp[n + 1][2];

 // Initialize the first cell of dp with 1 in both rows
 dp[0][0] = 1;
 dp[0][1] = 0;

 // Iterate through the character array from index 0 to n-1
 for (int i = 0; i < n; i++) {
 // If the current character is '0', then both rows of dp[i+1] are copied from dp[i]
 if (s[i] == '0') {
 dp[i + 1][0] = dp[i][0];
 dp[i + 1][1] = dp[i][1];
 }

 // If the current character is '1', then the first row of dp[i+1] is updated by adding the prefix sums of dp[i]
 else {
 dp[i + 1][1] = (dp[i][0] + dp[i][1]) % 1000000007;
 }

 // If the current character is '0', then the second row of dp[i+1] is updated by adding twice the second row of dp[i] and taking the modulo 1000000007
 if (s[i] == '0') {
 dp[i + 1][1] += (dp[i][1] * 2) % 1000000007;
 dp[i + 1][1] %= 1000000007;
 }

 // If the current character is '1', then both rows of dp[i+1] are updated by adding twice the corresponding rows of dp[i] and taking the modulo 1000000007
 else {
 dp[i + 1][0] += (dp[i][0] * 2) % 1000000007;
 dp[i + 1][1] += (dp[i][1] * 2) % 1000000007;
 dp[i + 1][0] %= 1000000007;
 dp[i + 1][1] %= 1000000007;
 }
 }

 // Print the final result which is the sum of dp[n][0] and dp[n][1] modulo 1000000007
 printf("%d\n", (dp[n][0] + dp[n][1]) % 1000000007);
}

