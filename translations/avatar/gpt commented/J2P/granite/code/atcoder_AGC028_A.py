
import math

# Read two integers n and m from input
n = int(input())
m = int(input())

# Calculate the greatest common divisor (gcd) of n and m
gcd = math.gcd(n, m)

# Read two strings s and t from input
s = input()
t = input()

# Check for mismatches in the characters of the two strings based on the gcd
# If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
mismatch = next((k for k in range(gcd) if s[k * n // gcd]!= t[k * m // gcd]), None)
if mismatch is None:
    lcm = n * m // gcd
else:
    lcm = -1

print(lcm) # 