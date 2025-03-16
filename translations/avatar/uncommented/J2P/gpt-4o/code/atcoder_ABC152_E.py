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
        if (e & 1) == 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        e >>= 1
    return ans

def mod_div(a, b, mod):
    return (a % mod) * mod_inv(b, mod) % mod

def main():
    N = int(input())
    A = list(map(int, input().split()))
    
    mod = 1000000007
    lcm_value = reduce(lcm, A, 1)
    mod_lcm = lcm_value % mod
    
    ans = 0
    for ai in A:
        ans = (ans + mod_div(mod_lcm, ai, mod)) % mod
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
