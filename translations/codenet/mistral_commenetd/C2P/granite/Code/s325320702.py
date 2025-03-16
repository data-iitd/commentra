

import sys

def swap(a, b):
    c = a
    a = b
    b = c

def cin(n):
    n = int(input())
    return n

def max2(a, b):
    return a if a >= b else b

def min2(a, b):
    return a if a <= b else b

def min3(a, b, c):
    return min(a, b, c)

def max3(a, b, c):
    return max(a, b, c)

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
    c = 1.0
    for i in range(b):
        c *= a
    return c

def gcd(a, b):
    return b if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def mod_MOD1(n):
    n += n // MOD1 if n < 0 else 0
    return n % MOD1

def mod_p(n, p):
    n += n // p if n < 0 else 0
    return n % p

def change_into_num(s, len, p):
    return 0 if p == 0 else POW(10, p - 1) * (ord(s[len - p]) - ord('0')) + change_into_num(s, len, p - 1)

def digits(a, b):
    return a // b + (1 if a % b!= 0 else 0)

def base(n, a, i):
    return n // POW(a, i) if i == 1 else base(n // a, a, i - 1)

def is_inArr1(x, n):
    return 0 if x < 0 or x >= n else 1

def is_inArr2(y, x, h, w):
    return 0 if y < 0 or y >= h or x < 0 or x >= w else 1

def lr_lower(l, r, am, val, type):
    # Function to find the lowest index i such that a[i] = val
    # If type is less than 3, then am < val, otherwise am <= val

def lr_upper(l, r, am, val, type):
    # Function to find the highest index i such that a[i] = val
    # If type is less than 3, then am <= val, otherwise am < val

def cmp_lower(a, b, type):
    # Comparison function for lower_bound
    # If type is 1, then a == b, otherwise a < b (type = 2) or a < b (type = 3)

def cmp_upper(a, b, type):
    # Comparison function for upper_bound
    # If type is 1, then a == b, otherwise a <= b (type = 2) or a < b (type = 3)

def lower_bound(a, l, r, val, type):
    # Binary search function for finding the lowest index i such that a[i] = val
    # If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)

def upper_bound(a, l, r, val, type):
    # Binary search function for finding the highest index i such that a[i] = val
    # If type is 1, then a[i] == val, otherwise a[i] <= val (type = 2) or a[i] < val (type = 3)

def count(a, l, r, x):
    # Function to find the number of occurrences of x in the subarray a[l..r]

def factor(n, new_common_plus):
    # Function to find the prime factorization of n
    # new_common_plus can be 1 (common factor), 2 (common factor and its power), or 0 (no common factor)

def judge_prime(n):
    # Function to check if n is prime

def makeinv(x, mod, is_fac):
    # Function to calculate the multiplicative inverse of x modulo mod
    # is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)

def m_inv(x, mod, is_fac):
    # Function to calculate the inverse of x modulo mod
    # is_fac can be 1 (calculate the inverse of x) or 0 (calculate the inverse of mod/x)

def m_f(x, mod):
    # Function to calculate the multiplicative function of x modulo mod

def mod_nck(n, k, mod):
    # Function to calculate nCk modulo mod

def m_p(r, n, mod):
    # Function to calculate r^n modulo mod

def m_mul2(a, b, mod):
    # Function to calculate the product of two numbers modulo mod

def m_mul3(a, b, c, mod):
    # Function to calculate the product of three numbers modulo mod

def m_mul4(a, b, c, d, mod):
    # Function to calculate the product of four numbers modulo mod

def m_mul5(a, b, c, d, e, mod):
    # Function to calculate the product of five numbers modulo mod

def sortup(a, n):
    a.sort()

def sortdown(a, n):
    a.sort(reverse=True)

def sort_string(n, size, s):
    s.sort()

def sort_char(s):
    s.sort()

def unique_string(n, size, s):
    ans = 1
    for i in range(1, n):
        if s[i]!= s[i - 1]:
            ans += 1
    return ans

def unique_num(n, a):
    ans = 1
    for i in range(1, n):
        if a[i]!= a[i - 1]:
            ans += 1
    return ans

l = cin(l)
r = cin(r)
d = cin(d)

ans = 0
for i in range(l, r + 1):
    if i % d == 0:
        ans += 1

print(ans)

