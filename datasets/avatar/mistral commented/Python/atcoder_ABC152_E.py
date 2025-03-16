# Importing the fractions module and defining a function lcm to calculate the least common multiple of two numbers a and b.
from fractions import gcd
def lcm(a, b):
    # Calculate the greatest common divisor of a and b using the gcd function.
    g = gcd(a, b)
    # Return the product of a and b divided by their greatest common divisor.
    return a * b // g

# Setting the value of MOD to 10^9 + 7.
MOD = 10 ** 9 + 7

# Reading the input N and storing the list A of N integers.
N = int(input())
A = list(map(int, input().split()))

# Initializing the variable _lcm to 1.
_lcm = 1

# Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
for a in A:
    # Update the value of _lcm using the lcm function.
    _lcm = lcm(_lcm, a)

# Calculating the answer ans using the formula _lcm * sum ( [ pow ( s , MOD - 2 , MOD ) for s in A ] ) % MOD.
ans = _lcm * sum([pow(s, MOD - 2, MOD) for s in A]) % MOD

# Printing the final answer.
print(int(ans % MOD))
