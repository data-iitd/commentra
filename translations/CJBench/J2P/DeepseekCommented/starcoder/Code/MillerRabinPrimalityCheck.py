import random
import sys

def miller_rabin(n, k):
    # Handle small numbers
    if n < 4:
        return n == 2 or n == 3
    # Decompose n-1 into d and s where d is odd and s is the number of times d can be divided by 2
    s = 0
    d = n - 1
    while d % 2 == 0:
        d >>= 1
        s += 1
    # Perform k iterations
    for i in range(k):
        # Select a random base a between 2 and n-3
        a = 2 + random.randint(0, n - 4)
        # Check if a is a witness for the compositeness of n
        if check_composite(n, a, d, s):
            return False
    return True

def check_composite(n, a, d, s):
    # Compute a^d mod n
    x = power_mod_p(a, d, n)
    # If x is 1 or n-1, n is probably prime
    if x == 1 or x == n - 1:
        return False
    # Iterate r times to check if x becomes n-1
    for r in range(1, s):
        x = power_mod_p(x, 2, n)
        if x == n - 1:
            return False
    return True

def power_mod_p(x, y, p):
    res = 1
    x %= p
    if x == 0:
        return 0
    while y > 0:
        if y & 1 == 1:
            res = (res * x) % p
        y >>= 1
        x = (x * x) % p
    return res

def deterministic_miller_rabin(n):
    # Handle small numbers
    if n < 2:
        return False
    # Decompose n-1 into d and r where d is odd and r is the number of times d can be divided by 2
    r = 0
    d = n - 1
    while d % 2 == 0:
        d >>= 1
        r += 1
    # Check n against a set of known prime numbers
    for a in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]:
        if n == a:
            return True
        if check_composite(n, a, d, r):
            return False
    return True

def main():
    # Read the long integer n from the user
    n = int(input())
    # Read the integer k from the user
    k = int(input())
    # Use the Miller-Rabin probabilistic test to check if n is probably prime with k iterations
    is_probably_prime = miller_rabin(n, k)
    # Print the result of the Miller-Rabin test
    print("Using Miller-Rabin Probabilistic Test: " + ("Probably Prime" if is_probably_prime else "Composite"))
    # Use the deterministic Miller-Rabin test to check if n is prime
    is_prime = deterministic_miller_rabin(n)
    # Print the result of the deterministic Miller-Rabin test
    print("Using Deterministic Miller-Rabin Test: " + ("Prime" if is_prime else "Composite"))

if __name__ == "__main__":
    main()

