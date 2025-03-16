import sys 

# Define the modulo constant for calculations to prevent overflow
mod = 1000000007

# Initialize scanner to read input values
sc = sys.stdin

# Read the values of n and k from input
n, k = map(int, sc.readline().split())

# Close the scanner as we no longer need input
sc.close()

# Create a list to store the lengths of segments
len = []

# Initialize the starting point for segment calculation
l = 1

# Calculate the lengths of segments based on the value of n
while l <= n:
    # Calculate the right endpoint of the current segment
    r = n // (n // l)
    # Add the length of the current segment to the list
    len.append(r - l + 1)
    # Move to the next segment
    l = r + 1

# Get the total number of segments calculated
q = len.__len__()

# Initialize a dynamic programming array to store results
dp = [0] * (k * (q + 1))

# Fill the dp array for the first segment
for j in range(1, q + 1):
    dp[j] = len[j - 1] + dp[j - 1]

# Fill the dp array for subsequent segments
for i in range(1, k):
    for j in range(1, q + 1):
        # Calculate the number of ways to form segments
        dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1]
        # Apply modulo to keep the value within limits
        dp[i * (q + 1) + j] %= mod

# Output the final result, which is the number of ways to form k segments
print(dp[k * (q + 1) - 1])

