
import sys
input = sys.stdin.readline

# Function to update the minimum value
def chmin(a, b):
    if a > b:
        a = b
    return a

INF = 1 << 30 # Define a constant for infinity

# Read the number of steps (N) and the maximum jump distance (K)
N, K = map(int, input().split())
h = [0] * N # Initialize a dp vector to store the minimum cost to reach each step
for i in range(N):
    h[i] = int(input()) # Read the heights of the steps

# Dynamic programming to calculate the minimum cost to reach each step
dp = [INF] * (N + 1)
dp[0] = 0 # Base case: cost to reach the first step is 0
for i in range(N):
    # Check possible jumps from the current step
    for j in range(1, K + 1):
        # Update the minimum cost to reach step i + j
        dp[i + j] = chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

# Output the minimum cost to reach the last step
print(dp[N - 1])

