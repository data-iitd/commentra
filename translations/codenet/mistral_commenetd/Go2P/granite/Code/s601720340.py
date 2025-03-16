
import sys
import os
import math
import time
import random
import re
import copy
import bisect
from collections import Counter
from collections import defaultdict
from collections import deque
from functools import reduce
from itertools import combinations
from itertools import permutations
import heapq

# Define the find function to check if a given number n is present in the p slice
def find(n):
    for i in range(N):
        if n == p[i]:
            return 0
    return 1

# Define the solve function to contain the main logic of the problem
def solve():
    # Create an Io instance for reading input
    io = Io()
    defer io.Flush()

    # Parse input using the NextInt function of the Io instance
    X = io.NextInt()
    Logf("%v\n", X)
    N = io.NextInt()
    Logf("%v\n", N)
    p = [io.NextInt() for _ in range(N)]
    Logf("p %v\n", p[0:10])

    # Check if X or its neighbors are present in the p slice
    for i in range(101):
        if find(X-i) == 1:
            print(X-i)
            sys.exit(0)
        if find(X+i) == 1:
            print(X+i)
            sys.exit(0)

    # Output generation part is not present in the code
    # // OUTPUT GENERATION PART
    # ans = 0
    # print(ans)

    # If ans > 0, print "Yes" and exit; otherwise, print "No"
    # if ans > 0:
    #   print("Yes")
    # else:
    #   print("No")

# Define the main function to initialize flags for CPU and memory profiling and call the solve function
def main():
    if len(sys.argv) > 1 and sys.argv[1].startswith("input"):
        input_file = sys.argv[1]
        sys.stdin = open(input_file, "r")
    else:
        # Use the default input file
        input_file = "input.txt"

    if len(sys.argv) > 2 and sys.argv[2].startswith("output"):
        output_file = sys.argv[2]
        sys.stdout = open(output_file, "w")
    else:
        # Use the default output file
        output_file = "output.txt"

    if "-c" in sys.argv:
        cProfile.run('solve()','restats')
    else:
        solve()

# Call the main function
if __name__ == '__main__':
    main()
