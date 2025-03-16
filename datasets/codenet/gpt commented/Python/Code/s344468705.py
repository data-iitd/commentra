import sys
# Importing necessary modules
# from collections import defaultdict, deque
# import math
# import copy
from bisect import bisect_left, bisect_right
# import heapq

# Setting the recursion limit for deep recursions (commented out as it's not used)
# sys.setrecursionlimit(1000000)

# Input aliases for convenience
input = sys.stdin.readline
getS = lambda: input().strip()  # Function to get a single string input
getN = lambda: int(input())      # Function to get a single integer input
getList = lambda: list(map(int, input().split()))  # Function to get a list of integers
getZList = lambda: [int(x) - 1 for x in input().split()]  # Function to get a zero-indexed list of integers

# Constants for the algorithm
INF = 10 ** 20  # A large number representing infinity
MOD = 1000000007  # A common modulus used in competitive programming

def solve():
    # Read the number of elements
    n = getN()
    
    # Initialize a list to keep track of the longest decreasing subsequence
    dp = [-INF]  # Start with a value less than any possible input
    
    # Process each number to find the longest decreasing subsequence
    for i in range(n):
        num = getN()  # Read the next number
        num = -num    # Negate the number to convert the problem to finding the longest increasing subsequence
        
        # If the current number is greater than or equal to the last element in dp, append it
        if num >= dp[-1]:
            dp.append(num)
        else:
            # Find the position to replace in dp using binary search
            idx = bisect_right(dp, num)
            dp[idx] = num  # Replace the found position with the current number

    # Output the length of the longest decreasing subsequence found
    print(len(dp) - 1)  # Subtract 1 because dp[0] is a placeholder
    return

def main():
    # Read the number of test cases
    n = getN()
    
    # Solve each test case
    for _ in range(n):
        solve()

if __name__ == "__main__":
    # Uncomment the following line to run the main function instead of solve
    # main()
    solve()  # Directly call solve for execution
