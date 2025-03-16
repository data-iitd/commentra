import math
from functools import reduce

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcm_list(numbers):
    return reduce(lcm, numbers)

def mod_div(a, b, mod):
    return (a % mod) * pow(b, mod - 2, mod) % mod

def mod_pow(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

# Main function
if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    
    # Calculate the LCM of all elements in array A
    lcm_value = lcm_list(A)
    
    # Define the modulo value
    mod = 1000000007
    
    # Initialize the answer to 0
    ans = 0
    
    # Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for ai in A:
        ans = (ans + mod_div(lcm_value, ai, mod)) % mod
    
    # Print the final answer
    print(ans)
