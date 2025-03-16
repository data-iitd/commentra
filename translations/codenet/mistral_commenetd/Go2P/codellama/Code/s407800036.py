# Import the "sys" module for reading input from the standard input
import sys

# Read three integers from the standard input and assign them to the variables A, B, and C respectively
A, B, C = map(int, sys.stdin.readline().split())

# Check if the value of C is within the range of A and B
if A <= C <= B:
    # If it is, print "Yes" to the standard output
    print("Yes")
else:
    # Otherwise, print "No" to the standard output
    print("No")

# End of code
