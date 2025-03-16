from collections import deque  # Importing deque from collections, though it's not used in this code

# Read an integer input for the number of elements
n = int(input())

# Read a list of strings from input and split them into a list
a = list(map(str, input().split()))

# Initialize an empty list to store the rearranged elements
b = []

# Rearrange the list: take elements at odd indices, reverse them, and then append elements at even indices
b = a[1::2][::-1] + a[::2]

# Check if the length of the original list is even
if len(a) % 2 == 0:
    # If even, print the rearranged list as is
    print(' '.join(b))
else:
    # If odd, print the rearranged list in reverse order
    print(' '.join(b[::-1]))
