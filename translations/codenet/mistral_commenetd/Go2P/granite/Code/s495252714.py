

import sys
from bisect import bisect_left

# Initialize scanner and writer
sc = bufio.Scanner(sys.stdin)
wr = bufio.Writer(sys.stdout)

# Function to read an integer from standard input
def scanInt():
    sc.scan()
    # Convert scanned text to integer
    return int(sc.text())

# Function to read an integer64 from standard input
def scanInt64():
    sc.scan()
    # Convert scanned text to integer64
    return int(sc.text())

# Function to read n integers from standard input
def scanInts(n):
    res = []
    # Read n integers and store them in list res
    for i in range(n):
        res.append(scanInt())
    return res

# Function to print integers to standard output
def printInts(a):
    # Iterate through list a and print each integer followed by a space
    for i, e in enumerate(a):
        print(e, end=" ")
    # Print newline character and flush writer buffer
    print()
    wr.flush()

# Set scanner to scan words
sc.whitespace = " "

# Read an integer n from standard input
n = scanInt()

# Read n integers c from standard input and store them in a list
c = scanInts(n)

# Initialize answer variable to 0
ans = 0

# Sort list c in ascending order
c.sort()

# Iterate through list c and calculate answer
for i in range(n):
    # Calculate contribution of current integer to answer
    ans = (ans + (n+1-i)*c[i])%1000000007

# Calculate final answer by multiplying answer with (4^(n-1)) modulo 1000000007
print((ans*pow(4,n-1,1000000007))%1000000007)

# Constants
mod = 1000000007

# Function to calculate modular exponentiation
def modpow(a,n):
    # Initialize result to 1
    res = 1

    # If n is 0, return result
    if n == 0: return res

    # If n is 1, return a
    if n == 1: return a

    # If n is odd, multiply result with a multiplied by itself recursively
    if n&1 == 1:
        res = res*a%mod
        a = a*a%mod
        n = n>>1
        res = res*modpow(a,n)%mod

    # If n is even, square result and recursively call function for n/2
    else:
        a = a*a%mod
        n = n>>1
        res = modpow(a,n)%mod

    # Return result
    return res

# End of code
