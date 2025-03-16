
import bufio
import math
import os
import random
import re
import sys
import time

# Constants and variables declaration
inf = float('inf')
mod = 1000000007
dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [1, 1, 0, -1, -1, -1, 0, 1]

# Global variables declaration
next = None

# ---------------------------------------------------------

def init():
    global next
    next = Scanner(os.Stdin)

def main():
    # Read input N as a string
    N = next.string()
    # Convert N to an integer
    n = 0
    for c in N:
        n += ord(c) - ord('0') # Convert each digit to an integer and add to the sum
    # Read input m as an integer
    m = int(N)
    # Check if m is divisible by n
    if m % n == 0:
        print("Yes") # Print "Yes" if m is divisible by n
    else:
        print("No") # Print "No" if m is not divisible by n

# ---------------------------------------------------------

class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

class Pairs:
    def __init__(self, pairs):
        self.pairs = pairs

    def len(self):
        return len(self.pairs)

    def swap(self, i, j):
        self.pairs[i], self.pairs[j] = self.pairs[j], self.pairs[i]

    def less(self, i, j):
        return self.pairs[i].b < self.pairs[j].b # Sort based on the second element

# ------int methods-------------------------
def in_range(c, a, z):
    return c >= a and c < z # Check if c is within the range [a, z)

def out_of_range(c, a, z):
    return not in_range(c, a, z) # Check if c is outside the range [a, z)

def b_to_i(b):
    return 1 if b else 0 # Convert boolean to integer: 1 for true, 0 for false

def i_to_b(a):
    return a!= 0 # Convert integer to boolean: true for non-zero, false for zero

def max_int(*a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i] # Find the maximum integer among the given integers
    return r

def min_int(*a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i] # Find the minimum integer among the given integers
    return r

def sum_int(a):
    r = 0
    for i in range(len(a)):
        r += a[i] # Calculate the sum of all integers in the given slice
    return r

def pro_int(a):
    r = 1
    for i in range(len(a)):
        r *= a[i] # Calculate the product of all integers in the given slice
    return r

def fill_int(a, n):
    for i in range(len(a)):
        a[i] = n # Fill the given slice with the given integer value
    return a

def minmax_int(a, b):
    if a > b:
        return b, a # Return the minimum and maximum integers among the given integers
    return a, b

def abs_int(a):
    if a < 0:
        return -a # Calculate the absolute value of an integer
    return a

# ---------- buffered scanner -----------------------------------------
class Scanner:
    def __init__(self, r):
        self.r = r
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        result = ''.join(self.buf[start:])
        return result

    def string(self):
        return self.next()

    def int(self):
        v = int(self.next())
        return v

    def ints(self, n):
        r = []
        for i in range(n):
            r.append(self.int())
        return r

    def int64(self):
        v = int(self.next())
        return v

    def uint64(self):
        v = int(self.next())
        return v

    def float64(self):
        v = float(self.next())
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
        if self.p >= len(self.buf):
            raise Exception("No more tokens")

    def readLine(self):
        self.buf = self.r.readline().strip().split()
        self.p = 0

init()
main()
