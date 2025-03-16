import sys
import random

# Initialize random seed
random.seed()

def main():
    N = input().strip()
    n = sum(int(digit) for digit in N)
    m = int(N)
    
    if m % n == 0:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# Utility functions
def in_range(c, a, z):
    return a <= c < z

def out_of_range(c, a, z):
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

def product_list(a):
    result = a[0]
    for i in range(1, len(a)):
        result *= a[i]
    return result

def fill_list(a, n):
    return [n] * len(a)

def minmax(a, b):
    return (b, a) if a > b else (a, b)

def abs_value(a):
    return -a if a < 0 else a

def ceil_div(a, b):
    return (a + b - 1) // b

def print_strings(out):
    print(" ".join(out))

def print_ints(out):
    print(" ".join(map(str, out)))

# <END-OF-CODE>
