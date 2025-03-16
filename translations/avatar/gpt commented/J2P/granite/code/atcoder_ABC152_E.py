
import math
import sys

# Read the number of elements N
N = int(input())

# Read N integers into the array A
A = list(map(int, input().split()))

# Initialize the answer variable to accumulate results
ans = 0

# Calculate the sum of modDiv for each element in A
for ai in A:
    ans = (ans + modDiv(modLcm, ai)) % mod

# Print the final result
print(ans)

# Method to perform modular division
def modDiv(a, b):
    return a * modInv(b) % mod

# Method to compute modular inverse using Fermat's Little Theorem
def modInv(x):
    return modPow(x, mod - 2)

# Method to perform modular exponentiation
def modPow(b, e):
    ans = 1
    x = b % mod
    while e > 0:
        if e % 2 == 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        e //= 2
    return ans

# Define the modulus value
mod = 1000000007

# Calculate the LCM of all elements in the array A
modLcm = 1
for ai in A:
    a = ai
    while a!= 0:
        a, b = b, a % b
    modLcm = (modLcm * ai // b) % mod

# End of code
