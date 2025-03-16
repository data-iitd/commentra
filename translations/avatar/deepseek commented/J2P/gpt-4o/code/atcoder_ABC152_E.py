import math
from functools import reduce

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

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

def main():
    N = int(input())
    A = list(map(int, input().split()))
    
    # Initialize LCM to 1
    lcm_value = 1
    
    # Calculate the LCM of all elements in array A
    for ai in A:
        lcm_value = lcm(lcm_value, ai)
    
    # Define the modulo value
    mod = 1000000007
    
    # Calculate the LCM modulo 10^9 + 7
    mod_lcm = lcm_value % mod
    
    # Initialize the answer to 0
    ans = 0
    
    # Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for ai in A:
        ans = (ans + (mod_lcm * mod_inv(ai, mod)) % mod) % mod
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
