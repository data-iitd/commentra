
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
        a = 2 + random.randint(0, n - 4)
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
    x = pow(a, d, n)
    if x == 1 or x == n - 1:
        return False
    for _ in range(s - 1):
        x = pow(x, 2, n)
        if x == n - 1:
            return False
    return True

# Input: n (number to test) and k (number of iterations)
n = int(input("Enter the number to test: "))
k = int(input("Enter the number of iterations: "))

# Probabilistic Miller-Rabin Test
is_probably_prime = miller_rabin(n, k)
print(f"Using Miller-Rabin Probabilistic Test: {'Probably Prime' if is_probably_prime else 'Composite'}")

# Deterministic Miller-Rabin Test
is_prime = deterministic_miller_rabin(n)
print(f"Using Deterministic Miller-Rabin Test: {'Prime' if is_prime else 'Composite'}")

# 