import math
import sys

# Create a scanner object for input
scanner = sys.stdin

# Read two integers n and m from input
n = int(scanner.readline())
m = int(scanner.readline())

# Calculate the greatest common divisor (gcd) of n and m
gcd = math.gcd(n, m)

# Read two strings s and t from input
s = scanner.readline()
t = scanner.readline()

# Check for mismatches in the characters of the two strings based on the gcd
# If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
print(
    -1 if any(s[i * n // gcd]!= t[i * m // gcd] for i in range(gcd))
    else n * m // gcd
)

# 