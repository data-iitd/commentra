
import sys

n = int(sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))

dp = [0] * 4010

for i in range(3):
    for j in range(arr[i], len(dp)):
        dp[j] = max(dp[j], dp[j - arr[i]] + 1)

print(dp[n])

