import math  # Import the math module to use mathematical functions
MOD = 10**9 + 7  # Define a constant MOD for modulo operations to prevent overflow

# Define a shortcut for the factorial function
f = math.factorial

# Read two integers from input, sort them, and assign to n and m
n, m = sorted(map(int, input().split()))

# Calculate the result based on the formula and print it
# The formula calculates the maximum of (2 - m + n) and 0, multiplies it by the factorial of n and m,
# and takes the result modulo MOD
print(max(2 - m + n, 0) * f(n) * f(m) % MOD)
