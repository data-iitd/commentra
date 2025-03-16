import math 
import sys 

# Read two integers n and m from input
n, m = map(int, input().split()) 

# Calculate the greatest common divisor (gcd) of n and m
gcd = math.gcd(n, m) 

# Read two strings s and t from input
s, t = input(), input() 

# Check for mismatches in the characters of the two strings based on the gcd
# If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
print(
    [k for k in range(gcd) if s[k * n // gcd] != t[k * m // gcd]] or
    math.prod([n, m]) // Calculate lcm if no mismatch
) 

