# Import necessary libraries
import sys

# Define long long type alias for convenience
lint = int

# Constants for large values and mathematical constants
INF = 1001001001001001
MOD = 1000000007

# Function to update the minimum value
def chmin(a, b):
    return min(a, b)

# Function to update the maximum value
def chmax(a, b):
    return max(a, b)

# Read the number of elements
n = int(input().strip())

# Initialize a list to store the input values and a list for prefix sums
a = list(map(lint, input().strip().split()))
acc = [0] * (n + 1)

# Compute prefix sums modulo MOD
for i in range(n):
    acc[i + 1] = (acc[i] + a[i]) % MOD  # Update prefix sum

# Initialize the answer variable
ans = 0

# Calculate the final answer using the prefix sums
for i in range(n):
    ans += (a[i] % MOD) * (MOD + acc[n] - acc[i + 1]) % MOD  # Update answer based on current element and remaining sum
    ans %= MOD  # Ensure the answer is within MOD

# Output the final result
print(ans)

# End of the program
# <END-OF-CODE>
