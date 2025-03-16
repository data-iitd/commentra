import math
from functools import reduce

MOD = 1000000007

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcm_list(numbers):
    return reduce(lcm, numbers)

def modinv(a, mod):
    return pow(a, mod - 2, mod)

def moddiv(a, b, mod):
    return (a % mod) * modinv(b, mod) % mod

def main():
    N = int(input())
    A = list(map(int, input().split()))

    lcm_val = lcm_list(A)
    ans = 0

    for ai in A:
        ans = (ans + moddiv(lcm_val, ai, MOD)) % MOD

    print(ans)

if __name__ == "__main__":
    main()
