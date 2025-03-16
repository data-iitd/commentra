# Import necessary libraries for various functionalities
from collections import deque
from collections import Counter
from itertools import product, permutations, combinations
from operator import itemgetter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right, bisect
from fractions import gcd
from math import ceil, floor, sqrt, cos, sin, pi, factorial
import sys

# Set up input reading methods for efficiency
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

# Set recursion limit to handle deep recursion cases
sys.setrecursionlimit(10 ** 8)

# Define constants for infinity and modulo operations
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    # Read input string
    s = input()

    # Check if all characters in the string are the same
    if len(set(s)) == 1:
        print(0)  # If true, print 0 and exit
        sys.exit()

    # Count the occurrences of each character in the string
    a = Counter(s)

    # Calculate the answer as twice the minimum frequency of any character
    ans = min(a.values()) * 2

    # Print the final answer
    print(ans)

# Entry point of the program
if __name__ == '__main__':
    main()
