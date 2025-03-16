

import math
import os
import sys

# Utility functions for input and mathematical operations

# nextStr reads the next string from input
def nextStr():
    return input()

# nextInt reads the next integer from input
def nextInt():
    return int(input())

# maxInt returns the maximum of two integers
def maxInt(a, b):
    if a > b:
        return a
    else:
        return b

# minInt returns the minimum of two integers
def minInt(a, b):
    if a > b:
        return b
    else:
        return a

# absInt returns the absolute value of an integer
def absInt(a):
    if a >= 0:
        return a
    else:
        return -a

# absFloat64 returns the absolute value of a float64
def absFloat64(a):
    if a >= 0:
        return a
    else:
        return -a

# maxFloat64 returns the maximum of two float64 values
def maxFloat64(a, b):
    if a > b:
        return a
    else:
        return b

# minFloat64 returns the minimum of two float64 values
def minFloat64(a, b):
    if a > b:
        return b
    else:
        return a

# str2Int converts a string to an integer
def str2Int(s):
    return int(s)

# reverse returns the reversed string
def reverse(s):
    return s[::-1]

# powInt calculates p raised to the power of q
def powInt(p, q):
    return int(math.pow(p, q))

# isPrime checks if a number is prime
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
    while i <= rootx:
        if x % i == 0:
            b = False
            break
        i += 2
    return b

# PrimeFactors returns the prime factors of a number
def PrimeFactors(n):
    # Get the number of 2s that divide n
    pfs = []
    while n % 2 == 0:
        pfs.append(2)
        n = n / 2

    # n must be odd at this point, so we can skip one element
    i = 3
    while i * i <= n:
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs.append(i)
            n = n / i
        i = i + 2

    # Handle the case when n is a prime number greater than 2
    if n > 2:
        pfs.append(n)

    return pfs

# PrimeFactorsMap returns a map of prime factors and their counts
def PrimeFactorsMap(n):
    pfs = {}
    # Get the number of 2s that divide n
    while n % 2 == 0:
        if 2 in pfs:
            pfs[2] += 1
        else:
            pfs[2] = 1
        n = n / 2

    # n must be odd at this point, so we can skip one element
    i = 3
    while i * i <= n:
        # while i divides n, append i and divide n
        while n % i == 0:
            if i in pfs:
                pfs[i] += 1
            else:
                pfs[i] = 1
            n = n / i
        i = i + 2

    # Handle the case when n is a prime number greater than 2
    if n > 2:
        if n in pfs:
            pfs[n] += 1
        else:
            pfs[n] = 1

    return pfs

# sumInts returns the sum of a slice of integers
def sumInts(x):
    total = 0
    for v in x:
        total += v
    return total

# gcd calculates the greatest common divisor of two integers
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# lcm calculates the least common multiple of two integers
def lcm(x, y):
    return x * y // gcd(x, y)

# Main function
const (
    initialBufSize = 10000 // Initial buffer size for input
    maxBufSize     = 1000000 // Maximum buffer size for input
    mod            = 1e9 + 7 // Modulus value
)

def main():
    # Read the number of 'S' and 'c'
    N, M = int(input()), int(input())
    tmp = min(N, M // 2) # Calculate the minimum of N and half of M
    ans = 0
    ans += tmp # Add the temporary value to the answer
    N -= tmp # Decrease N by the temporary value
    M -= tmp * 2 # Decrease M by twice the temporary value
    # Output the final answer, which includes the remaining M divided by 4
    print(ans + M // 4)

if __name__ == '__main__':
    main()

