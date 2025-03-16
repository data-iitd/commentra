# Import necessary libraries
import math  # For mathematical functions
import numpy as np  # For numerical operations (not used in this code)
from fractions import gcd  # For calculating the greatest common divisor (not used in this code)
import fractions  # For working with fractions (not used in this code)
import statistics  # For statistical functions (not used in this code)
import collections  # For specialized container datatypes (not used in this code)
from functools import reduce  # For reducing a list to a single value (not used in this code)
import itertools  # For creating iterators for efficient looping (not used in this code)

# Read an integer input from the user
N = int(input())

# Read 5 integer inputs from the user and store them in a list A
A = [int(input()) for i in range(5)]

# Calculate the minimum value from the list A, divide N by this minimum value,
# take the ceiling of the result, and add 4 to it before printing the final result
print(math.ceil(N / min(A)) + 4)
