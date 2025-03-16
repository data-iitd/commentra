
# Importing the required libraries
import sys

# Reading input from stdin
h, a = map(int, sys.stdin.readline().split())

# Initializing a counter to keep track of the number of subtractions
num = 0

# Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
while h > 0:
    h = h - a
    num += 1

# Printing the result, which is the number of subtractions
print(num)

# 