
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
key = [0] * (m + 1)
cost = [0] * (m + 1)
dp = [[float('inf')] * (m + 1) for _ in range(1 << n)]
dp[0][0] = 0

for i in range(1, m + 1):
    cost[i], b = map(int, input().split())
    for j in range(b):
        c = int(input())
        key[i] += 1 << (c - 1)

for i in range(1 << n):
    for j in range(1, m + 1):
        dp[i][j] = min(dp[i][j - 1], dp[i][j])
        dp[i | key[j]][j] = min(dp[i | key[j]][j], dp[i][j - 1] + cost[j])

if dp[(1 << n) - 1][m] == float('inf'):
    print(-1)
else:
    print(dp[(1 << n) - 1][m])

