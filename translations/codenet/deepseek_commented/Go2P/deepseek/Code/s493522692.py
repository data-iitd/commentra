import sys
import math

# Utility Functions

# Reads the next input as a string
def next_str():
    return input().strip()

# Reads the next input as an integer
def next_int():
    return int(next_str())

# Returns the maximum of two integers
def max_int(a, b):
    return a if a > b else b

# Returns the minimum of two integers
def min_int(a, b):
    return a if a < b else b

# Returns the absolute value of an integer
def abs_int(a):
    return a if a >= 0 else -a

# Returns the absolute value of a float64
def abs_float64(a):
    return a if a >= 0 else -a

# Returns the maximum of two float64 values
def max_float64(a, b):
    return a if a > b else b

# Returns the minimum of two float64 values
def min_float64(a, b):
    return a if a < b else b

# Converts a string to an integer
def str2_int(s):
    return int(s)

# Reverses a string
def reverse(s):
    return s[::-1]

# Raises an integer to the power of another integer
def pow_int(p, q):
    return p ** q

# Checks if a number is prime
def is_prime(x):
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    rootx = int(math.sqrt(x))
    for i in range(3, rootx + 1, 2):
        if x % i == 0:
            return False
    return True

# Returns the prime factors of a number
def prime_factors(n):
    pfs = []
    # Get the number of 2s that divide n
    while n % 2 == 0:
        pfs.append(2)
        n //= 2

    # n must be odd at this point. so we can skip one element
    # (note i = i + 2)
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs.append(i)
            n //= i

    # This condition is to handle the case when n is a prime number
    # greater than 2
    if n > 2:
        pfs.append(n)

    return pfs

# Returns the prime factors of a number as a map
def prime_factors_map(n):
    pfs = {}
    # Get the number of 2s that divide n
    while n % 2 == 0:
        pfs[2] = pfs.get(2, 0) + 1
        n //= 2

    # n must be odd at this point. so we can skip one element
    # (note i = i + 2)
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs[i] = pfs.get(i, 0) + 1
            n //= i

    # This condition is to handle the case when n is a prime number
    # greater than 2
    if n > 2:
        pfs[n] = pfs.get(n, 0) + 1

    return pfs

# Sums up a slice of integers
def sum_ints(x):
    total = 0
    for v in x:
        total += v
    return total

# Computes the greatest common divisor of two integers
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Computes the least common multiple of two integers
def lcm(x, y):
    return x * y // gcd(x, y)

# Constants and Variables

mod = 10**9 + 7

# Main Function
def main():
    # 'S'がN個、'c'がM個
    N, M = map(int, input().split())
    tmp = min(N, M // 2)
    ans = tmp
    N -= tmp
    M -= tmp * 2
    #print(ans, N, M)
    print(ans + M // 4)

if __name__ == "__main__":
    main()
