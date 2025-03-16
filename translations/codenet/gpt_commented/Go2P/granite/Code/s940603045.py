
import bufio
import math
import os
import random
import sys
import time

# Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [1, 1, 0, -1, -1, -1, 0, 1]

# Initialize a new scanner for input
next = Scanner()

# ---------------------------------------------------------
# init function to set up logging and random seed
def init():
    log.basicConfig(format='%(levelname)s: %(message)s', level=log.DEBUG) # Set log format and level
    random.seed(time.time()) # Seed the random number generator

# main function where the program execution starts
def main():
    # Read input as a string
    N = next.string()
    b = list(N) # Convert string to list of characters
    n = 0 # Initialize sum of digits

    # Calculate the sum of digits in the input number
    for i in range(len(b)):
        n += int(b[i]) # Convert character to int and accumulate

    # Convert the string input to an integer
    m = int(N)
    # Check if the number is divisible by the sum of its digits
    if m % n == 0:
        print("Yes") # Print "Yes" if divisible
    else:
        print("No") # Print "No" if not divisible

# ---------------------------------------------------------

# Pair struct to hold a pair of integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs is a list of Pair objects
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
    return c >= a and c < z

# Check if a value is outside a range
def out_range(c, a, z):
    return not in_range(c, a, z)

# Convert boolean to integer (1 for true, 0 for false)
def b_to_i(b):
    if b:
        return 1
    return 0

# Convert integer to boolean (non-zero to true, zero to false)
def i_to_b(a):
    return a!= 0

# Return the maximum value from a list of integers
def max(*a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

# Return the minimum value from a list of integers
def min(*a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

# Calculate the sum of a list of integers
def sum(a):
    r = 0
    for i in range(len(a)):
        r += a[i]
    return r

# Calculate the product of a list of integers
def pro(a):
    r = 1
    for i in range(len(a)):
        r *= a[i]
    return r

# Fill a list with a specified value
def fill(a, n):
    for i in range(len(a)):
        a[i] = n
    return a

# Return the minimum and maximum of two integers
def minmax(a, b):
    if a > b:
        return b, a
    return a, b

# Return the absolute value of an integer
def abs(a):
    if a < 0:
        return -a
    return a

# Calculate the ceiling of a division of two integers
def ceil(a, b):
    if a % b!= 0:
        return 1
    return 0

# Print a list of strings with space separation
def print_strings(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

# Print a list of integers with space separation
def print_ints(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

# ---------- buffered scanner -----------------------------------------

# Scanner class for buffered input reading
class Scanner:
    def __init__(self):
        self.r = bufio.BufferedReader(bufio. InputStreamReader(sys.stdin), 10000) # Initialize with a buffer size
        self.buf = [] # Buffer to hold input
        self.p = 0 # Current position in the buffer

    def next(self):
        self.pre() # Ensure the buffer is filled
        start = self.p # Mark the start of the token
        while self.p < len(self.buf) and self.buf[self.p]!= " ": # Stop at space
            self.p += 1
        result = "".join(self.buf[start:self.p]) # Extract the token
        self.p += 1 # Move past the space
        return result

    def line(self):
        self.pre() # Ensure the buffer is filled
        start = self.p # Mark the start of the line
        self.p = len(self.buf) # Move to the end of the buffer
        return "".join(self.buf[start:]) # Return the line

    def string(self):
        return self.next() # Call next to get the next token

    def int(self):
        v = int(self.next()) # Convert the next token to an integer
        return v # Return the integer

    def ints(self, n):
        r = [] # Create a list to hold the integers
        for i in range(n):
            r.append(self.int()) # Read each integer
        return r # Return the list of integers

    def int64(self):
        v = int(self.next()) # Convert the next token to int64
        return v # Return the int64

    def uint64(self):
        v = int(self.next()) # Convert the next token to uint64
        return v # Return the uint64

    def float64(self):
        v = float(self.next()) # Convert the next token to float64
        return v # Return the float64

    def pre(self):
        if self.p >= len(self.buf): # If current position is at the end of the buffer
            self.read_line() # Read a new line
            self.p = 0 # Reset position to the start of the new buffer

    def read_line(self):
        self.buf = [] # Reset the buffer
        while True:
            l = self.r.readline() # Read a line
            if not l: # If the line is empty
                break
            self.buf.extend(l) # Append line to buffer
        self.buf.append("\n") # Add newline character to the buffer

# Initialize the scanner
next = Scanner()

# Call the main function to start the program
main()

# Print the end-of-code marker
print("