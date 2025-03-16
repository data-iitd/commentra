import random
import sys

def millerRabin(n, k):
    if n < 4:
        return n == 2 or n == 3

    s = 0
    d = n - 1
    while (d & 1) == 0:
        d >>= 1
        s += 1

    for i in range(k):
        a = 2 + random.randint(0, n - 3)
        if checkComposite(n, a, d, s):
            return False
    return True

def deterministicMillerRabin(n):
    if n < 2:
        return False

    r = 0
    d = n - 1
    while (d & 1) == 0:
        d >>= 1
        r += 1

    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a:
            return True
        if checkComposite(n, a, d, r):
            return False
    return True

def checkComposite(n, a, d, s):
    x = powerModP(a, d, n)
    if x == 1 or x == n - 1:
        return False
    for r in range(1, s):
        x = powerModP(x, 2, n)
        if x == n - 1:
            return False
    return True

def powerModP(x, y, p):
    res = 1
    x %= p

    if x == 0:
        return 0
    while y > 0:
        if (y & 1) == 1:
            res = (res * x) % p
        y >>= 1
        x = (x * x) % p
    return res

def multiplyModP(a, b, p):
    res = 0
    a %= p

    while b > 0:
        if (b & 1) == 1:
            res = (res + a) % p
        a = (2 * a) % p
        b >>= 1
    return res

def main():
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())

    isProbablyPrime = millerRabin(n, k)
    print("Using Miller-Rabin Probabilistic Test: " + ("Probably Prime" if isProbablyPrime else "Composite"))

    isPrime = deterministicMillerRabin(n)
    print("Using Deterministic Miller-Rabin Test: " + ("Prime" if isPrime else "Composite"))

if __name__ == "__main__":
    main()

