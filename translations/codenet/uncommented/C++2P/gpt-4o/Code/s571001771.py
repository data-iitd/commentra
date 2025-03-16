import sys

INF = 123456789012

def main():
    n, m = map(int, input().split())
    dp = [[INF] * (m + 1) for _ in range(1 << n)]
    dp[0][0] = 0

    cost = [0] * (m + 1)
    key = [0] * (m + 1)

    for i in range(1, m + 1):
        b = int(input())
        cost[i], b = map(int, input().split())
        for _ in range(b):
            c = int(input())
            key[i] |= (1 << (c - 1))

    for i in range(1 << n):
        for j in range(m):
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])

    if dp[(1 << n) - 1][m] == INF:
        print(-1)
    else:
        print(dp[(1 << n) - 1][m])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
