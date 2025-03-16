
# Define the minimum update function
def chmin(a, b):
  # Minimum update function
  if a > b: a = b
  return

# Define the main function
def main():
  # Initialize dynamic programming vector dp with initial value INF for all indices
  dp = [INF] * 101000
  dp[0] = 0

  # Read input
  N, K = map(int, raw_input().split()) # Number of elements in the array and the size of the window
  h = map(int, raw_input().split()) # Array of heights

  # Dynamic programming calculation
  for i in range(N): # Iterate through all indices i
    for j in range(1, K + 1): # Iterate through all window sizes j
      # Update dp[i + j] with the minimum cost to reach this index with window size j
      chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]))

  # Output the result
  print dp[N - 1] # Print the minimum cost to reach the last index with window size K
  return 0

