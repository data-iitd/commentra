
import sys

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def upll(a, b):
    return a < b

def downll(a, b):
    return a > b

def sortup(a):
    a.sort(key=upll)

def sortdown(a):
    a.sort(key=downll)

def modpow(a, n, mod):
    ans = 1
    while n > 0:
        if n & 1:
            ans = ans * a % mod
        a = a * a % mod
        n //= 2
    return ans

def modinv(a, mod):
    return modpow(a, mod - 2, mod)

def max(a, b):
    return a if a > b else b

def min(a, b):
    return a if a < b else b

def chmax(a, b):
    if a < b:
        a = b
    return a

def chmin(a, b):
    if a > b:
        a = b
    return a

if __name__ == "__main__":
    n = int(input())
    sum = 0
    m = n
    for i in range(9):
        sum += n % 10
        n //= 10
    if m % sum == 0:
        print("Yes")
    else:
        print("No")

