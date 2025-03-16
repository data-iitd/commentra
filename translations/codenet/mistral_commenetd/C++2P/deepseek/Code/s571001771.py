import sys
import math
import heapq
from collections import defaultdict, deque

# Define necessary data types and constants
INF = 123456789012

# Read input
n, m = map(int, sys.stdin.readline().split())

# Initialize dynamic programming table with infinite values
dp = [[INF] * (m + 1) for _ in range(1 << n)]
dp[0][0] = 0

# Read bulbs' information
key = [0] * (m + 1)
cost = [0] * (m + 1)
for i in range(1, m + 1):
    b = int(sys.stdin.readline().split()[0])
    cost[i] = int(sys.stdin.readline().split()[0])
    for _ in range(b):
        c = int(sys.stdin.readline().split()[0])
        key[i] |= (1 << (c - 1))

# Fill dynamic programming table
for i in range(1 << n):
    for j in range(1, m + 1):
        dp[i][j] = min(dp[i][j], dp[i][j - 1])
        dp[i | key[j]][j] = min(dp[i | key[j]][j], dp[i][j] + cost[j])

# Output result
if dp[(1 << n) - 1][m] == INF:
    print(-1)
else:
    print(dp[(1 << n) - 1][m])

# <END-OF-CODE>