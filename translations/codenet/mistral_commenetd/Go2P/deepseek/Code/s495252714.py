import sys
import math

#=====I/O=====

# Initialize reader and writer
reader = sys.stdin
writer = sys.stdout

# Function to read an integer from standard input
def read_int():
    return int(reader.readline().strip())

# Function to read an integer64 from standard input
def read_int64():
    return int(reader.readline().strip())

# Function to read n integers from standard input
def read_ints(n):
    return list(map(int, reader.readline().strip().split()))

# Function to print integers to standard output
def print_ints(a, **kwargs):
    writer.write(' '.join(map(str, a)) + '\n')
    writer.flush()

#=====main=====

# Set reader to read words

# Read an integer n from standard input
n = read_int()

# Read n integers c from standard input and store them in a list
c = read_ints(n)

# Initialize answer variable to 0
ans = 0

# Sort list c in ascending order
c.sort()

# Iterate through list c and calculate answer
for i in range(n):
    # Calculate contribution of current integer to answer
    ans = (ans + (n+1-i)*c[i]%mod)%mod

# Calculate final answer by multiplying answer with (4^(n-1)) modulo mod
print(ans*modpow(4,n-1)%mod)

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
        n = n//2
        res = res*modpow(a,n)%mod

    # If n is even, square result and recursively call function for n/2
    else:
        a = a*a%mod
        n = n//2
        res = modpow(a,n)%mod

    # Return result
    return res

print("<END-OF-CODE>")