from functools import *
from operator import *

# Step 1: Take an integer input N, which represents the number of elements in the list.
N = int(input())

# Step 2: Take a list of integers as input and store them in the list 'a'.
a = list(map(int, input().split()))

# Step 3: Calculate the total XOR of all elements in the list 'a' using reduce and XOR operator.
total = reduce(xor, a, 0)

# Step 4: Create a new list where each element is the XOR of the original element and the total.
# Print the new list as a space-separated string.
print(" ".join(list(map(lambda ai: str(ai ^ total), a))))
