# Include the standard input-output library
import sys

# Read four integer values from the standard input
m1, d1, m2, d2 = map(int, sys.stdin.readline().split())

# Check if the values of m1 and m2 are not equal, if true print 1
if m1!= m2:
    print("1")
# If m1 and m2 are equal, print 0
else:
    print("0")

# 