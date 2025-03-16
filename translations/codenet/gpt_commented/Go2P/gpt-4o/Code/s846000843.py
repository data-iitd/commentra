import sys
import math
from collections import defaultdict

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout

    def flush(self):
        self.writer.flush()

    def next_line(self):
        return self.reader.readline().strip()

    def next(self):
        return self.next_line().split()

    def int(self):
        return int(self.next()[0])

    def print_ln(self, *args):
        print(*args, file=self.writer)

def abs_value(a):
    return abs(a)

def min_value(*nums):
    if not nums:
        raise ValueError("function min() requires at least one argument.")
    return min(nums)

def cum_sum(nums):
    sums = [0]
    for num in nums:
        sums.append(sums[-1] + num)
    return sums

def main():
    io = Io()

    # Read the number of elements
    n = io.int()

    # Create a list to hold the input integers
    aa = [io.int() for _ in range(n)]

    # Compute the cumulative sum of the input integers
    cumsum = cum_sum(aa)

    # Initialize the answer with a large value
    ans = 2020202020

    # Iterate through the cumulative sums to find the minimum difference
    for i in range(1, len(cumsum) - 1):
        ans = min_value(ans, abs_value(cumsum[-1] - cumsum[i] - (cumsum[i] - cumsum[0])))

    # Output the final answer
    io.print_ln(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
