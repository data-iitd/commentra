

import random

# Initialize random number generator
rng = random.SystemRandom()

# Probabilistic Miller-Rabin test
def miller_rabin(n, k):
    # Check base cases
    if n < 4:
        return n == 2 or n == 3

    # Initialize variables
    s = 0
    d = n - 1

    # Find the largest power of 2 that divides 'd'
    while d % 2 == 0:
        d //= 2
        s += 1

    # Generate random 'a' values and check for compositeness
    for _ in range(k):
        a = 2 + abs(rng.getrandbits(64)) % (n - 3)  # Generate a random number 'a' between 2 and 'n-1'
        if check_composite(n, a, d, s):  # If 'n' is composite, return False
            return False

    # If all tests pass, 'n' is probably prime
    return True

# Deterministic Miller-Rabin test
def deterministic_miller_rabin(n):
    # Check base cases
    if n < 2:
        return False

    # Initialize variables
    r = 0
    d = n - 1

    # Find the largest power of 2 that divides 'd'
    while d % 2 == 0:
        d //= 2
        r += 1

    # Check for small prime factors
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a:  # If 'n' is a small prime, return True
            return True
        if check_composite(n, a, d, r):  # If 'n' is composite, return False
            return False

    # If all tests pass, 'n' is prime
    return True

# Check if 'n' is composite given 'a', 'd', and's'
def check_composite(n, a, d, s):
    # Calculate 'x' = a^d mod n
    x = pow(a, d, n)

    # Check base cases
    if x == 1 or x == n - 1:
        return False

    # If 'x' is not a power of 2, 'n' is composite
    for _ in range(1, s):
        x = pow(x, 2, n)
        if x == n - 1:
            return False

    # If all tests pass, 'n' is probably composite
    return True

# Translate the above Java code to Python and end with comment "