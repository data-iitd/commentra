import math

# Util functions
def next_str():
    # Scans the next token from input and returns it as a string.
    return input().strip()

def next_int():
    # Scans the next token from input, converts it to an integer, and returns it.
    return int(input().strip())

# Helper functions for mathematical operations
def max_int(a, b):
    # Returns the maximum of two integers.
    return a if a > b else b

def min_int(a, b):
    # Returns the minimum of two integers.
    return b if a > b else a

def abs_int(a):
    # Returns the absolute value of an integer.
    return a if a >= 0 else -a

def abs_float(a):
    # Returns the absolute value of a floating-point number.
    return a if a >= 0 else -a

def max_float(a, b):
    # Returns the maximum of two floating-point numbers.
    return a if a > b else b

def min_float(a, b):
    # Returns the minimum of two floating-point numbers.
    return b if a > b else a

def str2int(s):
    # Converts a string to an integer.
    return int(s)

def reverse(s):
    # Reverses a given string.
    return s[::-1]

def pow_int(p, q):
    # Calculates 'p' raised to the power of 'q'.
    return int(math.pow(p, q))

def is_prime(x):
    # Checks if a given number is prime.
    if x == 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(x)) + 1, 2):
        if x % i == 0:
            return False
    return True

def prime_factors(n):
    # Finds the prime factors of a given number.
    pfs = []
    while n % 2 == 0:
        pfs.append(2)
        n //= 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            pfs.append(i)
            n //= i

    if n > 2:
        pfs.append(n)

    return pfs

def prime_factors_map(n):
    # Finds the prime factors of a given number and returns them as a map.
    pfs = {}
    while n % 2 == 0:
        pfs[2] = pfs.get(2, 0) + 1
        n //= 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            pfs[i] = pfs.get(i, 0) + 1
            n //= i

    if n > 2:
        pfs[n] = pfs.get(n, 0) + 1

    return pfs

# <END-OF-CODE>
