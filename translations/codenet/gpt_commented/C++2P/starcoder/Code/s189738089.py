# Define a constant for infinity
INF = 1 << 30

# Function to update the minimum value
def chmin(a, b):
  if a > b:
    a = b
  return

# Read the number of steps (N) and the maximum jump distance (K)
N, K = map(int, input().split())

# Initialize a dp vector to store the minimum cost to reach each step
dp = [INF] * (N + 1)
dp[0] = 0

# Read the heights of the steps
h = list(map(int, input().split()))

# Dynamic programming to calculate the minimum cost to reach each step
for i in range(N):
  # Check possible jumps from the current step
  for j in range(1, K + 1):
    # Update the minimum cost to reach step i + j
    chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

# Output the minimum cost to reach the last step
print(dp[N - 1])

