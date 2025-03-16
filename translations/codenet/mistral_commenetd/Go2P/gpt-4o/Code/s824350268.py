import sys
import math

# Constants definition
initial_buf_size = 10000
max_buf_size = 1000000
mod = 10**9 + 7

# Helper functions for reading integers and strings from the standard input
def get_int():
    return int(sys.stdin.readline().strip())

def get_string():
    return sys.stdin.readline().strip()

# Helper functions for basic arithmetic operations
def abs_val(a):
    return abs(a)

def pow_mod(n, p):
    # Base case: if p is 0, return 1
    if p == 0:
        return 1
    elif p % 2 == 0:
        # Recursive case: if p is even, square the base and recursively call pow_mod
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        # Recursive case: if p is odd, multiply the base with the result of recursively calling pow_mod with p-1
        return calc_mod(n * pow_mod(n, p - 1))

# Helper functions for finding the minimum and maximum values
def min_val(*nums):
    if len(nums) == 0:
        raise ValueError("function min_val() requires at least one argument.")
    return min(nums)

def max_val(*nums):
    if len(nums) == 0:
        raise ValueError("function max_val() requires at least one argument.")
    return max(nums)

# Helper function for calculating the modulo operation
def calc_mod(x):
    return x % mod

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

# Main function
def main():
    # Read the first integer from the standard input
    N = get_int()

    # Calculate the square root of N
    sqrt_n = int(math.sqrt(N))

    # Initialize the minimum number with N
    min_num = N

    # Iterate through all numbers from 1 to the square root of N
    for i in range(1, sqrt_n + 1):
        # Check if N is divisible by i
        if N % i != 0:
            continue

        # Calculate the number of divisors of i and N
        num = i + (N // i) - 2

        # Update the minimum number if the current number is smaller
        if num < min_num:
            min_num = num

    # Print the minimum number
    print(min_num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
