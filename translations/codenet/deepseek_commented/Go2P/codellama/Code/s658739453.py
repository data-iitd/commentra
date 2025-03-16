
#!/usr/bin/env python3

import sys

def main():
    n, p = map(int, input().split())
    mdans = set()
    for _ in range(p):
        mdans.add(int(input()))

    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 1

    if 1 in mdans:
        dp[1] = 0

    for i in range(2, n + 1):
        if i not in mdans:
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007

    print(dp[n])

if __name__ == '__main__':
    main()

