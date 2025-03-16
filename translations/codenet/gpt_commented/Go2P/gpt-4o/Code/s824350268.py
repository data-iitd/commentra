import sys
import math

# Constants for modulo value
MOD = int(1e9 + 7)

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read an integer N from input
    N = get_int()
    # Calculate the integer square root of N
    sqrtN = int(math.sqrt(N))

    # Initialize min to N, which will hold the minimum value found
    min_value = N
    # Iterate through all possible divisors of N
    for i in range(1, sqrtN + 1):
        # If i is not a divisor of N, skip to the next iteration
        if N % i != 0:
            continue

        # Calculate the value based on the divisor and its complement
        num = i + (N // i) - 2
        # Update min if the new value is smaller
        if num < min_value:
            min_value = num

    # Print the minimum value found
    print(min_value)

# Function to compute (n^p) % mod using exponentiation by squaring
def pow_mod(n, p):
    if p == 0:
        return 1
    elif p % 2 == 0:
        t = pow_mod(n, p // 2)
        return calc_mod(t * t)
    else:
        return calc_mod(n * pow_mod(n, p - 1))

# Function to calculate x % mod
def calc_mod(x):
    return x % MOD

# Function to find the minimum value among a variable number of integers
def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")
    return min(nums)

# Function to find the maximum value among a variable number of integers
def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")
    return max(nums)

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

    # Check for factors from 3 to the square root of n
    sqrtN = int(math.sqrt(n))
    for i in range(3, sqrtN + 1, 2):
        if n % i == 0:
            return False

    return True

if __name__ == "__main__":
    main()

# <END-OF-CODE>
