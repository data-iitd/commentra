# Import necessary libraries
import math
import numpy as np
from fractions import gcd
import fractions
import statistics
import collections
from functools import reduce
import itertools

# Define a constant variable N, which is the input number
N = int(input())

# Define a list A, which consists of five integers, each input as a separate line
A = [int(input()) for i in range(5)]

# Calculate the minimum value in the list A
min_value = min(A)

# Calculate the ceiling value of N divided by the minimum value in the list A
ceiling_value = math.ceil(N / min_value)

# Add 4 to the ceiling value to get the final answer
final_answer = ceiling_value + 4

# Print the final answer
print(final_answer)
