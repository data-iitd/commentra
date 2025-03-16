import sys
import io
import os
import math
import bisect
import heapq
import itertools
from collections import deque, Counter, defaultdict
from functools import lru_cache
from itertools import accumulate
from decimal import Decimal

# Fast I/O
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve():
    # Input the number of test cases (if any) or the main input
    n = int(input().decode().strip())
    # Initialize the list to store the numbers
    nums = list(map(int, input().decode().strip().split()))
    # Initialize variables to keep track of the last number and the previous index of the last number
    last = 0
    # Initialize a list to store the prefix sum of the number of ways to reach each index
    dp = [0] * (n + 1)
    # Set the initial value of the prefix sum at index 0
    dp[0] = 1
    # Initialize two dictionaries to keep track of the previous index of each number and the number of ways to reach the previous index
    kek = defaultdict(int)
    prev = defaultdict(int)
    # Iterate through the numbers from 1 to n
    for i in range(1, n + 1):
        # Calculate the prefix sum at the current index by adding the number of ways to reach the previous index (if the previous number is not the same as the current number) and updating the dictionaries
        dp[i] = dp[i - 1] + (0 if prev[nums[i - 1]] != i - 1 else kek[nums[i - 1]])
        dp[i] %= 1000000007
        # Update the dictionaries
        kek[nums[i - 1]] = dp[i]
        prev[nums[i - 1]] = i
    # Output the result
    print(dp[n])

# Main function to run the program
if __name__ == "__main__":
    # Run the solve function for each test case (if any) or the main input
    q = 1
    # q = int(input().decode().strip())
    while q > 0:
        solve()
        q -= 1
