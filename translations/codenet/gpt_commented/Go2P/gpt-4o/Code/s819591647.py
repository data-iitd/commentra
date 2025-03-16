import sys
from math import gcd

# Define a constant for modulus operation
constMod = int(1e9) + 7

# Function to read a single integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read n integers from input and return them as a list
def get_int_list(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to compute the modular exponentiation a^n % m
def num_mod_pow(a, n, m):
    result = 1
    while n > 0:
        if n % 2 == 1:
            result = (result * a) % m
        a = (a * a) % m
        n //= 2
    return result

# Function to compute the least common multiple of a and b
def num_lcm(a, b):
    return a * b // gcd(a, b)

# Function to compute factorials modulo constMod up to n
def num_mod_frac(n):
    frac = [1]
    for i in range(1, n + 1):
        frac.append(i * frac[i - 1] % constMod)
    return frac

# Function to compute nCr % constMod using precomputed factorials
def num_mod_conb(n, r):
    frac = num_mod_frac(n)
    return (frac[n] * pow(frac[n - r] * frac[r] % constMod, constMod - 2, constMod)) % constMod

# Main logic of the problem
def solve():
    # Read n and m from input
    n, m = map(int, sys.stdin.readline().strip().split())
    # Read n integers into list a
    a = get_int_list(n)

    # Calculate the sum of all elements in a
    total_sum = sum(a)

    # Count how many elements in a meet the required rate
    count = sum(1 for v in a if v >= total_sum / (4 * m))

    # Output "Yes" if count is greater than or equal to m, otherwise "No"
    print("Yes" if count >= m else "No")

# Entry point of the program
if __name__ == "__main__":
    solve()
    
# <END-OF-CODE>
