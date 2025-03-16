# Import the math module and define a constant MOD for the calculation of the result
import math
MOD = 10**9+7

# Define a function f that calculates the factorial of a given number
def f(n):
    # Base case: the factorial of 0 is 1
    if n == 0:
        return 1
    # Recursive case: the factorial of a number is the product of the number and the factorial of the number minus one
    else:
        return (f(n-1) * n) % MOD

# Read the input as two integers n and m, and sort them in ascending order
n, m = sorted(map(int, input().split()))

# Calculate the maximum value between 2 - m + n and 0
max_value = max(2 - m + n, 0)

# Multiply the factorial of n and the factorial of m
result = (f(n) * f(m)) % MOD

# Calculate the result by taking the modulo of the product with MOD
# and print the result
print(result)
