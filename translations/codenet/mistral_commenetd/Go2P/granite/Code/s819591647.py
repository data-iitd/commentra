
#problem_b.py
# This is the main file for problem B solution

import sys
import math

# -----------------------------------------

# Function definitions

def getInt(): # Function to read an integer from standard input
    return int(sys.stdin.readline())

def getIntSlice(n): # Function to read n integers and return a slice
    return [getInt() for _ in range(n)]

def getString(): # Function to read a string from standard input
    return sys.stdin.readline().strip()

def getStringSlice(n): # Function to read n strings and return a slice
    return [getString() for _ in range(n)]

def getStringDoubleSlice(m, n): # Function to read m strings of length n and return a 2D slice
    return [[getString() for _ in range(n)] for _ in range(m)]

# -----------------------------------------

# Sorting functions

def sortIntSlice(ns): # Function to sort an integer slice in ascending order
    return sorted(ns)

def sortIntReverseSlice(ns): # Function to sort an integer slice in descending order
    return sorted(ns, reverse=True)

# -----------------------------------------

# Mathematical functions

#numAbs(x) = abs(s)
def numAbs(x): # Function to get absolute value of an integer
    return abs(x)

#numModPow(a, n, m) = a^n % m
def numModPow(a, n, m): # Function to calculate a^n % m
    result = 1

    for _ in range(n):
        if n % 2 == 1:
            result = (result * a) % m

        a = (a * a) % m
        n //= 2

    return result

# numGcd(a, b) = gcd(a, b)
def numGcd(a, b): # Function to calculate the greatest common divisor of a and b
    if b == 0:
        return a

    return numGcd(b, a % b)

# numLcm(a, b) = lcm(a, b)
def numLcm(a, b): # Function to calculate the least common multiple of a and b
    return a * b // numGcd(a, b)

# numModInv(a, p) = a^(-1) % p
def numModInv(a, p): # Function to calculate the modular inverse of a modulo p
    if a == 1:
        return 1

    return p - numModInv(p % a, p) * (p // a) % p

# numModFrac(n) = n! % constMod
def numModFrac(n): # Function to calculate n! modulo constMod
    frac = [1]

    for i in range(1, n + 1):
        frac.append(i * frac[i - 1] % constMod)

    return frac

# numModConb(n, r) = nCr % constMod
def numModConb(n, r): # Function to calculate nCr modulo constMod
    frac = numModFrac(n)

    return (frac[n] // ((frac[n - r] * frac[r]) % constMod)) % constMod

# -----------------------------------------

# Main function

def solve(): # Function to solve the problem
    n, m = getInt(), getInt()
    a = getIntSlice(n)

    sum = 0
    for v in a:
        sum += v

    count = 0
    for v in a:
        rate = sum / (4 * m)
        if v >= rate:
            count += 1

    if count >= m:
        print("Yes")
    else:
        print("No")

# -----------------------------------------

if __name__ == "__main__": # Main function
    solve()