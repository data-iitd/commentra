
import math

# Define the MOD constant
MOD = 10**9+7

# Import the factorial function from the math module
f = math.factorial

# Read input values, convert them to integers, and sort them
n, m = sorted(map(int, input().split()))

# Calculate the result using the factorial of n and m, and apply modulo operation
result = max(2 - m + n, 0) * f(n) * f(m) % MOD

# Print the final result
print(result)

