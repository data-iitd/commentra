import math

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def main():
    n = int(input())
    while n > 0:
        p, q = map(int, input().split())
        l = int(math.sqrt(p*p + q*q))
        isprime = True
        for i in range(l):
            for j in range(l):
                x = i*i + j*j
                if x <= 1 or x >= p*p + q*q:
                    continue
                if (i*p + j*q) % x == 0 and (i*q - j*p) % x == 0:
                    isprime = False
                    break
            if not isprime:
                break
        print("P" if isprime else "C")
        n -= 1

main()
