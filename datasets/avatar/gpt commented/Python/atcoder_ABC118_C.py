# Read an integer input N, which represents the number of elements in the list
N = int(input())

# Read a line of input, split it into individual string elements, convert them to integers,
# and store them in a list A
A = list(map(int, input().split()))

# Import necessary modules for calculating the greatest common divisor (GCD)
import functools
import fractions

# Calculate the GCD of all elements in the list A using functools.reduce and fractions.gcd
gcd = functools.reduce(fractions.gcd, A)

# Print the calculated GCD
print(gcd)
