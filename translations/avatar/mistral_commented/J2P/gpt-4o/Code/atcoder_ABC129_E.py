# Import the necessary module for reading input
import sys

# Initialize the modulus constant M
M = 1000000007

# Read the input string and convert it to a list of characters
s = sys.stdin.readline().strip()
n = len(s)

# Initialize a 2D list dp of size (n+1) x 2 to store the prefix sums
dp = [[0] * 2 for _ in range(n + 1)]

# Initialize the first cell of dp with 1 in both rows
dp[0][0] = 1
dp[0][1] = 0

# Iterate through the character array from index 0 to n-1
for i in range(n):
    if s[i] == '0':
        # If the current character is '0', then both rows of dp[i+1] are copied from dp[i]
        dp[i + 1][0] = dp[i][0]
        dp[i + 1][1] = dp[i][1]
        
        # Update the second row of dp[i+1]
        dp[i + 1][1] += (dp[i][1] * 2) % M
        dp[i + 1][1] %= M
    else:
        # If the current character is '1', update the first row of dp[i+1]
        dp[i + 1][1] = (dp[i][0] + dp[i][1]) % M
        
        # Update both rows of dp[i+1]
        dp[i + 1][0] += (dp[i][0] * 2) % M
        dp[i + 1][1] += (dp[i][1] * 2) % M
        dp[i + 1][0] %= M
        dp[i + 1][1] %= M

# Print the final result which is the sum of dp[n][0] and dp[n][1] modulo M
print((dp[n][0] + dp[n][1]) % M)

# <END-OF-CODE>
