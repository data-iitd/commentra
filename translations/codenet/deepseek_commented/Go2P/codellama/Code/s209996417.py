
import math

n, k = input().split()
n = float(n)
k = float(k)

# Read two floating-point numbers, n and k, from standard input.
# These represent the number to be converted and the base of the number system, respectively.

# Calculate the number of digits in the base k representation of n.
# The logic involves finding the smallest integer x such that k^x is less than or equal to n and n is less than k^(x+1).
# Output x + 1 as the number of digits in the base k representation of n.

x = 0
while True:
    under = math.pow(k, x)
    upper = math.pow(k, x+1)

    if under <= n and n < upper:
        print(int(x+1))
        break
    x += 1

# 