
import random

def miller_rabin(n, k):
    # Handle small values of n
    if n < 4:
        return n == 2 or n == 3 # 2 and 3 are prime
    
    # Initialize variables for the test
    s = 0
    d = n - 1
    
    # Factor n-1 into 2^s * d
    while d % 2 == 0:
        d //= 2
        s += 1
    
    # Create a Random object for generating random bases
    rnd = random.Random()
    
    # Perform k iterations of the test
    for i in range(k):
        # Choose a random base a in the range [2, n-2]
        a = 2 + abs(rnd.getrandbits(64)) % (n - 3) 
        # Check if n is composite with respect to base a
        if check_composite(n, a, d, s):
            return False # n is composite
    
    return True # n is probably prime

def check_composite(n, a, d, s):
    # Compute a^d mod n
    x = pow(a, d, n)
    
    # Check if x is 1 or n-1
    if x == 1 or x == n - 1:
        return False # n is not composite
    
    # Square x s-1 times and check for n-1
    for r in range(1, s):
        x = pow(x, 2, n)
        if x == n - 1:
            return False # n is not composite
    
    return True # n is composite

def deterministic_miller_rabin(n):
    # Handle values of n less than 2
    if n < 2:
        return False # 0 and 1 are not prime
    
    # Initialize variables for the test
    r = 0
    d = n - 1
    
    # Factor n-1 into 2^r * d
    while d % 2 == 0:
        d //= 2
        r += 1
    
    # Test against a set of known small prime bases
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        # If n is one of the small primes, return True
        if n == a:
            return True
        # Check if n is composite with respect to base a
        if check_composite(n, a, d, r):
            return False # n is composite
    
    return True # n is prime

# 