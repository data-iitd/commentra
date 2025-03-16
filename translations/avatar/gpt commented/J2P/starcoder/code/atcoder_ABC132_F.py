import sys

# Define the modulo constant for calculations to prevent overflow
mod = 1000000000

# Read the values of n and k from input
n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

# Initialize a dynamic programming array to store results
dp = [0] * (k * (n + 1))

# Initialize the starting point for segment calculation
l = 1

# Calculate the lengths of segments based on the value of n
while l <= n:
    # Calculate the right endpoint of the current segment
    r = n // (n // l)
    # Add the length of the current segment to the list
    dp[l] = r - l + 1
    # Move to the next segment
    l = r + 1

# Get the total number of segments calculated
q = l - 1

# Fill the dp array for the first segment
for j in range(1, q + 1):
    dp[j] = dp[j] + dp[j - 1]

# Fill the dp array for subsequent segments
for i in range(1, k):
    for j in range(1, q + 1):
        # Calculate the number of ways to form segments
        dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * dp[j]
        # Apply modulo to keep the value within limits
        dp[i * (q + 1) + j] %= mod

# Output the final result, which is the number of ways to form k segments
print(dp[k * (q + 1) - 1])

# 