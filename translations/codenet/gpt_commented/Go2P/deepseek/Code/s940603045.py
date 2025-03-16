import sys
import math
import random
import re
from io import StringIO

# Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# Define an infinite value for comparison
inf = sys.maxsize

# Initialize a new scanner for input
class Scanner:
    def __init__(self, input_stream):
        self.r = input_stream
        self.buf = []
        self.p = 0

    def next(self):
        self._pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p] != ' ':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def line(self):
        self._pre()
        start = self.p
        while self.p < len(self.buf):
            self.p += 1
        return ''.join(self.buf[start:])

    def string(self):
        return self.next()

    def int(self):
        return int(self.next())

    def ints(self, n):
        return [self.int() for _ in range(n)]

    def int64(self):
        return int(self.next())

    def uint64(self):
        return int(self.next())

    def float64(self):
        return float(self.next())

    def _pre(self):
        if self.p >= len(self.buf):
            self.buf = list(self.r.readline().strip())
            self.p = 0

# Create a new scanner instance
next = Scanner(sys.stdin)

# ---------------------------------------------------------
# init function to set up logging and random seed
def init():
    import logging
    logging.basicConfig(level=logging.DEBUG, format='%(filename)s:%(lineno)d: %(message)s')
    random.seed(time.time())

# main function where the program execution starts
def main():
    # Read input as a string
    N = next.string()
    b = list(N)  # Convert string to byte slice
    n = 0  # Initialize sum of digits

    # Calculate the sum of digits in the input number
    for i in range(len(b)):
        n += int(b[i])  # Convert byte to int and accumulate

    # Convert the string input to an integer
    m = int(N)
    # Check if the number is divisible by the sum of its digits
    if m % n == 0:
        print("Yes")  # Print "Yes" if divisible
    else:
        print("No")  # Print "No" if not divisible

# ---------------------------------------------------------

# Pair struct to hold a pair of integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs is a list of Pair structs
class Pairs(list):
    def __init__(self, *args):
        super().__init__(*args)

    def len(self):
        return len(self)

    def swap(self, i, j):
        self[i], self[j] = self[j], self[i]

    def less(self, i, j):
        return self[i].b < self[j].b

# Utility functions for various operations

# Check if a value is within a range
def in_range(c, a, z):
    return a <= c < z

# Check if a value is outside a range
def out_of_range(c, a, z):
    return not in_range(c, a, z)

# Convert boolean to integer (1 for true, 0 for false)
def btoi(b):
    return 1 if b else 0

# Convert integer to boolean (non-zero to true, zero to false)
def itob(a):
    return a != 0

# Return the maximum value from a list of integers
def max_val(*args):
    return max(args)

# Return the minimum value from a list of integers
def min_val(*args):
    return min(args)

# Calculate the sum of a list of integers
def sum_list(a):
    return sum(a)

# Calculate the product of a list of integers
def pro_list(a):
    result = a[0]
    for i in range(1, len(a)):
        result *= a[i]
    return result

# Fill a list with a specified value
def fill_list(a, n):
    return [n for _ in range(len(a))]

# Return the minimum and maximum of two integers
def min_max(a, b):
    return (a, b) if a < b else (b, a)

# Return the absolute value of an integer
def abs_val(a):
    return abs(a)

# Calculate the ceiling of a division of two integers
def ceil_div(a, b):
    return (a + b - 1) // b

# Print a list of strings with space separation
def print_strings(out):
    print(' '.join(out))

# Print a list of integers with space separation
def print_ints(out):
    print(' '.join(map(str, out)))

# ---------- buffered scanner -----------------------------------------

# Create a new scanner instance
def new_scanner(input_stream):
    return Scanner(input_stream)

init()
main()
