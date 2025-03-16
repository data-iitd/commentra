# Constants and imports
mod = 1000000007
ioBufferSize = 1 * 1024 * 1024

# Helper function to read input
import sys
input = sys.stdin.readline

# Helper functions to read input as a word and an integer
def next():
    return input().strip()

def nextInt():
    return int(next())

# Main function
def main():
    # Reading the first two integers h and n
    h, n = map(int, input().split())

    # Initializing variable a to 0
    a = 0

    # Iterating through the array of size n and adding each integer to variable a
    for _ in range(n):
        a += nextInt()

    # Checking if h is less than or equal to the sum of all integers and printing the result accordingly.
    print("Yes" if h <= a else "No")

# Call the main function
main()
