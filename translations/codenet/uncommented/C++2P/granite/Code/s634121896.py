

# Python code

MOD = 1000000007

def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    dp = [0] * (n + 1)
    dp[0] = 1
    prev = {}
    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + (prev.get(nums[i - 1], 0)!= i - 1) * dp[prev[nums[i - 1]]]
        dp[i] %= MOD
        prev[nums[i - 1]] = i
    print(dp[n])

q = int(input())
for _ in range(q):
    solve()

