
N = int(input())
A = list(map(int, input().split()))

dp = [[[-10**18]*20 for _ in range(2)] for _ in range(N+1)]
dp[0][0][10] = 0

for i in range(1, N+1):
    for j in range(6, 15):
        if dp[i-1][0][j]!= -10**18:
            dp[i][1][j+1] = max(dp[i][1][j+1], dp[i-1][0][j] + A[i-1])
            dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][0][j])
        if dp[i-1][1][j]!= -10**18:
            dp[i][0][j-1] = max(dp[i][0][j-1], dp[i-1][1][j])

V = 10 + (N//2) - (N-(N//2))
T1 = dp[N][0][V]
T2 = dp[N][1][V]
print(max(T1, T2))

