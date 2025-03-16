#######
# Code
#######

# Import necessary libraries
from _collections import deque

# Function to parse input line by line
def parser():
# Continuously parse input lines
    while 1:
        data = list(input().split())
# Process each token in the input line
        for number in data:
# Check if the token is empty or not
            if len(number) > 0:
# Yield the token as a result of the function
                yield(number)

# Create a parser object
input_parser = parser()

# Function to get the next token from the parser
def gw():
# Get the next token from the parser
    global input_parser
    return next(input_parser)

# Function to get the next integer from the parser
def gi():
# Get the next token as a string
    data = gw()
# Convert the token to an integer
    return int(data)

# Global variables
MOD = int(1e9 + 7)

# Import additional libraries for scientific computing
import numpy
import scipy

# Define a deque for segment count
seg_cnt = deque()

# Get the number of segments in the string
N = gi()

# Get the number of queries
K = gi()

# Get the string S
S = gw()

# Initialize segment count
seg_cnt.clear()

# Iterate through the string and count the number of segments
for i in range(0, N - 1):
# Check if the current character is different from the next character
    if S[i] != S[i + 1]:
# Add 1 to the segment count
        seg_cnt.append(1)

# Calculate the current happiness
cur_happy = N - 1 - len(seg_cnt)

# Check if the number of queries is greater than or equal to the number of segments
if 2 * K >= len(seg_cnt):
# If yes, then the answer is the total number of segments
    ans = N - 1
# Otherwise, the answer is the current happiness plus twice the number of queries
else:
    ans = cur_happy + 2 * K

# Print the answer
print(ans)
