
import sys

# Read the first integer from input and convert it to an integer
a = int(sys.stdin.readline())
# Read the second integer from input and convert it to an integer
b = int(sys.stdin.readline())

# Check if the product of a and b is odd
if a * b % 2!= 0:
    # If the product is odd, print "Odd"
    print("Odd")
else:
    # If the product is even, print "Even"
    print("Even")

