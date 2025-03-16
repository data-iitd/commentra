
# Import the "sys" module for standard input/output
import sys

# Read three integers from the standard input
A, B, C = map(int, sys.stdin.readline().split())

# Check if the value of C is within the range of A and B
if C >= A and C <= B:
    # If it is, print "Yes" to the standard output
    print("Yes")
else:
    # Otherwise, print "No" to the standard output
    print("No")

# End of code