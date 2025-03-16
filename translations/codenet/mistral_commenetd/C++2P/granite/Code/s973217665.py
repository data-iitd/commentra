

import math

def is_prime(x):
    if x <= 1:
        return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

def solve():
    n = int(input())
    for _ in range(n):
        p, q = map(int, input().split())
        l = int(math.sqrt(p**2 + q**2))
        is_prime_ = True
        for i in range(l):
            for j in range(l):
                x = i**2 + j**2
                if x > p**2 + q**2:
                    break
                if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                    is_prime_ = False
                    break
            if not is_prime_:
                break
        print("P" if is_prime_ else "C")

solve()

