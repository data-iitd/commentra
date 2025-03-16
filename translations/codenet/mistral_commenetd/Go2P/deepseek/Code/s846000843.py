import sys
import math
from itertools import accumulate

# The main function is the entry point of the program.
def main():
    # Read the number n from the standard input.
    n = int(input().strip())

    # Initialize an array aa of length n to store the input integers.
    aa = [int(input().strip()) for _ in range(n)]

    # Compute the cumulative sum of the aa array using the accumulate function from the itertools module.
    cumsum = list(accumulate(aa))

    # Initialize a variable ans to store the answer.
    ans = 2020202020

    # Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
    for i in range(1, len(cumsum) - 1):
        # Compute the absolute difference between the last cumulative sum and the current cumulative sum.
        diff1 = abs(cumsum[-1] - cumsum[i])

        # Compute the difference between the current cumulative sum and the first cumulative sum.
        diff2 = cumsum[i] - cumsum[0]

        # Keep the minimum of these two differences as the answer.
        ans = min(ans, diff1, diff2)

    # Print the answer.
    print(ans)

# The Abs function returns the absolute value of an integer.
def abs(a):
    return a if a >= 0 else -a

# The Min function returns the minimum of a list of integers.
def min(a, b):
    return a if a < b else b

# <END-OF-CODE>