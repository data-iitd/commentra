
import math # Importing math module for handling large integers

n = int(input()) # Reading the first integer
m = int(input()) # Reading the second integer
gcd = math.gcd(n, m) # Calculating the GCD of n and m
s = input() # Reading the first string
t = input() # Reading the second string

# Filtering the range of the GCD and checking character mismatches
result = next((k for k in range(gcd) if s[k * n // gcd]!= t[k * m // gcd]), -1)
if result == -1:
    result = n * m // gcd # Calculating the result

print(result) # Printing the result

