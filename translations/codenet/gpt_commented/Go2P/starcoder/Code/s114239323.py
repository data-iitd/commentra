
# <START-OF-CODE>

# Read the number of elements
N = int(input())
# Read the heights into a slice
h = list(map(int, input().split()))

# Initialize a dynamic programming slice to store minimum costs
dp = [0] * N
for i in range(N):
    dp[i] = 0 # Set initial values to zero

# Base case: cost to jump from the first to the second height
dp[1] = abs(h[0] - h[1])

# Fill the dp slice with minimum costs for each position
for i in range(2, N):
    dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]))

# Output the minimum cost to reach the last height
print(dp[N-1])

# 