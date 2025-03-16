import math

# Read input values for n and m
n = int(input())
m = int(input())

# Calculate the greatest common divisor (GCD) of n and m
gcd = math.gcd(n, m)

# Read input strings s and t
s = input()
t = input()

# Perform the required calculation and print the result
result = 0
for k in range(gcd):
    if s[int(k * n / gcd)] != t[int(k * m / gcd)]:
        result = -1
        break
else:
    result = (n * m) // gcd

# Print the result
print(result)
