
import sys

"""
The Main class provides a solution to the wine selling problem.
Given a collection of N wines with different prices, the objective is to maximize profit by selling
one wine each year, considering the constraint that only the leftmost or rightmost wine can be sold
at any given time.

The price of the ith wine is pi, and the selling price increases by a factor of the year in which
it is sold. This class implements three approaches to solve the problem:

1. **Recursion**: A straightforward recursive method that computes the maximum profit.
   - Time Complexity: O(2^N)
   - Space Complexity: O(N) due to recursive calls.

2. **Top-Down Dynamic Programming (Memoization)**: This approach caches the results of subproblems
   to avoid redundant computations.
   - Time Complexity: O(N^2)
   - Space Complexity: O(N^2) for the storage of results and O(N) for recursion stack.

3. **Bottom-Up Dynamic Programming (Tabulation)**: This method builds a table iteratively to
   compute the maximum profit for all possible subproblems.
   - Time Complexity: O(N^2)
   - Space Complexity: O(N^2) for the table.
"""


class Main:
    def __init__(self):
        pass

    @staticmethod
    def main(args):
        # Input number of wines
        n = int(input())

        # Input wine prices
        arr = [int(x) for x in input().split()]

        # Bottom-Up Approach
        result = Main.wpbu(arr)

        # Output the maximum profit
        print("Maximum profit: " + str(result))

    @staticmethod
    def wpbu(arr):
        if arr is None or len(arr) == 0:
            raise ValueError("Input array cannot be null or empty.")
        n = len(arr)
        strg = [[0 for _ in range(n)] for _ in range(n)]

        for slide in range(0, n):
            for si in range(0, n - slide):
                ei = si + slide
                year = (n - (ei - si + 1)) + 1
                if si == ei:
                    strg[si][ei] = arr[si] * year
                else:
                    start = strg[si + 1][ei] + arr[si] * year
                    end = strg[si][ei - 1] + arr[ei] * year

                    strg[si][ei] = max(start, end)
        return strg[0][n - 1]


# 