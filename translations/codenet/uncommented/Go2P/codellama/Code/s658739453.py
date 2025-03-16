
import sys

n, p = map(int, sys.stdin.readline().split())

mdans = {}
for index in range(p):
    n1 = int(sys.stdin.readline())
    mdans[n1] = n1

dp = [0] * (n + 1)
dp[0] = 1
dp[1] = 1

if 1 in mdans:
    dp[1] = 0

for i in range(2, n + 1):
    if i in mdans:
        continue
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007

print(dp[n])

