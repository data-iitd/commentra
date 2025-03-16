#######
# Code
#######

# Import necessary libraries
import sys
# from collections import defaultdict, deque
# import math
# import copy
from bisect import bisect_left, bisect_right
# import heapq

# Set recursion limit (for large input)
# sys.setrecursionlimit(1000000)

# Input aliases
# input: read input as string
input = sys.stdin.readline

# getS: read input as string and strip leading/trailing whitespaces
getS = lambda: input().strip()

# getN: read input as integer
getN = lambda: int(input())

# getList: read input as list of integers
getList = lambda: list(map(int, input().split()))

# getZList: read input as list of zero-based indices
getZList = lambda: [int(x) - 1 for x in input().split()]

# Constants
INF = 10 ** 20
MOD = 1000000007

# Function to solve a single test case
def solve():
    # Read input
    n = getN()

    # Initialize dynamic programming array
    dp = [-INF]

    # Process input
    for i in range(n):
        # Read next number
        num = getN()

        # Flip its sign
        num = -num

        # Binary search for the index where num should be inserted in dp
        if num >= dp[-1]:
            dp.append(num)
        else:
            idx = bisect_right(dp, num)
            dp[idx] = num

    # Print result
    print(len(dp) - 1)

# Main function
def main():
    # Read number of test cases
    n = getN()

    # Process each test case
    for _ in range(n):
        solve()

# Run the main function if the script is run as the main module
if __name__ == "__main__":
    main()
