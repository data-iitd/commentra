
import sys

# Define constants for buffer sizes
INITIAL_BUF_SIZE = 10000 # Initial buffer size for the scanner
MAX_BUF_SIZE = 10000000 # Maximum buffer size for the scanner

# Create a new scanner to read from standard input
sc = iter(sys.stdin.read().split())

# Function to read the next word from input
def next():
    return next(sc)

# Function to return the minimum of two integers
def min(x, y):
    if x > y:
        return y # Return y if x is greater
    else:
        return x # Return x otherwise

# Main function where the program execution begins
if __name__ == '__main__':
    S = next() # Read the input string

    l0, l1 = 0, 0 # Initialize counters for '0's and '1's
    # Loop through each character in the input string
    for i in range(len(S)):
        if S[i] == '0':
            l0 += 1 # Increment the counter for '0'
        else:
            l1 += 1 # Increment the counter for '1'
    # Print the result, which is twice the minimum count of '0's or '1's
    print(2 * min(l0, l1))
