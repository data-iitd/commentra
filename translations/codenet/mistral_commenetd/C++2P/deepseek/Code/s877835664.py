import sys
from collections import defaultdict

# Include necessary libraries for the program

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

# Define helper functions for gcd and lcm

def get_prime_factors(n):
    res = defaultdict(int)
    # Initialize an empty dictionary to store prime factors and their exponents

    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            res[i] += 1
            # If the number is divisible by 'i', add it to the dictionary with its exponent incremented

            n //= i
    if n != 1:
        res[n] = 1
    # If the number is not 1, add it to the dictionary with exponent 1

    return res

# Function to get prime factors of a number

def is_prime_number(num):
    if num <= 2:
        return True
    elif num % 2 == 0:
        return False

    sqrt_num = int(num**0.5)
    # Check if the number is prime by checking divisibility up to its square root

    for i in range(3, sqrt_num + 1, 2):
        if num % i == 0:
            return False

    return True

# Function to check if a number is prime

def modinv(a, m):
    b, u, v = m, 1, 0
    # Extended Euclidean Algorithm to find modular multiplicative inverse

    while b:
        t = a // b
        a, b = b, a - t * b
        u, v = v, u - t * v
    u %= m
    # Make the result positive and less than 'm'

    if u < 0:
        u += m
    return u

# Function to find modular multiplicative inverse

# Define macros for for loops

def main():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    # Read input for 'N' and 'K'

    A = [0] + list(map(int, input().split()))
    # Initialize an array 'A' of size 'N+1' and read input for each element of the array 'A'

    cur = 1
    # Initialize a variable 'cur' to keep track of the current position in the array

    dic = [-1] * (N + 1)
    # Initialize a list 'dic' of size 'N+1' to store the distance from the start for each position

    flg = False
    # Initialize a boolean variable 'flg' to check if we need to reverse the direction of traversal

    for i in range(1, K + 1):
        if dic[cur] == -1 or flg:
            dic[cur] = i
            # If the distance from the start for the current position is not yet determined or we need to reverse the direction, update the distance

            cur = A[cur]
            # Move to the next position
        elif not flg:
            tmp = (K - (dic[cur] - 1)) % (i - dic[cur])
            # Calculate the number of steps we need to take to reach the position 'i' from the current position

            cur = A[cur]
            # Move to the next position
            for _ in range(tmp):
                cur = A[cur]
            # Move 'tmp' steps to reach the desired position

            flg = True
            # Set 'flg' to True to indicate that we have found the position

    print(cur)
    # Print the final answer, which is the position of the last visited node

# Main function to solve the problem

