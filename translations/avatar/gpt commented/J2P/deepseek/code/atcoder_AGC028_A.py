import sys
import math

# Read two integers n and m from input
n, m = map(int, input().split())

# Calculate the greatest common divisor (gcd) of n and m
gcd = math.gcd(n, m)

# Read two strings s and t from input
s = input()
t = input()

# Check for mismatches in the characters of the two strings based on the gcd
# If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
lcm = (n * m) // gcd
result = -1
for k in range(gcd):
    if s[k * n // gcd] != t[k * m // gcd]:
        result = -1
        break
if result == -1:
    print(-1)
else:
    print(lcm)
