from _collections import deque  # Importing the deque class from the collections module for efficient queue operations

def parser():  # Defining a function to parse input data
    while True:
        data = list(input().split(' '))  # Read input, split by spaces, and convert to a list of strings
        for number in data:
            if len(number) > 0:  # Yield each non-empty string from the input data
                yield number

input_parser = parser()  # Creating an instance of the parser function

def gw():  # Define a function to get the next word from the input parser
    global input_parser
    return next(input_parser)

def gi():  # Define a function to get the next integer from the input parser
    data = gw()
    return int(data)

MOD = int(1e9 + 7)  # Define a constant for modulo operation

import numpy  # Import numpy for numerical operations
import scipy  # Import scipy for scientific computing
from collections import deque  # Import deque for efficient queue operations

N = gi()  # Read the number of elements N from the input
K = gi()  # Read the parameter K from the input
S = gw()  # Read the string S from the input

seg_cnt = 0  # Initialize a counter for the number of segments
for i in range(N - 1):  # Loop through the string to count segments
    if S[i] != S[i + 1]:  # Check if the current character is different from the next
        seg_cnt += 1  # Increment the segment counter if a change is found

cur_happy = N - 1 - seg_cnt  # Calculate the initial happiness based on the number of segments

if 2 * K >= seg_cnt:  # Check if the number of operations allows for maximum happiness
    ans = N - 1  # If yes, set the answer to the maximum possible happiness
else:
    ans = cur_happy + 2 * K  # Otherwise, adjust the happiness based on the number of operations

print(ans)  # Print the final happiness value
