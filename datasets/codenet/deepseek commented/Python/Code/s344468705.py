import sys
# from collections import defaultdict, deque
# import math
# import copy
from bisect import bisect_left, bisect_right
# import heapq

# sys.setrecursionlimit(1000000)

# input aliases
input = sys.stdin.readline

getS = lambda: input().strip()
getN = lambda: int(input())
getList = lambda: list(map(int, input().split()))
getZList = lambda: [int(x) - 1 for x in input().split()]

INF = 10 ** 20
MOD = 1000000007
def solve():
    # Read the number of elements
    n = getN()
    # Initialize dp with a single element -INF
    dp = [-INF]
    for i in range(n):
        # Read the next number and negate it
        num = getN()
        num = -num
        # If the number is greater than or equal to the last element in dp, append it
        if num >= dp[-1]:
            dp.append(num)
        else:
            # Use binary search to find the position to replace
            idx = bisect_right(dp, num)
            dp[idx] = num

    # Print the length of the longest increasing subsequence found
    print(len(dp) - 1)
    return

def main():
    # Read the number of test cases
    n = getN()
    for _ in range(n):
        solve()
if __name__ == "__main__":
    # main()
    solve()
