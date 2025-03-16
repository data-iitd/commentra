#include <stdio.h>
#include <string.h>

#define M 1000000007

int main() {
 char s[100001];
 int dp[100001][2];
 int n;

 // Read the input string
 scanf("%s", s);

 // Get the length of the string
 n = strlen(s);

 // Initialize the dp array
 dp[0][0] = 1;
 dp[0][1] = 0;

 // Iterate through the string
 for (int i = 0; i < n; i++) {
 // If the current character is '0', then both rows of dp[i+1] are copied from dp[i]
 if (s[i] == '0') {
 dp[i + 1][0] = dp[i][0];
 dp[i + 1][1] = dp[i][1];
 }

 // If the current character is '1', then the first row of dp[i+1] is updated by adding the prefix sums of dp[i]
 else {
 dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M;
 }

 // If the current character is '0', then the second row of dp[i+1] is updated by adding twice the second row of dp[i] and taking the modulo M
 if (s[i] == '0') {
 dp[i + 1][1] += (dp[i][1] * 2) % M;
 dp[i + 1][1] %= M;
 }

 // If the current character is '1', then both rows of dp[i+1] are updated by adding twice the corresponding rows of dp[i] and taking the modulo M
 else {
 dp[i + 1][0] += (dp[i][0] * 2) % M;
 dp[i + 1][1] += (dp[i][1] * 2) % M;
 dp[i + 1][0] %= M;
 dp[i + 1][1] %= M;
 }
 }

 // Print the final result which is the sum of dp[n][0] and dp[n][1] modulo M
 printf("%d\n", (dp[n][0] + dp[n][1]) % M);

 return 0;
}
