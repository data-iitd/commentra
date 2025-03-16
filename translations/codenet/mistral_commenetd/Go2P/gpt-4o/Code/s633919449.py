import sys
import math
from collections import deque

# Constants for modulo value
MOD = int(1e9 + 7)

def main():
    # Read an integer input
    N = get_int()

    # Determine the output based on the last digit of N
    if N % 10 in {2, 4, 5, 7, 9}:
        print("hon")
    elif N % 10 in {0, 1, 6, 8}:
        print("pon")
    elif N % 10 == 3:
        print("bon")

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read an array of integers from input
def get_int_array(n):
    return list(map(int, sys.stdin.readline().strip().split()))[:n]

# Function to read a string from input
def get_string():
    return sys.stdin.readline().strip()

# Function to read an array of strings from input
def get_string_array(n):
    return [get_string() for _ in range(n)]

# Function to calculate the absolute value of an integer
def abs_value(a):
    return abs(a)

# Function to calculate p raised to the power of q
def pow_func(p, q):
    return int(p ** q)

# Function to calculate n raised to the power of p modulo mod
def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        return calc_mod(n * pow_mod(n, p - 1))

# Function to find the minimum value among a list of integers
def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")
    return min(nums)

# Function to find the maximum value among a list of integers
def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")
    return max(nums)

# Function to check if a string exists in an array of strings
def str_search(a, b):
    return b in a

# Function to print an array of integers
def print_int_array(array):
    print(" ".join(map(str, array)))

# Function to calculate x modulo mod
def calc_mod(x):
    return x % MOD

# Function to reverse a string
def reverse(s):
    return s[::-1]

# Function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False

    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False

    return True

# Function to check if an integer exists in a list
def contains(s, e):
    return e in s

# Function to create a range of integers from min to max
def make_range(min_val, max_val):
    return list(range(min_val, max_val + 1))

# Function to generate the powerset of a given list of integers
def powerset(nums):
    length = 2 ** len(nums)
    result = [[]]

    # Generate all subsets
    for n in nums:
        max_index = len(result)
        for i in range(max_index):
            result.append(result[i] + [n])

    return result

# Function to calculate the greatest common divisor (GCD) of two integers
def calc_gcd(x, y):
    if y == 0:
        return x
    return calc_gcd(y, x % y)

# Function to get all divisors of a number
def get_divisors(n):
    divisors = set()
    divisors.add(1)
    if n != 1:
        divisors.add(n)

    sqrt_n = int(math.sqrt(n))
    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)

    return list(divisors)

# Function to calculate factorial modulo mod
def fact_mod(n):
    value = 1
    for i in range(2, n + 1):
        value = calc_mod(value * i)
    return value

# Function to calculate combinations modulo mod
def combination_mod(n, k):
    fact_n = fact_mod(n)
    fact_k = fact_mod(k)
    fact_n_k = fact_mod(n - k)
    fact_k_inv = pow_mod(fact_k, MOD - 2)
    fact_n_k_inv = pow_mod(fact_n_k, MOD - 2)
    return calc_mod(fact_n * calc_mod(fact_k_inv * fact_n_k_inv))

# Function to find prime factors of a number
def prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        if n % i == 0:
            factors.append(i)
            n //= i
        else:
            i += 1
    if n > 1:
        factors.append(n)
    return factors

if __name__ == "__main__":
    main()

# <END-OF-CODE>
