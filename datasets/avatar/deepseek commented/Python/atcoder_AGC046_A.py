
from math import gcd  # Importing the gcd function from the math module

# Take an integer input x
x = int(input())

# Calculate the number of distinct cyclic permutations of a string of length x
print(360 // gcd(360, x))


