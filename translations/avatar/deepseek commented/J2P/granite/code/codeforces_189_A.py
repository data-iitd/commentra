

n = int(input())
maxn = 4010
a = int(input())
b = int(input())
c = int(input())

arr = [a, b, c]
dp = [0] * maxn

for i in range(3):
    for j in range(arr[i], maxn):
        dp[j] = max(dp[j], dp[j - arr[i]] + 1)

print(dp[n])

