
#problem_b.py

import sys
import math

constMod = 1000000007

# -----------------------------------------

# This section contains utility functions to read inputs in various formats.
def getInt():
    return int(input())

# getIntSlice reads n integers from the input and returns them as a slice.
def getIntSlice(n):
    ns = []
    for i in range(n):
        ns.append(getInt())
    return ns

# getIntDoubleSlice reads m sets of n integers from the input and returns them as a 2D slice.
def getIntDoubleSlice(m, n):
    nds = []
    for i in range(m):
        ns = getIntSlice(n)
        nds.append(ns)
    return nds

# getString reads a single line from the input and returns it as a string.
def getString():
    return input()

# getStringSlice reads n strings from the input and returns them as a slice.
def getStringSlice(n):
    ss = []
    for i in range(n):
        ss.append(getString())
    return ss

# getStringDoubleSlice reads m sets of n strings from the input and returns them as a 2D slice.
def getStringDoubleSlice(m, n):
    sds = []
    for i in range(m):
        ss = getStringSlice(n)
        sds.append(ss)
    return sds

# -----------------------------------------

# This section contains functions to sort slices.

# sortIntSlice sorts an integer slice in ascending order.
def sortIntSlice(ns):
    ns.sort()
    return ns

# sortIntReverseSlice sorts an integer slice in descending order.
def sortIntReverseSlice(ns):
    ns.sort(reverse=True)
    return ns

# -----------------------------------------

# This section contains number-related utility functions.

# numAbs returns the absolute value of an integer.
def numAbs(x):
    if x < 0:
        return -x
    return x

# numModPow calculates a^n % m using modular exponentiation.
def numModPow(a, n, m):
    result = 1
    for i in range(n):
        if n%2 == 1:
            result = (result * a) % m
        a = (a * a) % m
        n //= 2
    return result

# numGcd calculates the greatest common divisor of two integers.
def numGcd(a, b):
    if b == 0:
        return a
    return numGcd(b, a%b)

# numLcm calculates the least common multiple of two integers.
def numLcm(a, b):
    return a * b // numGcd(a, b)

# numModInv calculates the modular multiplicative inverse of a under modulo p.
def numModInv(a, p):
    if a == 1:
        return 1
    return p - numModInv(p%a, p)*(p//a)%p

# numModFrac calculates the factorial of n under modulo constMod.
def numModFrac(n):
    frac = [1]
    for i in range(1, n+1):
        frac.append(i*frac[i-1]%constMod)
    return frac

# numModConb calculates the combination nCr under modulo constMod.
def numModConb(n, r):
    frac = numModFrac(n)
    return (frac[n] / ((frac[n-r] * frac[r]) % constMod)) % constMod

# -----------------------------------------

# solve function processes the main logic of the program.
def solve():
    n, m = getInt(), getInt()
    a = getIntSlice(n)

    sum = 0
    for v in a:
        sum += v

    count = 0
    for v in a:
        rate = sum / (4*m)
        if v >= rate:
            count += 1

    if count >= m:
        print("Yes")
    else:
        print("No")

# -----------------------------------------

if __name__ == "__main__":
    solve()