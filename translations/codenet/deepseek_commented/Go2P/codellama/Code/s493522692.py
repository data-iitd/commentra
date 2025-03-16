
#!/usr/bin/env python3

import sys
import math

# Utility Functions

# Reads the next input as a string
def nextStr():
    return sys.stdin.readline().strip()

# Reads the next input as an integer
def nextInt():
    return int(sys.stdin.readline().strip())

# Returns the maximum of two integers
def maxInt(a, b):
    if a > b:
        return a
    else:
        return b

# Returns the minimum of two integers
def minInt(a, b):
    if a > b:
        return b
    else:
        return a

# Returns the absolute value of an integer
def absInt(a):
    if a >= 0:
        return a
    else:
        return -a

# Returns the absolute value of a float64
def absFloat64(a):
    if a >= 0:
        return a
    else:
        return -a

# Returns the maximum of two float64 values
def maxFloat64(a, b):
    if a > b:
        return a
    else:
        return b

# Returns the minimum of two float64 values
def minFloat64(a, b):
    if a > b:
        return b
    else:
        return a

# Converts a string to an integer
def str2Int(s):
    return int(s)

# Reverses a string
def reverse(s):
    return s[::-1]

# Raises an integer to the power of another integer
def powInt(p, q):
    return int(math.pow(p, q))

# Checks if a number is prime
def isPrime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    b = True
    rootx = int(math.sqrt(x))
    i = 3
    for i in range(3, rootx + 1, 2):
        if x % i == 0:
            b = False
            break
    return b

# Returns the prime factors of a number
def PrimeFactors(n):
    pfs = []
    # Get the number of 2s that divide n
    while n % 2 == 0:
        pfs.append(2)
        n = n // 2

    # n must be odd at this point. so we can skip one element
    # (note i = i + 2)
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs.append(i)
            n = n // i
    # This condition is to handle the case when n is a prime number
    # greater than 2
    if n > 2:
        pfs.append(n)
    return pfs

# Returns the prime factors of a number as a map
def PrimeFactorsMap(n):
    pfs = {}
    # Get the number of 2s that divide n
    while n % 2 == 0:
        if 2 in pfs:
            pfs[2] += 1
        else:
            pfs[2] = 1
        #pfs = append(pfs, 2)
        n = n // 2

    # n must be odd at this point. so we can skip one element
    # (note i = i + 2)
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            if i in pfs:
                pfs[i] += 1
            else:
                pfs[i] = 1
            n = n // i
    # This condition is to handle the case when n is a prime number
    # greater than 2
    if n > 2:
        if n in pfs:
            pfs[n] += 1
        else:
            pfs[n] = 1
    return pfs

# Sums up a slice of integers
def sumInts(x):
    total = 0
    for v in x:
        total += v
    return total

# Computes the greatest common divisor of two integers
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Computes the least common multiple of two integers
def lcm(x, y):
    return x * y // gcd(x, y)

# Constants and Variables

# 'S'がN個、'c'がM個
N, M = nextInt(), nextInt()
tmp = minInt(N, M // 2)
ans = 0
ans += tmp
N -= tmp
M -= tmp * 2
#fmt.Println(ans, N, M)
print(ans + M // 4)

