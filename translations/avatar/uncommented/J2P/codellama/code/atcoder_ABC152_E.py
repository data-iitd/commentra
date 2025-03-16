import math
import sys

def main():
    N = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().split()))
    lcm = 1
    for ai in A:
        lcm = lcm // math.gcd(lcm, ai) * ai
    mod = 1000000007
    modLcm = lcm % mod
    ans = 0
    for ai in A:
        ans = (ans + modDiv(modLcm, ai, mod)) % mod
    print(ans)

def modDiv(a, b, mod):
    return (a % mod) * modInv(b, mod) % mod

def modInv(x, mod):
    return modPow(x, mod - 2, mod)

def modPow(b, e, mod):
    ans = 1
    x = b % mod
    for y in range(e):
        if y & 1:
            ans = (ans * x) % mod
        x = (x * x) % mod
    return ans

if __name__ == '__main__':
    main()

