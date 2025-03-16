# Import some built-in Python modules that we may need later
import bisect, collections, copy, heapq, itertools, math, numpy, string

# Define two helper functions to read input from the standard input stream
def S( ): return sys.stdin.readline().rstrip()
def I( ): return int(sys.stdin.readline().rstrip())

# Define another helper function to read a list of integers from the standard input stream
def LI( ): return list(map(int, sys.stdin.readline().rstrip().split()))

# Define another helper function to read a list of strings from the standard input stream
def LS( ): return list(sys.stdin.readline().rstrip().split())

# Define two variables and initialize them with the values read from the standard input stream
a, b = LI()

# Check if 'a' is positive
if a > 0:
    # If it is, print the string 'Positive'
    print('Positive')

# If 'a' is not positive, check if 'b' is non-negative
elif a <= 0 and b >= 0:
    # If it is, print the string 'Zero'
    print('Zero')

# If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
else:
    # If it is, print the string 'Negative'
    if (a + b) % 2 == 0:
        print('Negative')
    # Otherwise, print the string 'Positive'
    else:
        print('Positive')
