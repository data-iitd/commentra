import sys
import math

# Function to print a list with a specified separator
def printV(v, separator=" "):
    if v:
        print(separator.join(map(str, v[:-1])) + str(v[-1]))

# Function to check if a number is prime
def isPrime(num):
    if num < 2:
        return False
    elif num == 2:
        return True
    elif num % 2 == 0:
        return False
    sqrtNum = math.sqrt(num)
    for i in range(3, int(sqrtNum) + 1, 2):
        if num % i == 0:
            return False
    return True

# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
    return a * b // gcd(a, b)

# Function to find the maximum of three integers
def Max(a, b, c):
    return max(a, b, c)

# Function to find the minimum of three integers
def Min(a, b, c):
    return min(a, b, c)

# Function to check if a double is an integer
def integer(num):
    return math.floor(num) == num

# Recursive function to calculate factorial
def fact(num):
    if num == 0:
        return 1
    else:
        return num * fact(num - 1)

# Function to count the number of divisors of n
def yakusu(n):
    cnt = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            cnt += 1
            if i * i != n:
                cnt += 1
    return cnt

# Function to calculate factorial modulo a given number
def fact_mod(n, mod):
    f = 1
    for i in range(2, n + 1):
        f = f * (i % mod) % mod
    return f

# Function to perform modular exponentiation
def mod_pow(x, n, mod):
    res = 1
    while n > 0:
        if n & 1:
            res = (res * x) % mod
        x = (x * x) % mod
        n >>= 1
    return res

# Function to calculate combinations nCr modulo a given number
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
def rev(s):
    return s == s[::-1]

# Main function
def main():
    k, a, b = map(int, sys.stdin.readline().split())

    # Check for multiples of k in the range [a, b]
    for i in range(a, b + 1):
        if i % k == 0:
            print("OK")
            return
    print("NG")

if __name__ == "__main__":
    main()
