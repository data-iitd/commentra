
import sys
import math

#=====I/O=====

def scanInt():
    return int(input())

def scanInt64():
    return int(input())

def scanInts(n):
    res = []
    for i in range(n):
        res.append(scanInt())
    return res

def scanText():
    return input()

def printInts(a):
    print(" ".join(map(str, a)))

#=====main=====

def main():
    n = scanInt()

    c = scanInts(n)

    ans = 0
    c.sort()

    for i in range(n):
        ans = (ans+(n+1-i)*c[i]%mod)%mod

    print((ans*modpow(4,n-1))%mod)

mod = 1000000007

def modpow(a,n):
    res = 1
    while n>0:
        if n&1 == 1:
            res = res*a%mod
        a = a*a%mod
        n= n>>1
    return res

if __name__ == "__main__":
    sys.exit(main())

