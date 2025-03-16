# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 20:52:46 2019

@author: Owner
"""

# Import necessary modules for various functionalities
import collections
import scipy.misc
import sys
import numpy as np
import math
from operator import itemgetter
import itertools
import copy

# Function to decompose a number into its prime factors
def prime_decomposition(n):
  i = 2
  table = []
  while i * i <= n:
    while n % i == 0:
      n /= i
      table.append(int(i))
    i += 1
  if n > 1:
    table.append(int(n))
  return table   

# Function to recursively extract digits of a number
def digit(i):
    if i > 0:
        return digit(i//10) + [i%10]
    else:
        return []
    
# Function to find the index of the value closest to a given number in a list
def getNearestValueIndex(list, num):
    """
    概要: リストからある値に最も近い値のインデックスを取得する関数
    @param list: データ配列
    @param num: 対象値
    @return 対象値に最も近い値
    """
    idx = np.abs(np.asarray(list) - num).argmin()
    return idx

"""
# Read input values for N, X, and arrays x, P, Y
N, X = map(int, input().split())
x = [0]*N
x[:] = map(int, input().split())
for n in range(N):
    P[n], Y[n] = map(int, input().split())
    
# Check if a string contains the characters '7', '5', and '3' in any order
all(nstr.count(c) for c in '753')

# Sort arrays based on a specific criterion using itemgetter
ABT = zip(A, B, totAB)
result = 0
sorted(ABT,key=itemgetter(2))
A, B, totAB = zip(*ABT)
A.sort(reverse=True)

# Perform binary bit checks
(x >> i) & 1

# Dynamic programming approach to solve a minimization problem
dp = [np.inf]*N
for n in range(N):
    if n == 0:
        dp[n] = 0
    else:
        for k in range(1,K+1):
            if n-k >= 0:
                dp[n] = min(dp[n], dp[n-k] + abs(h[n]-h[n-k]))
            else:
                break
"""

# Read a date string, split it, and check if the date is before or after a certain threshold
S = input()
T = S.split('/')
date = int(T[1]+T[2])
if date <= 430:
    print('Heisei')
else:
    print('TBD')
