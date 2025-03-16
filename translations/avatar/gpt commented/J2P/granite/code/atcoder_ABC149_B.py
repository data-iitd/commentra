
import sys

# Read input values A, B, and K from the command line arguments
A = int(sys.argv[1])
B = int(sys.argv[2])
K = int(sys.argv[3])

# Perform the main calculation based on A, B, and K
x = A - K
if x < 0:
    y = B + x
    x = 0
    if y < 0:
        y = 0

# Display the results of the calculations
print(x, y)

