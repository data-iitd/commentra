
import sys
import math
import bisect
import numpy as np
from decimal import Decimal
from numba import njit, i8, b1
MOD = 10**9 + 7
INF = float('inf')

def main():
    v1 = int(input())
    v2 = int(input())
    t = int(input())
    d = int(input())
    dp = np.full((t - 1, 1150), -INF, dtype=np.int64)
    dp[0, v1] = v1
    for i in range(1, t - 1):
        for j in range(1150):
            for x in range(d + 1):
                if j + x < 1150:
                    dp[i, j] = max(dp[i, j], dp[i - 1, j + x] + j)
            for x in range(d, -1, -1):
                if j - x >= 0:
                    dp[i, j] = max(dp[i, j], dp[i - 1, j - x] + j)
    ans = -INF
    for i in range(t - 2, t - 1):
        for j in range(1150):
            if abs(j - v2) <= d:
                ans = max(ans, dp[i, j] + v2)
    print(ans)

if __name__ == '__main__':
    main()

