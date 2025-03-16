import sys
import os
import io
import math
import bisect
import collections
import itertools
import heapq
import random
import time
import re
import string
import copy

# fmt.Sprintf("%b\n", 255) 	# binary expression

# I/O usage
# readString = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
readString = io.BytesIO(os.read(0, 1 << 20)).readline
readInt = lambda: int(readString().decode())
readInt2 = lambda: tuple(map(int, readString().decode().split()))
readInt3 = lambda: tuple(map(int, readString().decode().split()))
readInt4 = lambda: tuple(map(int, readString().decode().split()))
readInts = lambda: list(map(int, readString().decode().split()))
readFloat6 = lambda: float(readString().decode())
readFloat6s = lambda n: [float(readString().decode()) for _ in range(n)]
readRuneSlice = lambda: list(readString().decode().strip())

# str := ZeroPaddingRuneSlice(num, 32)
# str := PrintIntsLine(X...)

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

# init() initializes the input reader and output writer.
def init():
    global readString
    readString = io.BytesIO(os.read(0, 1 << 20)).readline

# Global variables for the problem.
a, b, c = 0, 0, 0
k = 0

# main function reads inputs, generates patterns, and checks the condition.
def main():
    global a, b, c, k
    a, b, c = readInt3()  # Read three integers a, b, and c.
    k = readInt()         # Read the integer k.

    # Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
    patterns = duplicate_patterns([0, 1, 2, 3], k)

    # Iterate through each pattern to check the condition.
    for P in patterns:
        r, g, _ = a, b, c  # Initialize r, g, and b with a, b, and c respectively.
        for i in range(len(P)):
            if P[i] == 0:
                continue  # If the operation is 0, do nothing.
            elif P[i] == 1:
                r *= 2  # Double the value of r.
            elif P[i] == 2:
                g *= 2  # Double the value of g.
            elif P[i] == 3:
                c *= 2  # Double the value of c.

        # Check if the condition b > a and c > b is met.
        if g > r and c > g:
            print("Yes")  # Print "Yes" if the condition is met.
            return
    print("No")  # Print "No" if no pattern meets the condition.

# DuplicatePatterns generates all patterns of n^k of elems([]int).
def duplicate_patterns(elems, k):
    return duplicate_rec([], elems, k)

# DFS function for DuplicatePatterns.
def duplicate_rec(pattern, elems, k):
    if len(pattern) == k:
        return [pattern]  # Return the pattern if its length equals k.

    res = []
    for e in elems:
        new_pattern = pattern + [e]  # Add the current element to the pattern.
        res.extend(duplicate_rec(new_pattern, elems, k))  # Recursively generate patterns.

    return res

# init()
init()
main()
