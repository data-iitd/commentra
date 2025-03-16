import sys
import math

# Utility Functions

# Reads the next input as a string
def next_str():
    return input().strip()

# Reads the next input as an integer
def next_int():
    return int(input().strip())

# Returns the maximum of two integers
def max_int(a, b):
    return max(a, b)

# Returns the minimum of two integers
def min_int(a, b):
    return min(a, b)

# Returns the absolute value of an integer
def abs_int(a):
    return abs(a)

# Returns the absolute value of a float
def abs_float(a):
    return abs(a)

# Returns the maximum of two float values
def max_float(a, b):
    return max(a, b)

# Returns the minimum of two float values
def min_float(a, b):
    return min(a, b)

# Converts a string to an integer
def str2int(s):
    return int(s)

# Reverses a string
def reverse(s):
    return s[::-1]

# Raises an integer to the power of another integer
def pow_int(p, q):
    return p ** q

# Checks if a number is prime
def is_prime(x):
    if x <= 1:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False

    for i in range(3, int(math.sqrt(x)) + 1, 2):
        if x % i == 0:
            return False
    return True

# Returns the prime factors of a number
def prime_factors(n):
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

# Returns the prime factors of a number as a dictionary
def prime_factors_map(n):
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

# Sums up a list of integers
def sum_ints(x):
    return sum(x)

# Computes the greatest common divisor of two integers
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Computes the least common multiple of two integers
def lcm(x, y):
    return x * y // gcd(x, y)

# Main Function
def main():
    N, M = map(int, next_str().split())
    tmp = min_int(N, M // 2)
    ans = 0
    ans += tmp
    N -= tmp
    M -= tmp * 2
    print(ans + M // 4)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
