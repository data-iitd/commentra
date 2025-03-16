import sys
import re

# Function to read a single line of input
def read():
    return sys.stdin.readline().strip()

# Set the split function for the scanner to words
# (In Python, we don't need to do this explicitly as we read lines)

# Read the first integer from input
a = int(read())
# Read the second integer from input
b = int(read())

# Perform addition of the two integers
ret = a + b

# Check if the result is less than the difference between the two integers
if ret < (a - b):
    ret = a - b
# Check if the updated result is less than the product of the two integers
if ret < (a * b):
    ret = a * b

# Print the final result
print(ret)

