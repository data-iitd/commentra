// Importing necessary packages
import sys

// Declaring variables
x, a, b = map(int, sys.stdin.readline().split())

# Logic block to check if b is less than or equal to a
if b-a <= 0:
    print("delicious")
elif b-a <= x:
    print("safe")
else:
    print("dangerous")

# End of code
