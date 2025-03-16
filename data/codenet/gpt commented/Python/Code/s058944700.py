# -*- coding: utf-8 -*-
import numpy as np  # Importing the numpy library for numerical operations (not used in this code)

# Read two integers from input: n and k
n, k = map(int, input().split())

# Check if n is greater than k
if n > k:
    # Calculate the remainder of n when divided by k
    tmp = n % k
    # Determine the minimum value between tmp and k - tmp
    if tmp >= k - tmp:
        ans = k - tmp  # If tmp is greater than or equal to k - tmp, set ans to k - tmp
    else:
        ans = tmp  # Otherwise, set ans to tmp
# Check if n is less than k
elif n < k:
    # Determine the minimum value between n and k - n
    if n >= k - n:
        ans = k - n  # If n is greater than or equal to k - n, set ans to k - n
    else:
        ans = n  # Otherwise, set ans to n
# If n is equal to k
else:
    ans = 0  # If n equals k, the answer is 0

# Print the result
print(ans)
