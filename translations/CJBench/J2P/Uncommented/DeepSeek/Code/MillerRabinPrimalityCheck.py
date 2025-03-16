import random

def miller_rabin(n, k):
    if n < 4:
        return n == 2 or n == 3
    s = 0
    d = n - 1
    while d % 2 == 0:
        d //= 2
        s += 1
    for _ in range(k):
        a = 2 + abs(random.randrange(n - 3))
        if check_composite(n, a, d, s):
            return False
    return True

def deterministic_miller_rabin(n):
    if n < 2:
        return False
    r = 0
    d = n - 1
    while d % 2 == 0:
        d //= 2
        r += 1
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a:
            return True
        if check_composite(n, a, d, r):
            return False
    return True

def check_composite(n, a, d, s):
    x = power_mod_p(a, d, n)
    if x == 1 or x == n - 1:
        return False
    for _ in range(s):
        x = power_mod_p(x, 2, n)
        if x == n - 1:
            return False
    return True

def power_mod_p(x, y, p):
    res = 1
    x %= p
    if x == 0:
        return 0
    while y > 0:
        if y & 1:
            res = multiply_mod_p(res, x, p)
        y >>= 1
        x = multiply_mod_p(x, x, p)
    return res

def multiply_mod_p(a, b, p):
    res = 0
    a %= p
    while b > 0:
        if b & 1:
            res = (res + a) % p
        a = (2 * a) % p
        b >>= 1
    return res

# Example usage:
# n = int(input())
# k = int(input())
# print("Using Miller-Rabin Probabilistic Test:", "Probably Prime" if miller_rabin(n, k) else "Composite")
# print("Using Deterministic Miller-Rabin Test:", "Prime" if deterministic_miller_rabin(n) else "Composite")

