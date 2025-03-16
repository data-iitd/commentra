# Import necessary libraries
import sys
from math import gcd

# Function to compute the least common multiple of two numbers x and y
def lcm(x, y):
    return x // gcd(x, y) * y

# Function to compute the factorial of a number k modulo 10^9 + 7
def kaijo(k):
    sum = 1
    for i in range(1, k + 1):
        sum *= i
        sum %= 1000000000 + 7
    return sum

# Utility functions to find the maximum and minimum of two numbers
def lmax(s, t):
    return s if s > t else t

def lmin(s, t):
    return s if s < t else t

# Main function
def main():
    # Read two integers n and k
    n, k = map(int, input().split())
    sum = 0

    # Iterate over possible values of b
    for b in range(1, n + 1):
        # Calculate the count and remainder
        cnt = (n + 1) // b
        md = (n + 1) % b

        # Update the sum based on the conditions involving k
        sum += cnt * max((b - k), 0) + max((md - k), 0)

        # Adjust the sum if k is 0
        if k == 0:
            sum -= 1

    # Print the computed sum
    print(sum)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
