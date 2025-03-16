

import sys
import math
import bisect
import re
import heapq
import collections
import itertools
import operator
import string

def main():
    # Declare and initialize a constant integer
    num = 998244353
    # Create a BufferedReader object to read input from the standard input
    bf = sys.stdin.buffer
    # Create a PrintWriter object to write output to the standard output
    out = sys.stdout.buffer
    # Read the number of elements 'n' from the input
    n = int(bf.readline())
    # Create two ArrayList objects to store the pairs of integers
    ai = []
    bi = []
    # Read the pairs of integers from the input and store them in the ArrayList objects
    for i in range(n):
        a, b = map(int, bf.readline().split())
        ai.append(a)
        bi.append(b)
    # Sort both the ArrayList objects
    ai.sort()
    bi.sort()
    # Check if 'n' is odd or even
    if n % 2 == 1:
        # If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
        out.write(str(bi[n // 2] - ai[n // 2] + 1).encode())
    else:
        # If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        out.write(str(int(2 * (c - b) + 1)).encode())

if __name__ == "__main__":
    main()
