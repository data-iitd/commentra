import sys
import math
import heapq
from collections import defaultdict

INF = 123456789012

def main():
    n, m = map(int, sys.stdin.readline().split())
    key = [0] * 1005
    cost = [0] * 1005
    dp = [[INF] * (1005) for _ in range(1 << 12 + 5)]
    
    dp[0][0] = 0
    
    for i in range(1, m + 1):
        b = int(sys.stdin.readline().split()[0])
        cost[i] = int(sys.stdin.readline().split()[0])
        for _ in range(b):
            c = int(sys.stdin.readline().split()[0])
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
