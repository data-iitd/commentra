# Import necessary modules and functions
import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import groupby, accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce

# Set input parameters and initialize variables
def input():
    """
    Reads a line from standard input and returns it as a string after stripping whitespaces.
    """
    return sys.stdin.readline().strip()

N = INT()
"""
Reads the number of elements in the list A from standard input and assigns it to the variable N.
"""

A = LIST()
"""
Reads N integers from standard input and assigns them to a list A.
"""

A = [k for k, g in groupby(A)]
"""
Uses the groupby function from itertools to group consecutive equal elements in list A.
The result is a list of tuples, where the first element of each tuple is the group key (the common value of the group)
and the second element is a list of all elements in the group. We only need the keys, so we use a list comprehension
to extract them.
"""

N = len(A)
"""
Assigns the length of the list A to the variable N.
"""

i = 1
ans = 0
"""
Initializes two variables: i for the loop counter and ans for the answer counter.
"""

# Main logic
while i < N - 1:
    """
    The loop runs from i = 1 to i = N - 2.
    """

    if A[i - 1] < A[i] > A[i + 1] or A[i - 1] > A[i] < A[i + 1]:
        """
        Checks if the current element A[i] is sandwiched between two larger or smaller elements.
        """

        ans += 1
        i += 1
    """
    If the condition is true, increments the answer counter and moves to the next iteration.
    """

i += 1
"""
Moves the loop counter to the last position in the list A.
"""

print(ans + 1)
"""
Prints the final answer, which is the number of sandwiched elements plus one.
"""
