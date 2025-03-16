import math
import sys

# Reading the first integer
n = int(input())

# Reading the second integer
m = int(input())

# Calculating the GCD of n and m
gcd = math.gcd(n, m)

# Reading the first string
s = input()

# Reading the second string
t = input()

# Filtering the range of the GCD and checking character mismatches
print(
    list(
        filter(
            lambda k: s[k * n // gcd]!= t[k * m // gcd],
            range(gcd)
        )
    )[0] if gcd > 0 else n * m // gcd
)

# 