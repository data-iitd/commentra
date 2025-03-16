# Include the standard input/output library
import sys

# Read four integers from the user
a, b, c, d = map(int, sys.stdin.readline().split())

# Perform multiplication operations and store the results in i and j
i = a * b
j = c * d

# Use an if-else statement to compare the results and print the larger one
if i > j:
    print(i)
else:
    print(j)

# Return 0 to indicate successful execution
sys.exit(0)

