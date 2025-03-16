import sys

n = int(sys.stdin.readline())
maxn = 4010
a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())
arr = [a, b, c]
dp = [0] * maxn

for i in range(0, n):
    dp[i] = -1

for i in range(0, 3):
    for j in range(arr[i], maxn):
        dp[j] = max(dp[j], dp[j - arr[i]] + 1)

print(dp[n])

