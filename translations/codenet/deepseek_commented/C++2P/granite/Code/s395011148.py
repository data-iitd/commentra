
N = int(input())
A = list(map(int, input().split()))

dp = [[[-float('inf') for _ in range(20)] for _ in range(2)] for _ in range(N+1)]
dp[0][0][10] = 0

for i in range(1, N+1):
    for j in range(6, 15):
        if dp[i-1][0][j]!= -float('inf'):
            dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j] + A[i-1])
            dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
        if dp[i-1][1][j]!= -float('inf'):
            dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])

V = 10 + (N//2) - (N - (N//2))
print(max(dp[N][0][V], dp[N][1][V]))

