from fractions import gcd  # Import the gcd function from the fractions module

def lcm(a, b):
    # Calculate the least common multiple (LCM) of two numbers a and b
    return a * b / gcd(a, b)

MOD = 10 ** 9 + 7  # Define a constant MOD for modular arithmetic
N = int(input())  # Read the number of elements from user input
A = list(map(int, input().split()))  # Read a list of integers from user input

_lcm = 1  # Initialize the variable to store the LCM of the list
for a in A:
    # Update the LCM by calculating the LCM of the current LCM and the next element
    _lcm = _lcm * a // gcd(_lcm, a)

# Calculate the final answer using the LCM and the modular inverses of the elements in A
ans = _lcm * sum([pow(s, MOD - 2, MOD) for s in A]) % MOD

# Print the result, ensuring it is within the bounds of MOD
print(int(ans % MOD))
