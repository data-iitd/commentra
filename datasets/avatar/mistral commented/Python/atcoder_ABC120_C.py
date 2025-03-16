# Import necessary libraries and modules
from collections import deque, Counter
from itertools import product, permutations, combinations
from operator import itemgetter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right, bisect
from fractions import gcd
from math import ceil, floor, sqrt, cos, sin, pi, factorial
import sys

# Set up input reading functions
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 8)

# Define constants
INF = float('inf')
MOD = 10 ** 9 + 7

# Define main function
def main():
    # Read input string
    s = input()

    # Check if all characters in the string are the same
    if len(set(s)) == 1:
        # If so, print 0 and exit
        print(0)
        sys.exit()

    # Count the occurrences of each character in the string
    a = Counter(s)

    # Calculate the answer
    ans = min(a.values()) * 2

    # Print the answer
    print(ans)

# Call the main function if the script is run as the main program
if __name__ == '__main__':
    main()
