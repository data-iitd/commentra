import random
import sys

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
        a = 2 + abs(random.randrange(n - 3))  # Generate a random number 'a' between 2 and 'n-1'
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

# Check if 'n' is composite given 'a', 'd', and 's'
def check_composite(n, a, d, s):
    # Calculate 'x' = a^d mod n
    x = power_mod_p(a, d, n)

    # Check base cases
    if x == 1 or x == n - 1:
        return False

    # If 'x' is not a power of 2, 'n' is composite
    for _ in range(s):
        x = power_mod_p(x, 2, n)
        if x == n - 1:
            return False

    # If all tests pass, 'n' is probably composite
    return True

# Calculate 'x' = a^y mod p
def power_mod_p(a, y, p):
    # Calculate 'x' as the product of 'a' raised to the power of each bit in 'y'
    res = 1
    a %= p
    if a == 0:
        return 0
    while y > 0:
        if y & 1:
            res = multiply_mod_p(res, a, p)
        a = multiply_mod_p(a, a, p)
        y >>= 1
    return res

# Multiply 'a' and 'b' modulo 'p'
def multiply_mod_p(a, b, p):
    # Calculate the product of 'a' and 'b'
    res = 0
    a %= p
    while b > 0:
        if b & 1:
            res = (res + a) % p
        a = (2 * a) % p
        b >>= 1
    return res

# Main method to start the program
def main():
    # Create a new Scanner object for user input
    scanner = sys.stdin
    n = int(scanner.readline().strip())  # Read the first number 'n' from the user input
    k = int(scanner.readline().strip())  # Read the second number 'k' from the user input

    # Perform probabilistic Miller-Rabin test
    is_probably_prime = miller_rabin(n, k)
    print("Using Miller-Rabin Probabilistic Test: " + ("Probably Prime" if is_probably_prime else "Composite"))

    # Perform deterministic Miller-Rabin test
    is_prime = deterministic_miller_rabin(n)
    print("Using Deterministic Miller-Rabin Test: " + ("Prime" if is_prime else "Composite"))

if __name__ == "__main__":
    main()
