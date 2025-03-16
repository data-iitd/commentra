
import sys
import math

def gcd(a, b):
    return b if b!= 0 else a

def lcm(a, b):
    return a // gcd(a, b) * b

def integer(num):
    return math.floor(num) == num

def fact(num):
    if num == 0:
        return 1
    else:
        return num * fact(num - 1)

def yakusu(n):
    cnt = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            cnt += 1
            if i * i!= n:
                cnt += 1
    return cnt

def fact_mod(n, mod):
    f = 1
    for i in range(2, n + 1):
        f = (f * i) % mod
    return f

def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = (res * x) % mod
        x = (x * x) % mod
        n >>= 1
    return res

def combination_mod(n, r, mod):
    if r > n - r:
        r = n - r
    if r == 0:
        return 1
    a = 1
    for i in range(r):
        a = (a * (n - i)) % mod
    b = mod_pow(fact_mod(r, mod), mod - 2, mod)
    return (a * b) % mod

def rev(s):
    return s == s[::-1]

if __name__ == "__main__":
    k, a, b = map(int, input().split())
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")
            sys.exit(0)
    print("NG")

