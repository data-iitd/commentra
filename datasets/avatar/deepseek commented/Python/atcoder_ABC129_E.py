mod = 10 ** 9 + 7  # Set the modulus to a large prime number
l = input()  # Read the input string
n = len(l)  # Calculate the length of the input string

# Initialize the dynamic programming table
dp = [[0] * 2 for _ in range(n + 1)]
dp[0][0] = 1  # Base case: one empty sequence

# Iterate over each character in the input string
for i, c in enumerate(l):
    if c == '0':
        dp[i + 1][0] += dp[i][0]  # Add sequences ending with zero
        dp[i + 1][1] += dp[i][1] * 3  # Triple sequences ending with one
    else:
        dp[i + 1][0] += dp[i][0] * 2  # Double sequences ending with zero
        dp[i + 1][1] += dp[i][0]  # Add sequences ending with zero
        dp[i + 1][1] += dp[i][1] * 3  # Triple sequences ending with one
    
    # Take modulo to prevent overflow
    dp[i + 1][0] %= mod
    dp[i + 1][1] %= mod

# Calculate and print the final result
result = (dp[n][0] + dp[n][1]) % mod
print(result)
