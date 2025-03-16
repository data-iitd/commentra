
# <START-OF-CODE>

import sys
import math

def is_prime(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def main():
    n = int(sys.stdin.readline())
    while n > 0:
        p, q = map(int, sys.stdin.readline().split())
        l = int(math.sqrt(p*p + q*q))
        isprime = True
        for i in range(l):
            for j in range(l):
                x = i*i + j*j
                if x <= 1 or x >= p*p + q*q:
                    continue
                if ((i*p + j*q) % x == 0 and (i*q - j*p) % x == 0):
                    isprime = False
        print("P" if isprime else "C")
        n -= 1

if __name__ == "__main__":
    main()

# 