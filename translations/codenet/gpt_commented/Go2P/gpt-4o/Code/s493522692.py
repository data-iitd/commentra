import sys
import math

# Utility functions for input and mathematical operations

# next_str reads the next string from input
def next_str():
    return input().strip()

# next_int reads the next integer from input
def next_int():
    return int(input().strip())

# max_int returns the maximum of two integers
def max_int(a, b):
    return a if a > b else b

# min_int returns the minimum of two integers
def min_int(a, b):
    return a if a < b else b

# abs_int returns the absolute value of an integer
def abs_int(a):
    return a if a >= 0 else -a

# abs_float returns the absolute value of a float
def abs_float(a):
    return a if a >= 0 else -a

# max_float returns the maximum of two float values
def max_float(a, b):
    return a if a > b else b

# min_float returns the minimum of two float values
def min_float(a, b):
    return a if a < b else b

# str2int converts a string to an integer
def str2int(s):
    return int(s)

# reverse returns the reversed string
def reverse(s):
    return s[::-1]

# pow_int calculates p raised to the power of q
def pow_int(p, q):
    return int(math.pow(p, q))

# is_prime checks if a number is prime
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

# prime_factors returns the prime factors of a number
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

# prime_factors_map returns a map of prime factors and their counts
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

# sum_ints returns the sum of a list of integers
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
    N, M = next_int(), next_int()
    tmp = min_int(N, M // 2)  # Calculate the minimum of N and half of M
    ans = 0
    ans += tmp  # Add the temporary value to the answer
    N -= tmp  # Decrease N by the temporary value
    M -= tmp * 2  # Decrease M by twice the temporary value
    # Output the final answer, which includes the remaining M divided by 4
    print(ans + M // 4)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
