
# Include standard input-output header for basic I/O functions
# Include standard library header for general utilities
# Include iostream header for C++ style I/O operations
# Include string header for string manipulation
# Include algorithm header for using the sort function
# Include vector header for using dynamic arrays
# Include limits header for numeric limits
# Include numeric header for numeric operations
# Include type_traits header for type traits
# Include math header for mathematical functions
from sys import stdin, stdout # Import standard input/output functions
from typing import List # Import List type from typing module
from functools import reduce # Import reduce function from functools module
from operator import mul # Import mul function from operator module
from math import ceil # Import ceil function from math module

# Define a type alias 'll' for long long integers
ll = int

# Define a macro for loop iteration
def rep(i, n):
    for i in range(n):

# Define a macro for loop iteration with start and end values
def repi(i, a, b):
    for i in range(a, b):

# Define a macro to read input into variable 'x'
def in(x):
    x = int(input())

# Define a macro to output a string followed by a newline
def out(str):
    stdout.write(str + '\n')

# Define a template function to check and set maximum value
def chmax(a, b):
    if a < b:
        a = b
        return 1
    return 0

# Define a template function to check and set minimum value
def chmin(a, b):
    if b < a:
        a = b
        return 1
    return 0

# Declare global variables for the length of strings and the number of strings
L, N = 0, 0

# Declare an array to store the strings
S = []

# Read the number of strings and the length of each string
in(N)
in(L)

# Read each string and store it in the array
for i in range(N):
    S.append(input())

# Sort the array of strings alphabetically
S.sort()

# Output each sorted string
for i in range(N):
    out(S[i])

# Output a newline character
out('')

