import random
import sys

def miller_rabin(n, k):
    if n < 4:
        return n == 2 or n == 3
    s = 0
    d = n - 1
    while d % 2 == 0:
        d >>= 1
        s += 1
    for i in range(k):
        a = random.randint(2, n - 2)
        x = power_mod(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for r in range(1, s):
            x = power_mod(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def power_mod(x, y, p):
    res = 1
    x %= p
    if x == 0:
        return 0
    while y > 0:
        if y & 1 == 1:
            res = (res * x) % p
        y >>= 1
        x = (x * x) % p
    return res

def deterministic_miller_rabin(n):
    if n < 2:
        return False
    r = 0
    d = n - 1
    while d % 2 == 0:
        d >>= 1
        r += 1
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a:
            return True
        if miller_rabin(n, 1):
            return False
    return True

def main():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    if miller_rabin(n, k):
        print("Using Miller-Rabin Probabilistic Test: Probably Prime")
    else:
        print("Using Miller-Rabin Probabilistic Test: Composite")
    if deterministic_miller_rabin(n):
        print("Using Deterministic Miller-Rabin Test: Prime")
    else:
        print("Using Deterministic Miller-Rabin Test: Composite")

if __name__ == "__main__":
    main()

# 