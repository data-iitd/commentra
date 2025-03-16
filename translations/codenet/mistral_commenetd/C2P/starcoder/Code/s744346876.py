# Include the standard input/output library
import sys

# Declare two integer variables A and B
A = int(sys.stdin.readline())
B = int(sys.stdin.readline())

# Check if both A and B are less than 10
if A < 10 and B < 10:
    # If true, print the product of A and B to the standard output
    print(A * B)
else:
    # If the condition is false
    print(-1)

# Indicate that the program has run successfully
sys.exit(0)

