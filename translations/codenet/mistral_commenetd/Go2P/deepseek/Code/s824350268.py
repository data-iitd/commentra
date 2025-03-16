import math
import sys

# Constants definition
initialBufSize = 10000
maxBufSize = 1000000
mod = 10**9 + 7

# Variables definition and initialization
input = sys.stdin.readline

# Main function
def main():
    # Read the first integer from the standard input
    N = get_int()

    # Calculate the square root of N
    sqrtN = int(math.sqrt(N))

    # Initialize the minimum number with N
    min_num = N

    # Iterate through all numbers from 1 to the square root of N
    for i in range(1, sqrtN + 1):
        # Check if N is divisible by i
        if N % i != 0:
            continue

        # Calculate the number of divisors of i and N
        num = i + (N // i) - 2

        # Update the minimum number if the current number is smaller
        min_num = min(min_num, num)

    # Print the minimum number
    print(min_num)

# Helper functions for reading integers and strings from the standard input
def get_int():
    return int(input())

def get_string():
    return input()

# Helper functions for basic arithmetic operations
def abs(a):
    return int(math.fabs(a))

def pow(p, q):
    return int(math.pow(p, q))

def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return (t * t) % mod
    else:
        return (n * pow_mod(n, p - 1)) % mod

# Helper functions for finding the minimum and maximum values
def min(nums):
    return min(nums)

def max(nums):
    return max(nums)

# Helper function for searching a string in an array of strings
def str_search(a, b):
    return b in a

# Helper function for printing an integer array
def print_int_array(array):
    print(array)

# Helper function for calculating the modulo operation
def calc_mod(x):
    return x % mod

# Helper function for reversing a string
def reverse(s):
    return s[::-1]

# Helper function for checking if a number is prime
def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    sqrt_n = int(math.sqrt(n))
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return False
    return True

