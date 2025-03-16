# Include necessary header files
import sys
import math
import itertools

# Uncomment the following lines to include Boost multiprecision libraries
# import boost.multiprecision as mp
# Real = mp.cpp_dec_float(1024)
# Bint = mp.cpp_int

# Define long long as int for convenience
int = long long

# Macros for loop iterations
def REP(i, s, e):
    for i in range(s, e):
        yield i

def RREP(i, s, e):
    for i in range(s-1, e-1, -1):
        yield i

def FOR(i, n):
    for i in range(n):
        yield i

def RFOR(i, n):
    for i in range(n-1, -1, -1):
        yield i

# Define a constant for modulo operation
MOD = 1000000007

def main():
    # Declare a vector to store strings and variables for input
    v = []
    N, L = 0, 0

    # Read the number of strings (N) and the length of strings (L)
    N, L = map(int, input().split())

    # Input N strings from the user and store them in the vector
    for i in range(N):
        s = input()
        v.append(s) # Add the string to the vector

    # Sort the vector of strings in lexicographical order
    v.sort()

    # Output the sorted strings
    for s in v:
        print(s, end='') # Print each string in the sorted order
    print() # Print a newline at the end

if __name__ == '__main__':
    main()

