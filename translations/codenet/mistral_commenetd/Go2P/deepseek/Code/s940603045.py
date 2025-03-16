import sys
import math
import random
import os
import string

# Constants and variables declaration
inf = sys.maxsize  # Constants for maximum signed integer value

dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]  # 8 directions for movement
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# Global variables declaration
next_input = sys.stdin

# init function initializes the program
def init():
    sys.stderr.setflags(sys.stderr.Lshortfile)  # Set log flags for short file names
    random.seed(os.urandom(8))  # Seed random number generator with current time

# main function is the entry point of the program
def main():
    # Read input N as a string
    N = next_input.readline().strip()
    # Convert N to an integer
    n = sum(int(digit) for digit in N)
    # Read input m as an integer
    m = int(N)
    # Check if m is divisible by n
    if m % n == 0:
        print("Yes")  # Print "Yes" if m is divisible by n
    else:
        print("No")  # Print "No" if m is not divisible by n

# ---------------------------------------------------------

# Pair type definition for storing two integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs type definition for storing a list of Pair
class Pairs(list):
    pass

# Implement Len, Swap, and Less methods for sorting Pairs based on the second element
def len(p):
    return len(p)

def swap(p, i, j):
    p[i], p[j] = p[j], p[i]

def less(p, i, j):
    return p[i].b < p[j].b  # Sort based on the second element

# ------int methods-------------------------
def in_range(c, a, z):
    return a <= c < z  # Check if c is within the range [a, z)

def out_of_range(c, a, z):
    return not in_range(c, a, z)  # Check if c is outside the range [a, z)

def bool_to_int(b):
    return 1 if b else 0  # Convert boolean to integer: 1 for true, 0 for false

def int_to_bool(a):
    return a != 0  # Convert integer to boolean: true for non-zero, false for zero

def max_of(a, *args):
    r = a
    for arg in args:
        if r < arg:
            r = arg  # Find the maximum integer among the given integers
    return r

def min_of(a, *args):
    r = a
    for arg in args:
        if r > arg:
            r = arg  # Find the minimum integer among the given integers
    return r

def sum_of(a):
    return sum(a)  # Calculate the sum of all integers in the given list

def product_of(a):
    r = a[0]
    for i in range(1, len(a)):
        r *= a[i]  # Calculate the product of all integers in the given list
    return r

def fill(a, n):
    for i in range(len(a)):
        a[i] = n  # Fill the given list with the given integer value
    return a

def min_max(a, b):
    return (b, a) if a > b else (a, b)  # Return the minimum and maximum integers among the given integers

def abs_value(a):
    return -a if a < 0 else a  # Calculate the absolute value of an integer

# ---------- buffered scanner -----------------------------------------
class Scanner:
    def __init__(self, input_stream):
        self.r = input_stream
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for ; self.p < len(self.buf); self.p++:
            if self.buf[self.p] == ' ':
                break  # Find the position of the next whitespace character
        result = string(self.buf[start:self.p])  # Extract the substring from the buffer
        self.p++  # Increment the position in the buffer
        return result

    def line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        result = string(self.buf[start:])  # Extract the rest of the line as a string
        return result

    def string(self):
        return self.next()  # Call next() method to read the next token as a string

    def int(self):
        v, err = int(self.next()), None  # Convert the next token to an integer
        if err:
            sys.stderr.write(err)  # Log an error and exit the program if the conversion fails
            sys.exit(1)
        return v

    def ints(self, n):
        r = [0] * n  # Initialize an empty list of integers with the given size
        for i in range(n):
            r[i] = self.int()  # Read and store n integers in the list
        return r

    def int64(self):
        v, err = int(self.next()), None
        if err:
            sys.stderr.write(err)
            sys.exit(1)
        return v

    def uint64(self):
        v, err = int(self.next()), None
        if err:
            sys.stderr.write(err)
            sys.exit(1)
        return v

    def float64(self):
        v, err = float(self.next()), None
        if err:
            sys.stderr.write(err)
            sys.exit(1)
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.buf = list(self.r.readline().strip())  # Read a new line if the buffer is empty
            self.p = 0

# Initialize the scanner with the standard input
next_input = Scanner(sys.stdin)

init()
main()
