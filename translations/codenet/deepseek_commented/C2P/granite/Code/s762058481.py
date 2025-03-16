
def chmin(a, b):
    if a > b:
        return b
    else:
        return a

n = int(input())  # Read the number of elements
h = [int(input()) for _ in range(n)]  # Read the heights into the h array
dp = [100000] * n  # Initialize the dp array to a large value
dp[0] = 0  # Starting point with no cost

for i in range(1, n):
    if i == 1:
        dp[1] = abs(h[1] - h[0])  # Cost to reach the first step
    else:
        dp[i] = chmin(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]))  # Calculate the minimum cost to reach the current step

print(dp[n - 1])  # Print the minimum cost to reach the last step

