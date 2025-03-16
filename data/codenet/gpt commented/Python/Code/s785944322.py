import sys  # Importing the sys module to use sys.stdin for fast input
input = sys.stdin.readline  # Redefining input to read a line from standard input

# Reading two integers from input and unpacking them into variables a and b
a, b = map(int, input().split())

# Checking the value of a to determine the output based on specified conditions
if a >= 13:
    # If a is 13 or greater, print b as is
    print(b)
elif a >= 6:
    # If a is between 6 and 12 (inclusive), print half of b
    print(int(b / 2))
else:
    # If a is less than 6, print 0
    print(0)
