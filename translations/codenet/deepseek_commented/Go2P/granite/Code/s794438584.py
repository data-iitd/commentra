
import math

def max(lhs, rhs):
    return int(math.max(float(lhs), float(rhs)))

N, M = map(int, input().split())
values = []
weights = []
for _ in range(N):
    w, v = map(int, input().split())
    weights.append(w)
    values.append(v)

dp = [[0 for _ in range(M+1)] for _ in range(N+1)]
for i in range(1, N+1):
    for j in range(M+1):
        dp[i][j] = dp[i-1][j]
        if j >= weights[i-1]:
            dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1])

print(dp[N][M])

