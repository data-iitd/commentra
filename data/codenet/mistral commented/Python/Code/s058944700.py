# -*- coding: utf-8 -*-
# Import NumPy library for numerical computations
import numpy as np

# Read input values n and k from standard input
n, k = map(int, input().split())

# Check if n is greater than k
if n > k:
    # Calculate the remainder of n divided by k
    tmp = n % k
    
    # If the remainder is greater than or equal to k - tmp,
    # set ans to k - tmp
    if tmp >= k - tmp:
        ans = k - tmp
    # Otherwise, set ans to tmp
    else:
        ans = tmp
# If n is less than k, check if n is greater than or equal to k - n
elif n < k:
    if n >= k - n:
        ans = k - n
    else:
        ans = n
# If n is equal to k, set ans to 0
else:
    ans = 0

# Print the value of ans
print(ans)
