
import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

MOD = 100000007

def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    last = 0
    dp = [0] * (n + 1)
    dp[0] = 1
    kek = {}
    prev = {}
    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + (prev[nums[i - 1]]!= i - 1? kek[nums[i - 1]] : 0)
        dp[i] %= MOD
        kek[nums[i - 1]] = dp[i]
        prev[nums[i - 1]] = i
    print(dp[n])

if __name__ == "__main__":
    solve()

