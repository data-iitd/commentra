# Include necessary standard libraries

# Define custom data types

# Macros for repetition

# Constants and definitions

def swap(a, b):
    c = b
    b = a
    a = c

def cin(n):
    n[0] = int(input())

def max2(a, b):
    return a if a >= b else b

def min2(a, b):
    return a if a >= b else b

def min3(a, b, c):
    return a if a <= b and a <= c else b if b <= c else c

def max3(a, b, c):
    return a if a >= b and a >= c else b if b >= c else c

def minn(n, a):
    b = float('inf')
    for i in range(n):
        b = min(b, a[i])
    return b

def maxn(n, a):
    b = float('-inf')
    for i in range(n):
        b = max(b, a[i])
    return b

def POW(a, b):
    c = 1
    for i in range(b):
        c *= a
    return c

def POW_d(a, b):
    c = 1
    for i in range(b):
        c *= a
    return c

def gcd(a, b):
    return gcd(b, a % b) if b else a

def lcm(a, b):
    return a // gcd(a, b) * b

def mod_MOD1(n):
    n += -n // MOD1 * MOD1 if n < 0 else 0
    return n % MOD1

def mod_p(n, p):
    n += -n // p * p if n < 0 else 0
    return n % p

def change_into_num(s, len, p):
    return 0 if p == 0 else (10 ** (p - 1)) * (ord(s[len - p]) - ord('0')) + change_into_num(s, len, p - 1)

def digits(a, b):
    return 1 if a >= b else 1 + digits(a // b, b)

def base(n, a, i):
    return base(n // a, a, i - 1) if i == 1 else n % a

def is_inArr1(x, n):
    return 0 if x < 0 or x >= n else 1

def is_inArr2(y, x, h, w):
    return 0 if y < 0 or y >= h or x < 0 or x >= w else 1

def lr_lower(l, r, am, val, type):
    pass

def lr_upper(l, r, am, val, type):
    pass

def cmp_lower(a, b, type):
    return 0 if a == b else -1 if a < b else 1

def cmp_upper(a, b, type):
    return 0 if a == b else -1 if a <= b else 1

def lower_bound(a, l, r, val, type):
    pass

def upper_bound(a, l, r, val, type):
    pass

def count(a, l, r, x):
    ans = 0
    for i in range(l, r + 1):
        if a[i] == x:
            ans += 1
    return ans

def factor(n, new_common_plus):
    pass

def judge_prime(n):
    pass

def makeinv(x, mod, is_fac):
    pass

def m_inv(x, mod, is_fac):
    pass

def m_f(x, mod):
    pass

def mod_nck(n, k, mod):
    pass

def m_p(r, n, mod):
    pass

def m_mul2(a, b, mod):
    return (a * b) % mod

def m_mul3(a, b, c, mod):
    return m_mul2(a, b, mod) * c % mod

def m_mul4(a, b, c, d, mod):
    return m_mul3(a, b, c, mod) * d % mod

def m_mul5(a, b, c, d, e, mod):
    return m_mul4(a, b, c, d, mod) * e % mod

# Functions for sorting arrays

def upll(a, b):
    return a < b

def downll(a, b):
    return a > b

def cmp_string(a, b):
    return -1 if a < b else 1 if a > b else 0

def cmp_char(a, b):
    return ord(a) - ord(b)

def sortup(a, n):
    a.sort()

def sortdown(a, n):
    a.sort(reverse=True)

def sort_string(n, size, s):
    s.sort()

def sort_char(s):
    s = ''.join(sorted(s))

# Function to find the number of unique elements in an array or a string

def unique_string(n, size, s):
    ans = 1
    for i in range(1, n):
        if s[i] != s[i - 1]:
            ans += 1
    return ans

def unique_num(n, a):
    ans = 1
    for i in range(1, n):
        if a[i] != a[i - 1]:
            ans += 1
    return ans

# Global variables and constants

s = input()

def main():
    l = int(input())
    r = int(input())
    d = int(input())

    ans = 0

    for i in range(l, r + 1):
        if i % d == 0:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()
