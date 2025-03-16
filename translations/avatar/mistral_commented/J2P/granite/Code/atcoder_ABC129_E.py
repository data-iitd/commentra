

import sys

# Initialize the modulus constant M
M = 1000000007

# Read the input string and convert it to a list of characters
s = list(sys.stdin.readline().strip())

# Get the length of the list
n = len(s)

# Initialize a 2D list dp of size (n+1) x 2 to store the prefix sums
dp = [[0, 0] for _ in range(n + 1)]

# Initialize the first cell of dp with 1 in both rows
dp[0][0] = 1
dp[0][1] = 0

# Iterate through the list from index 0 to n-1
for i in range(n):
 # If the current character is '0', then both rows of dp[i+1] are copied from dp[i]
 if s[i] == '0':
 dp[i + 1][0] = dp[i][0]
 dp[i + 1][1] = dp[i][1]
 # If the current character is '1', then the first row of dp[i+1] is updated by adding the prefix sums of dp[i]
 else:
 dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M
 # If the current character is '0', then the second row of dp[i+1] is updated by adding twice the second row of dp[i] and taking the modulo M
 if s[i] == '0':
 dp[i + 1][1] += (dp[i][1] * 2) % M
 dp[i + 1][1] %= M
 # If the current character is '1', then both rows of dp[i+1] are updated by adding twice the corresponding rows of dp[i] and taking the modulo M
 else:
 dp[i + 1][0] += (dp[i][0] * 2) % M
 dp[i + 1][1] += (dp[i][1] * 2) % M
 dp[i + 1][0] %= M
 dp[i + 1][1] %= M

# Print the final result which is the sum of dp[n][0] and dp[n][1] modulo M
print((dp[n][0] + dp[n][1]) % M)
