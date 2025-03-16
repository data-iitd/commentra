
# Constants and package imports
import sys

# Helper function to read input
def sc():
    return sys.stdin.readline().rstrip()

# Helper functions to read input as a word and an integer
def next():
    return sc().split()

def nextInt():
    return int(sc())

# Main function
def main():
    # Reading the first two integers h and n
    h, n = nextInt(), nextInt()

    # Initializing variable a to 0
    a = 0

    # Iterating through the array of size n and adding each integer to variable a
    for i in range(n):
        a += nextInt()

    # Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    if h > a:
        print("No")
    else:
        print("Yes")

# Calling the main function
main()

