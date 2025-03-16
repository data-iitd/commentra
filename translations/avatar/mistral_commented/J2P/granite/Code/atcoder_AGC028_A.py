
#######
# Import necessary libraries
#######
import math
import sys

# Read input values for n and m
n = int(input())
m = int(input())

# Calculate the greatest common divisor (GCD) of n and m
gcd = math.gcd(n, m)

# Read input strings s and t
s = input()
t = input()

# Perform the required calculation and print the result
result = next((k for k in range(gcd) if s[k * n // gcd]!= t[k * m // gcd]), -1)
if result == -1:
    result = n * m // gcd

# Print the result
print(result)

