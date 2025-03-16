import sys
import math
from collections import deque

# Constants for modulo value
MOD = int(1e9 + 7)

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read an array of integers from input
def get_int_array(n):
    return list(map(int, sys.stdin.readline().strip().split()))[:n]

# Function to calculate the absolute value of an integer
def abs_val(a):
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

# Function to calculate x modulo mod
def calc_mod(x):
    return x % MOD

# Function to find the minimum value among a list of integers
def min_val(*nums):
    if len(nums) == 0:
        raise ValueError("function min_val() requires at least one argument.")
    return min(nums)

# Function to find the maximum value among a list of integers
def max_val(*nums):
    if len(nums) == 0:
        raise ValueError("function max_val() requires at least one argument.")
    return max(nums)

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

# Main function
def main():
    # Read an integer input
    N = get_int()

    # Determine the output based on the last digit of N
    last_digit = N % 10
    if last_digit in {2, 4, 5, 7, 9}:
        print("hon")
    elif last_digit in {0, 1, 6, 8}:
        print("pon")
    elif last_digit == 3:
        print("bon")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
