
import sys
import os
import math
import operator
import bisect
import random
import re
import heapq
import functools
import itertools
import collections
import statistics

def main():
    # Read input: number of elements n and the number of summands k
    n, k = map(int, input().split())

    # Read input array a of size n
    a = list(map(int, input().split()))

    # Sort the array a in parallel using sorted()
    a.sort()

    # Calculate the answer: sum of first k elements of sorted array a
    ans = sum(a[:k])

    # Write the answer to the output stream
    print(ans)

if __name__ == "__main__":
    main()

