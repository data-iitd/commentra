import math
import sys

# Reading the size of the array from the user
a = int(input())

# Initializing the array with the size read from the user
ar = [0] * a

# Initializing max and min to 0
max = 0
min = 0

# Filling the array with integers read from the user
for i in range(a):
    ar[i] = int(input())

# Calculating the minimum and maximum differences between consecutive elements of the array
for i in range(a):
    max = max(ar[i] - ar[0], ar[a - 1] - ar[i])  # Calculating the maximum difference
    if i == 0:
        min = ar[i + 1] - ar[i]  # Calculating the minimum difference for the first element
    elif i == a - 1:
        min = ar[i] - ar[i - 1]  # Calculating the minimum difference for the last element
    else:
        min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])  # Calculating the minimum difference for other elements
    print(min, max)  # Displaying the minimum and maximum differences

# 