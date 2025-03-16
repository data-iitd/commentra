import sys
import math

# Utility functions for input and mathematical operations

# nextStr reads the next string from input
def next_str():
    return input().strip()

# nextInt reads the next integer from input
def next_int():
    return int(next_str())

# maxInt returns the maximum of two integers
def max_int(a, b):
    return a if a > b else b

# minInt returns the minimum of two integers
def min_int(a, b):
    return a if a < b else b

# absInt returns the absolute value of an integer
def abs_int(a):
    return a if a >= 0 else -a

# absFloat64 returns the absolute value of a float64
def abs_float64(a):
    return a if a >= 0 else -a

# maxFloat64 returns the maximum of two float64 values
def max_float64(a, b):
    return a if a > b else b

# minFloat64 returns the minimum of two float64 values
def min_float64(a, b):
    return a if a < b else b

# str2Int converts a string to an integer
def str2_int(s):
    return int(s)

# reverse returns the reversed string
def reverse(s):
    return s[::-1]

# powInt calculates p raised to the power of q
def pow_int(p, q):
    return p ** q

# isPrime checks if a number is prime
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

# PrimeFactors returns the prime factors of a number
def prime_factors(n):
    pfs = []
    # Get the number of 2s that divide n
    while n % 2 == 0:
        pfs.append(2)
        n //= 2

    # n must be odd at this point, so we can skip one element
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs.append(i)
            n //= i

    # Handle the case when n is a prime number greater than 2
    if n > 2:
        pfs.append(n)

    return pfs

# PrimeFactorsMap returns a map of prime factors and their counts
def prime_factors_map(n):
    pfs = {}
    # Get the number of 2s that divide n
    while n % 2 == 0:
        pfs[2] = pfs.get(2, 0) + 1
        n //= 2

    # n must be odd at this point, so we can skip one element
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        # while i divides n, append i and divide n
        while n % i == 0:
            pfs[i] = pfs.get(i, 0) + 1
            n //= i

    # Handle the case when n is a prime number greater than 2
    if n > 2:
        pfs[n] = pfs.get(n, 0) + 1

    return pfs

# sumInts returns the sum of a list of integers
def sum_ints(x):
    return sum(x)

# gcd calculates the greatest common divisor of two integers
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# lcm calculates the least common multiple of two integers
def lcm(x, y):
    return x * y // gcd(x, y)

# Main function
def main():
    # Read the number of 'S' and 'c'
    N, M = map(int, input().split())
    tmp = min(N, M // 2)  # Calculate the minimum of N and half of M
    ans = tmp  # Add the temporary value to the answer
    N -= tmp  # Decrease N by the temporary value
    M -= tmp * 2  # Decrease M by twice the temporary value
    # Output the final answer, which includes the remaining M divided by 4
    print(ans + M // 4)

if __name__ == "__main__":
    main()
