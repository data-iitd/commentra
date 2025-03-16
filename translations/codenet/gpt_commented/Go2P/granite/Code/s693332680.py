
import sys

# Read three integer values from standard input
x, a, b = map(int, sys.stdin.readline().split())

# Evaluate the difference between b and a to determine the output
if b - a <= 0:
    print("delicious") # Output "delicious" if b is less than or equal to a
elif b - a <= x:
    print("safe") # Output "safe" if the difference is within the limit x
else:
    print("dangerous") # Output "dangerous" if the difference exceeds x

