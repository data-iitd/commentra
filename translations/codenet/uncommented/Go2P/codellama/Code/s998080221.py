
import sys

def solve():
    N, _ = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    maxProfit = 0
    maxCnt = 0
    maxA = A[N-1]
    for i in range(N-2, -1, -1):
        profit = max(0, maxA-A[i])
        if maxProfit < profit:
            maxProfit = profit
            maxCnt = 1
        elif maxProfit == profit:
            maxCnt += 1
        maxA = max(maxA, A[i])
    print(maxCnt)

solve()

