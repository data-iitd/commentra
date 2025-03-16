
import random
import sys

# Initialize random number generator
random.seed(1)

# Read the first number 'n' from the user input
n = int(sys.stdin.readline())

# Read the second number 'k' from the user input
k = int(sys.stdin.readline())

# Perform probabilistic Miller-Rabin test
isProbablyPrime = millerRabin(n, k)
print("Using Miller-Rabin Probabilistic Test: " + ("Probably Prime" if isProbablyPrime else "Composite"))

# Perform deterministic Miller-Rabin test
isPrime = deterministicMillerRabin(n)
print("Using Deterministic Miller-Rabin Test: " + ("Prime" if isPrime else "Composite"))

# Probabilistic Miller-Rabin test
def millerRabin(n, k):
    # Check base cases
    if n < 4:
        return n == 2 or n == 3

    # Initialize variables
    s = 0
    d = n - 1

    # Find the largest power of 2 that divides 'd'
    while (d & 1) == 0:
        d >>= 1
        s += 1

    # Generate random 'a' values and check for compositeness
    for i in range(k):
        a = 2 + random.randint(0, n - 3) # Generate a random number 'a' between 2 and 'n-1'
        if checkComposite(n, a, d, s): # If 'n' is composite, return false
            return False

    # If all tests pass, 'n' is probably prime
    return True

# Deterministic Miller-Rabin test
def deterministicMillerRabin(n):
    # Check base cases
    if n < 2:
        return False

    # Initialize variables
    r = 0
    d = n - 1

    # Find the largest power of 2 that divides 'd'
    while (d & 1) == 0:
        d >>= 1
        r += 1

    # Check for small prime factors
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a: # If 'n' is a small prime, return true
            return True
        if checkComposite(n, a, d, r): # If 'n' is composite, return false
            return False

    # If all tests pass, 'n' is prime
    return True

# Check if 'n' is composite given 'a', 'd', and's'
def checkComposite(n, a, d, s):
    # Calculate 'x' = a^d mod n
    x = powerModP(a, d, n)

    # Check base cases
    if x == 1 or x == n - 1:
        return False

    # If 'x' is not a power of 2, 'n' is composite
    for r in range(1, s):
        x = powerModP(x, 2, n)
        if x == n - 1:
            return False

    # If all tests pass, 'n' is probably composite
    return True

# Calculate 'x' = a^y mod p
def powerModP(a, y, p):
    # Calculate 'x' as the product of 'a' raised to the power of each bit in 'y'
    res = 1
    a %= p
    if a == 0:
        return 0
    while y > 0:
        if (y & 1) == 1:
            res = multiplyModP(res, a, p)
        a = multiplyModP(a, a, p)
        y >>= 1
    return res

# Multiply 'a' and 'b' modulo 'p'
def multiplyModP(a, b, p):
    # Calculate the product of 'a' and 'b'
    res = 0
    a %= p
    while b > 0:
        if (b & 1) == 1:
            res = (res + a) % p
        a = (2 * a) % p
        b >>= 1
    return res

# 