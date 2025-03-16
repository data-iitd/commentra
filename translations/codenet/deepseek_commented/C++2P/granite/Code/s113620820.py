
# 2415.py: Sashimi

import sys

def main():
    n = int(input())
    wis = list(map(int, input().split()))
    wsums = [0] * (n + 1)
    for i in range(n):
        wsums[i + 1] = wsums[i] + wis[i]

    dp = [[float('inf')] * (n + 1) for _ in range(n)]
    ks = [[-1] * (n + 1) for _ in range(n)]
    for i in range(n):
        dp[i][i + 1] = 0
        ks[i][i + 1] = i

    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l
            wsum = wsums[j] - wsums[i]
            mind = float('inf')
            mink = -1
            for k in range(ks[i][j - 1], ks[i + 1][j] + 1):
                d = dp[i][k] + dp[k][j] + wsum
                if d < mind:
                    mind = d
                    mink = k
            dp[i][j] = mind
            ks[i][j] = mink

    print(dp[0][n])

if __name__ == '__main__':
    main()

