import sys
import math

constMod = int(1e9) + 7

def get_int():
    return int(sys.stdin.readline().strip())

def get_int_slice(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def get_string():
    return sys.stdin.readline().strip()

def get_string_slice(n):
    return sys.stdin.readline().strip().split()[:n]

def get_string_double_slice(m, n):
    sds = []
    for _ in range(m):
        ss = get_string_slice(n)
        sds.append(ss)
    return sds

def sort_int_slice(ns):
    return sorted(ns)

def sort_int_reverse_slice(ns):
    return sorted(ns, reverse=True)

def num_abs(x):
    return abs(x)

def num_mod_pow(a, n, m):
    result = 1
    while n > 0:
        if n % 2 == 1:
            result = (result * a) % m
        a = (a * a) % m
        n >>= 1
    return result

def num_gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def num_lcm(a, b):
    return a * b // num_gcd(a, b)

def num_mod_inv(a, p):
    if a == 1:
        return 1
    return p - num_mod_inv(p % a, p) * (p // a) % p

def num_mod_frac(n):
    frac = [1]
    for i in range(1, n + 1):
        frac.append(i * frac[i - 1] % constMod)
    return frac

def num_mod_comb(n, r):
    frac = num_mod_frac(n)
    return (frac[n] // ((frac[n - r] * frac[r]) % constMod)) % constMod

def solve():
    n, m = get_int(), get_int()
    a = get_int_slice(n)

    total_sum = sum(a)
    threshold = total_sum / (4 * m)
    qualified_count = sum(1 for x in a if x >= threshold)

    if qualified_count >= m:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    solve()
