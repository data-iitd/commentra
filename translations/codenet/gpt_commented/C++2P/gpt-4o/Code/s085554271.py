import sys
import math

# Constants for convenience
MOD = 1000000007

# Function to check if a number is prime
def is_prime(num):
    if num < 2:
        return False  # Numbers less than 2 are not prime
    elif num == 2:
        return True  # 2 is prime
    elif num % 2 == 0:
        return False  # Exclude even numbers

    sqrt_num = int(math.sqrt(num))  # Calculate square root for optimization
    for i in range(3, sqrt_num + 1, 2):  # Check for factors from 3 to sqrt(num)
        if num % i == 0:
            return False  # Not a prime number

    return True  # Number is prime

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    return gcd(b, a % b) if b != 0 else a  # Recursive GCD calculation

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a // gcd(a, b) * b  # LCM using GCD

# Function to find the maximum of three integers
def max_of_three(a, b, c):
    return max(a, b, c)  # Return the maximum value

# Function to find the minimum of three integers
def min_of_three(a, b, c):
    return min(a, b, c)  # Return the minimum value

# Function to check if a double is an integer
def is_integer(num):
    return math.floor(num) == num  # Check if the number is an integer

# Recursive function to calculate factorial
def factorial(num):
    if num == 0:
        return 1  # Base case for factorial
    else:
        return num * factorial(num - 1)  # Recursive case

# Function to count the number of divisors of n
def count_divisors(n):
    cnt = 0  # Counter for divisors
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            cnt += 1  # Count the divisor
            if i * i != n:
                cnt += 1  # Count the complementary divisor if it's different
    return cnt  # Return the count of divisors

# Function to calculate factorial modulo a given number
def factorial_mod(n, mod):
    f = 1
    for i in range(2, n + 1):
        f = f * (i % MOD) % MOD  # Calculate factorial with modulo
    return f  # Return the result

# Function to perform modular exponentiation
def mod_pow(x, n, mod):
    res = 1  # Initialize result
    while n > 0:
        if n & 1:
            res = (res * x) % mod  # If n is odd, multiply x with result
        x = (x * x) % mod  # Square x
        n >>= 1  # Divide n by 2
    return res  # Return the result

# Function to calculate combinations nCr modulo a given number
def combination_mod(n, r, mod):
    if r > n - r:
        r = n - r  # Use symmetry property of combinations
    if r == 0:
        return 1  # Base case for combinations
    a = 1
    for i in range(r):
        a = a * ((n - i) % mod) % mod  # Calculate numerator
    b = mod_pow(factorial_mod(r, mod), mod - 2, mod)  # Calculate denominator using Fermat's Little Theorem
    return (a % mod) * (b % mod) % mod  # Return the result

# Function to check if a string is a palindrome
def is_palindrome(s):
    return s == s[::-1]  # Check if the original string is equal to the reversed string

# Main function
def main():
    k, a, b = map(int, input().split())  # Input values for k, a, and b

    # Check for multiples of k in the range [a, b]
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")  # Output OK if a multiple is found
            return  # Exit the program
    print("NG")  # Output NG if no multiples are found

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
