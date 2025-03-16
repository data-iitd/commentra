# Importing necessary functions
from functools import reduce
from operator import xor

# Reading input
N = int(input())
a = list(map(int, input().split()))

# Calculating the XOR of all elements in the list 'a'
total = reduce(xor, a, 0)

# Printing the result
print(" ".join(list(map(lambda ai: str(ai ^ total), a))))