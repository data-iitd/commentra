import sys
import math

# Function to check if a number is prime
def is_prime(num):
    if num < 2:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False

    sqrt_num = math.sqrt(num)
    for i in range(3, int(sqrt_num) + 1, 2):
        if num % i == 0:
            return False
    return True

# Function to calculate the greatest common divisor
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to calculate the least common multiple
def lcm(a, b):
    return a * b // gcd(a, b)

# Function to find the maximum of three numbers
def max_of_three(a, b, c):
    return max(a, max(b, c))

# Function to find the minimum of three numbers
def min_of_three(a, b, c):
    return min(a, min(b, c))

# Function to check if a number is an integer
def is_integer(num):
    return math.floor(num) == num

# Function to calculate factorial
def fact(num):
    if num == 0:
        return 1
    else:
        return num * fact(num - 1)

# Function to count the number of divisors
def count_divisors(n):
    cnt = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            cnt += 1
            if i != n // i:
                cnt += 1
    return cnt

# Function to calculate factorial modulo m
def fact_mod(n, mod):
    f = 1
    for i in range(2, n + 1):
        f = f * (i % mod) % mod
    return f

# Function to calculate x^n modulo m using repeated squaring method
def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = (res * x) % mod
        x = (x * x) % mod
        n >>= 1
    return res

# Function to calculate the number of combinations of n items taken r at a time modulo m
def combination_mod(n, r, mod):
    if r > n - r:
        r = n - r
    if r == 0:
        return 1
    a = 1
    for i in range(r):
        a = a * ((n - i) % mod) % mod
    b = mod_pow(fact_mod(r, mod), mod - 2, mod)
    return (a % mod) * (b % mod) % mod

# Function to check if a string is a palindrome
def is_palindrome(s):
    return s == s[::-1]

# Main function
def main():
    # Read input values for k, a, and b
    k, a, b = map(int, sys.stdin.readline().split())

    # Check if there exists an integer between a and b that is divisible by k
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")
            return

    print("NG")

if __name__ == "__main__":
    main()
