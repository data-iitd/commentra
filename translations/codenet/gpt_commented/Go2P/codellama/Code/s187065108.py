
# Import the necessary modules
import sys

# Create a function to read an integer from standard input
def scanInt():
    return int(sys.stdin.readline())

# Create a function to read a string from standard input
def scanString():
    return sys.stdin.readline().strip()

# Create a function to read 'n' integers from standard input
def scanInts(n):
    return [int(i) for i in sys.stdin.readline().split()]

# Create a function to read 'n' strings from standard input
def scanStrings(n):
    return [sys.stdin.readline().strip() for _ in range(n)]

# Initialize the scanner to split input by words
sys.stdin = open("input.txt", "r")

# Read three integers from input: r, D, and x
r, D, x = scanInt(), scanInt(), scanInt()

# Perform calculations and print the result for 10 iterations
for i in range(1, 11):
    x = r*x - D # Update x based on the formula
    print(x) # Print the current value of x

# End of code
