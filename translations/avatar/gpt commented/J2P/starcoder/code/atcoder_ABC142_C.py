
# Importing necessary classes from the sys and collections packages
import sys
from collections import OrderedDict

# Reading the number of elements (N) from the input
N = int(input())

# Creating an OrderedDict to store the mapping of integer values to their order of input
idorder = OrderedDict()

# Looping through the range from 1 to N to read N integers
for i in range(1, N + 1):
    # Reading an integer A from the input
    A = int(input())
    # Storing the integer A in the map with its order of input (i)
    idorder[A] = i

# Looping through the range from 1 to N to print the order of each integer
for i in range(1, N + 1):
    # Retrieving and printing the order of the integer i from the map
    print(idorder[i], end=" ")

# 