

import sys
from bisect import bisect_left

def main():
    # Initialize a scanner to read input from standard input
    scanner = bufio.Scanner(sys.stdin)
    scanner.use_dict = True

    # Read the number of elements in the array from the input
    N = int(scanner.next())
    # Allocate memory for two arrays X and Y of size N
    X = [0] * N
    Y = [0] * N

    # Read N integers from the input and store them in X and Y arrays
    for i in range(N):
        X[i] = int(scanner.next())
        # Store the current element of X in Y array for sorting
        Y[i] = X[i]

    # Sort the Y array in ascending order
    Y.sort()

    # Find the median of Y array
    m1 = Y[N//2 - 1]
    m2 = Y[N//2]

    # Iterate through each element of X array and print the corresponding median value
    for i in range(N):
        if X[i] <= m1:
            # If X[i] is smaller than m1, print m2 as the answer
            print(m2)
        else:
            # If X[i] is greater than m1, print m1 as the answer
            print(m1)

# Function to read an integer from the input
def ScanInt():
    # Read the next token from standard input
    return int(sys.stdin.readline())

# Function to read a float64 from the input
def ScanFloat64():
    # Read the next token from standard input
    return float(sys.stdin.readline())

# Function to read a text from the input
def ScanText():
    # Read the next token from standard input
    return sys.stdin.readline().rstrip()

# Function to find the maximum of two integers
def Max(a, b):
    # If a is smaller than b, return b
    if a < b:
        return b
    # Otherwise, return a
    return a

# Function to find the minimum of two integers
def Min(a, b):
    # If a is greater than b, return b
    if a > b:
        return b
    # Otherwise, return a
    return a

# Function to find the absolute value of an integer
def Abs(a):
    # If a is negative, return the negative of a
    if a < 0:
        return -a
    # Otherwise, return a
    return a

# End of code
