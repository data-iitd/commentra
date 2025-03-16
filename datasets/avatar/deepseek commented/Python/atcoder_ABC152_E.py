from fractions import gcd  # Importing the gcd function from the fractions module

# Define a function to calculate the least common multiple (LCM) of two numbers
def lcm(a, b):
    return a * b / gcd(a, b)  # Using the gcd function to calculate the LCM

MOD = 10 ** 9 + 7  # Define a constant MOD for modulo operations

N = int(input())  # Read the number of elements in the list A
A = list(map(int, input().split()))  # Read the list A as integers split by spaces

_lcm = 1  # Initialize _lcm to 1
for a in A:
    _lcm = _lcm * a // gcd(_lcm, a)  # Update _lcm to be the LCM of _lcm and the current element

# Calculate ans as _lcm multiplied by the sum of modular inverses of each element in A modulo MOD
ans = _lcm * sum([pow(s, MOD - 2, MOD) for s in A]) % MOD

print(int(ans % MOD))  # Print the result, ensuring it is within the modulo range
