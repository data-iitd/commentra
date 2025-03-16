import math

# Util functions
def next_str():
    return input().strip()

def next_int():
    return int(input().strip())

# Helper functions for mathematical operations
def max_int(a, b):
    return a if a > b else b

def min_int(a, b):
    return a if a < b else b

def abs_int(a):
    return a if a >= 0 else -a

def abs_float64(a):
    return a if a >= 0 else -a

def max_float64(a, b):
    return a if a > b else b

def min_float64(a, b):
    return a if a < b else b

def str2_int(s):
    return int(s)

def reverse(s):
    return s[::-1]

def pow_int(p, q):
    return p ** q

def is_prime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    rootx = int(math.sqrt(x))
    i = 3
    while i <= rootx:
        if x % i == 0:
            return False
        i += 2
    return True

def prime_factors(n):
    pfs = []
    while n % 2 == 0:
        pfs.append(2)
        n //= 2
    i = 3
    while i * i <= n:
        while n % i == 0:
            pfs.append(i)
            n //= i
        i += 2
    if n > 2:
        pfs.append(n)
    return pfs

def prime_factors_map(n):
    pfs = {}
    while n % 2 == 0:
        pfs[2] = pfs.get(2, 0) + 1
        n //= 2
    i = 3
    while i * i <= n:
        while n % i == 0:
            pfs[i] = pfs.get(i, 0) + 1
            n //= i
        i += 2
    if n > 2:
        pfs[n] = pfs.get(n, 0) + 1
    return pfs

