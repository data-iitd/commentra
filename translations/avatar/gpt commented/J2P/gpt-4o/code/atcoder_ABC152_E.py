import sys
from math import gcd
from functools import reduce

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

def mod_pow(b, e, mod):
    ans = 1
    x = b % mod
    while e != 0:
        if e & 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        e >>= 1
    return ans

def mod_div(a, b, mod):
    return (a % mod) * mod_inv(b, mod) % mod

def lcm(a, b):
    return a * (b // gcd(a, b))

def main():
    # Read the number of elements N
    N = int(sys.stdin.readline().strip())
    
    # Read N integers into the list A
    A = list(map(int, sys.stdin.readline().strip().split()))
    
    # Initialize the LCM
    lcm_value = 1
    
    # Calculate the LCM of all elements in the list A
    for ai in A:
        lcm_value = lcm(lcm_value, ai)
    
    # Define the modulus value
    mod = 1000000007
    
    # Calculate the LCM modulo mod
    mod_lcm = lcm_value % mod
    
    # Initialize the answer variable to accumulate results
    ans = 0
    
    # Calculate the sum of modDiv for each element in A
    for ai in A:
        ans = (ans + mod_div(mod_lcm, ai, mod)) % mod
    
    # Print the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
