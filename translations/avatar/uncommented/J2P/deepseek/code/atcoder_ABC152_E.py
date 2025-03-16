import sys
import math

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    
    lcm = 1
    for ai in A:
        g = math.gcd(lcm, ai)
        lcm = lcm // g * ai
    
    mod = 1000000007
    mod_lcm = lcm % mod
    ans = 0
    for ai in A:
        ans = (ans + mod_div(mod_lcm, ai, mod)) % mod
    print(ans)

def mod_div(a, b, mod):
    return (a % mod) * mod_inv(b, mod) % mod

def mod_inv(x, mod):
    return mod_pow(x, mod - 2, mod)

def mod_pow(b, e, mod):
    ans = 1
    x = b % mod
    while e > 0:
        if e % 2 == 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
        e //= 2
    return ans

if __name__ == "__main__":
    main()
