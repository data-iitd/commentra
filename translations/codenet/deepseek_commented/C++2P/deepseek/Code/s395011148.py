import sys

# Read input
N = int(input().strip())
A = list(map(int, sys.stdin.readline().strip().split()))

# Initialize dp array
INF = -(1 << 60)
dp = [[[INF] * 20 for _ in range(2)] for _ in range(N + 1)]
dp[0][0][10] = 0

# Dynamic Programming Transition
for i in range(1, N + 1):
    for j in range(6, 14):
        if dp[i - 1][0][j] != INF:
            dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i - 1])
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])
        if dp[i - 1][1][j] != INF:
            dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])

# Calculate the result
V = 10 + (N // 2) - (N - (N // 2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]
print(max(T1, T2))
