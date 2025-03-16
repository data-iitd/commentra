
import math
import sys

# Reading the first long integer input N
N = int(sys.stdin.readline().strip())

# Initializing the minimum long integer variable with the first input value
min = 0
for i in range(5):
    if i == 0: # If it's the first iteration of the loop
        min = int(sys.stdin.readline().strip()) # Set the minimum value to the current input value
    else: # Otherwise
        min = min if min < int(sys.stdin.readline().strip()) else int(sys.stdin.readline().strip()) # Update the minimum value with the current input value if it's smaller

# Printing the answer using the p method
p((math.ceil(N/min))+4)

# Utility method to print a string as output
def p(ans):
    print(ans)

# Utility method to print an integer as output
def p(ans):
    print(ans)

# Utility method to print nothing as output
def p():
    print()

# Utility method to print a long integer as output
def p(ans):
    print(ans)

# Utility method to print a double as output
def p(ans):
    print(ans)

