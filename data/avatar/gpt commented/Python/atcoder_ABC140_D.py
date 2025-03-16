from _collections import deque

# Generator function to parse input data
def parser():
    while 1:
        # Read input and split it into a list of strings
        data = list(input().split(' '))
        # Yield each non-empty string as a separate value
        for number in data:
            if len(number) > 0:
                yield (number)

# Create an instance of the input parser generator
input_parser = parser()

# Function to get the next value from the input parser as a string
def gw():
    global input_parser
    return next(input_parser)

# Function to get the next value from the input parser and convert it to an integer
def gi():
    data = gw()
    return int(data)

# Define a constant for the modulo operation
MOD = int(1e9 + 7)

# Import necessary libraries
import numpy
import scipy
from collections import deque

# Read the number of elements N and the integer K from input
N = gi()
K = gi()
# Read the string S from input
S = gw()

# Initialize a counter for segments
seg_cnt = 0

# Count the number of segments in the string S
for i in range(0, N - 1):
    if S[i] != S[i + 1]:
        seg_cnt += 1

# Calculate the current happiness based on the number of segments
cur_happy = N - 1 - seg_cnt

# Determine the final answer based on the relationship between K and seg_cnt
if 2 * K >= seg_cnt:
    ans = N - 1  # If K is sufficient to cover all segments
else:
    ans = cur_happy + 2 * K  # Otherwise, calculate based on current happiness and K

# Print the final answer
print(ans)
