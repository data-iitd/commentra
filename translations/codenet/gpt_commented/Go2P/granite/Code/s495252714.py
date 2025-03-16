
import sys
from bisect import bisect_left

#=====I/O=====

# Declare reader and writer for input and output
sc = sys.stdin.buffer.readline
wr = sys.stdout.buffer.write

# Function to scan an integer from input
def scanInt():
    return int(sc().decode())

# Function to scan a 64-bit integer from input
def scanInt64():
    return int(sc().decode())

# Function to scan multiple integers from input
def scanInts(n):
    return list(map(int, sc().split()))

# Function to scan a single line of text from input
def scanText():
    return sc().decode().rstrip()

# Function to print integers to output
def printInts(a):
    wr(" ".join(map(str, a)).encode())
    wr("\n".encode())

#=====main=====

# Main function where execution starts
def main():
    n = scanInt() # Read the number of integers
    c = scanInts(n) # Read n integers into list c
    c.sort() # Sort the list of integers
    ans = 0 # Initialize answer variable
    for i in range(n):
        ans = (ans + (n+1-i)*c[i]) % 1000000007 # Update the answer using the formula
    printInts([ans * pow(4, n-1, 1000000007) % 1000000007]) # Print the final result after applying modular exponentiation

if __name__ == "__main__":
    main()

