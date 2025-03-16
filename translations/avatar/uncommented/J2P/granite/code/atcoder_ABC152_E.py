
import math
import sys

def mod_div(a, b, mod):
    return (a * pow(b, mod - 2, mod)) % mod

def mod_inv(x, mod):
    return pow(x, mod - 2, mod)

def mod_pow(b, e, mod):
    ans = 1
    x = b % mod
    for y in range(e):
        if y & 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
    return ans

def main():
    N = int(input())
    A = list(map(int, input().split()))
    lcm = 1
    for a in A:
        lcm = (lcm * a) // math.gcd(lcm, a)
    mod = 1000000007
    mod_lcm = lcm % mod
    ans = 0
    for a in A:
        ans = (ans + mod_div(mod_lcm, a, mod)) % mod
    print(ans)

if __name__ == "__main__":
    main()

