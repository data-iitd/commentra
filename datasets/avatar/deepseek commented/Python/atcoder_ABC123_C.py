
import math
import numpy as np
from fractions import gcd
import fractions
import statistics
import collections
from functools import reduce
import itertools

# Step 1: Import necessary modules for mathematical operations, numerical computations, and data structures.

N = int(input())

# Step 2: Read an integer input N which represents some quantity or value.

A = [int(input()) for i in range(5)]

# Step 3: Read five integer inputs and store them in a list A. This list will be used to determine the minimum value among these integers.

print(math.ceil(N / min(A)) + 4)

# Step 4: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.
