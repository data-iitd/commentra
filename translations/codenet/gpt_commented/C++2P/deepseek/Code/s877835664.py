import sys
from collections import defaultdict

# Function to compute the greatest common divisor (GCD) of two numbers
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to compute the least common multiple (LCM) of two numbers
def lcm(a, b):
    return a // gcd(a, b) * b

# Function to get the prime factorization of a number
def get_prime_factor(n):
    res = defaultdict(int)
    # Iterate from 2 to the square root of n
    i = 2
    while i * i <= n:
        # While i divides n, store i in the result map
        while n % i == 0:
            res[i] += 1
            n //= i
        i += 1
    # If n is still greater than 1, it is a prime factor
    if n > 1:
        res[n] = 1
    return res

# Function to check if a number is prime
def is_prime_number(num):
    if num <= 2:
        return True  # 0, 1, and 2 are considered prime
    elif num % 2 == 0:
        return False  # Exclude even numbers

    sqrt_num = int(num**0.5)
    # Check for factors from 3 to the square root of num
    for i in range(3, sqrt_num + 1, 2):
        if num % i == 0:
            return False  # Found a factor, not prime

    return True  # No factors found, num is prime

# Function to compute modular inverse using the Extended Euclidean Algorithm
def modinv(a, m):
    b, u, v = m, 1, 0
    # Loop until b becomes zero
    while b:
        t = a // b
        a, b = b, a - t * b
        u, v = v, u - t * v
    u %= m  # Ensure u is within the modulo
    if u < 0:
        u += m  # Adjust if u is negative
    return u  # Return the modular inverse

# Macro definitions for loop iterations
def repeat(start, end):
    while start <= end:
        yield start
        start += 1

# Main function
def main():
    input_lines = sys.stdin.readlines()
    N, K = map(int, input_lines[0].split())
    A = list(map(int, input_lines[1].split()))

    cur = 1  # Initialize current position
    dic = defaultdict(lambda: -1)  # Dictionary to store the first occurrence of each index
    flg = False  # Flag to indicate if we have entered a cycle

    # Process the sequence based on the value of K
    for i in range(1, K + 1):
        # If current index has not been seen before or we are in a cycle
        if dic[cur] < 0 or flg:
            dic[cur] = i  # Record the current index
            cur = A[cur - 1]  # Move to the next index
        # If we have seen this index before and are not in a cycle
        elif not flg:
            tmp = K - (dic[cur] - 1)  # Calculate remaining steps
            tmp %= i - dic[cur]  # Adjust steps based on the cycle length
            i = K - tmp  # Update i to skip to the end of the cycle
            flg = True  # Set the flag indicating we are in a cycle

    # Output the final position after K steps
    print(cur)

if __name__ == "__main__":
    main()
