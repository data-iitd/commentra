import sys
from collections import defaultdict

MOD = int(1e9 + 7)

def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    dp = [0] * (n + 1)
    dp[0] = 1
    kek = defaultdict(int)
    prev = {}

    for i in range(1, n + 1):
        dp[i] = dp[i - 1] + (kek[nums[i - 1]] if prev.get(nums[i - 1], -1) != i - 1 else 0)
        dp[i] %= MOD
        kek[nums[i - 1]] = dp[i]
        prev[nums[i - 1]] = i

    print(dp[n])

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    solve()

# <END-OF-CODE>
