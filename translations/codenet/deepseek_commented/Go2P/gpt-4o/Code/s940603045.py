import sys
import math
import random

# Constants
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]
inf = math.inf

# Initialize random seed
random.seed()

# Main function reads a string, calculates digit sum, and checks divisibility
def main():
    N = input().strip()  # Read input string
    n = sum(int(digit) for digit in N)  # Calculate sum of digits
    m = int(N)  # Convert input string to integer
    if m % n == 0:  # Check if the number is divisible by the sum of its digits
        print("Yes")
    else:
        print("No")

# Pair class representing a pair of integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Utility functions
def in_range(c, a, z):
    return a <= c < z

def out_range(c, a, z):
    return not in_range(c, a, z)

def btoi(b):
    return 1 if b else 0

def itob(a):
    return a != 0

def max_value(*args):
    return max(args)

def min_value(*args):
    return min(args)

def sum_list(a):
    return sum(a)

def prod_list(a):
    result = a[0]
    for i in range(1, len(a)):
        result *= a[i]
    return result

def fill(a, n):
    return [n] * len(a)

def minmax(a, b):
    return (min(a, b), max(a, b))

def abs_value(a):
    return abs(a)

def ceil_div(a, b):
    return (a + b - 1) // b

def print_strings(out):
    print(" ".join(out))

def print_ints(out):
    print(" ".join(map(str, out)))

# Entry point
if __name__ == "__main__":
    main()

# <END-OF-CODE>
