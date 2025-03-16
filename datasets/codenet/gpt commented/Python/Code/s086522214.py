# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 20:52:46 2019

@author: Owner
"""

# Import necessary libraries
import collections
import scipy.misc
import sys
import numpy as np
import math
from operator import itemgetter
import itertools
import copy

# Function to perform prime factorization of a given number
def prime_decomposition(n):
    i = 2
    table = []
    # Continue dividing n by i until i^2 is greater than n
    while i * i <= n:
        # While n is divisible by i, append i to the list and divide n by i
        while n % i == 0:
            n /= i
            table.append(int(i))
        i += 1
    # If n is still greater than 1, append it to the list (it's a prime number)
    if n > 1:
        table.append(int(n))
    return table   

# Function to return the digits of a number as a list
def digit(i):
    if i > 0:
        return digit(i//10) + [i%10]  # Recursively get digits
    else:
        return []  # Base case for recursion

# Function to find the index of the nearest value in a list to a given number
def getNearestValueIndex(list, num):
    """
    Overview: Function to get the index of the closest value to a target number in a list
    @param list: Data array
    @param num: Target value
    @return: Index of the closest value to the target
    """
    # Calculate the absolute difference between list elements and the target number,
    # then find the index of the minimum difference
    idx = np.abs(np.asarray(list) - num).argmin()
    return idx

"""
The following block of code is commented out, but it appears to handle input for a problem.
It reads values for N and X, and then reads two arrays P and Y.
It also counts occurrences of the digits '7', '5', and '3' in a string.
"""

# S = input()  # Read input string
# T = S.split('/')  # Split the input string by '/'
# date = int(T[1]+T[2])  # Combine month and day into a single integer
# Check if the date is within the Heisei era
# if date <= 430:
#     print('Heisei')  # Print Heisei if the date is valid
# else:
#     print('TBD')  # Print TBD if the date is not valid

# The following block of code is commented out, but it appears to handle sorting and dynamic programming.
# It sorts multiple arrays based on a combined key and solves a minimization problem using dynamic programming.

# ABT = zip(A, B, totAB)  # Combine arrays A, B, and totAB
# result = 0
# Sort the combined array based on the third element (totAB)
# sorted(ABT, key=itemgetter(2))
# A, B, totAB = zip(*ABT)  # Unzip the sorted arrays
# A.sort(reverse=True)  # Sort array A in descending order

# Check if a specific bit is set in a binary representation of a number
# (x >> i) & 1

# Initialize a dynamic programming array for minimization
# dp = [np.inf]*N
# for n in range(N):
#     if n == 0:
#         dp[n] = 0  # Base case for the first element
#     else:
#         for k in range(1, K+1):
#             if n-k >= 0:
#                 # Update dp[n] with the minimum cost to reach this state
#                 dp[n] = min(dp[n], dp[n-k] + abs(h[n]-h[n-k]))
#             else:
#                 break
