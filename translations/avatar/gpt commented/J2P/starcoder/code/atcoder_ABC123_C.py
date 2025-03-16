import sys
import math
import random
import time

# Create a Scanner object for user input
sc = sys.stdin

# Read a long integer N from user input
N = int(sc.readline())

# Initialize a variable to hold the minimum value
min = 0

# Loop to read five long integers and find the minimum
for i in range(5):
    # For the first iteration, directly assign the value to min
    if i == 0:
        min = int(sc.readline())
    else:
        # For subsequent iterations, update min if a smaller value is found
        min = min if min < int(sc.readline()) else int(sc.readline())

# Calculate the result by dividing N by min, rounding up, and adding 4
print(math.ceil(N / min) + 4)

# 