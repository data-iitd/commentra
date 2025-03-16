# Importing sys module for reading input
import sys

# Function to read a single line
def read():
    return sys.stdin.read(1)

# Function to read a single line without newline character
def readline():
    return sys.stdin.readline().rstrip()

# Function to read all lines at once
def readlines():
    return sys.stdin.readlines()

# Setting recursion limit to handle large inputs
sys.setrecursionlimit(10 ** 7)

# Reading input strings
s = readline().rstrip()
t = readline().rstrip()[::-1]

# Sorting strings
s = sorted(list(s))
t = sorted(list(t))[::-1]

# Comparing sorted strings and printing result
if s < t:
    print("Yes")
else:
    print("No")
