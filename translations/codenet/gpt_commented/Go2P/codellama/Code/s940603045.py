
import sys
import math
import random

# Direction vectors for 8 possible movements (up, down, left, right, and diagonals)
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# Define an infinite value for comparison
inf = math.inf

# Initialize a new scanner for input
next = Scanner()

# ---------------------------------------------------------
# init function to set up logging and random seed
def init():
    sys.setrecursionlimit(10**6) # Set recursion limit to 1 million
    random.seed(int(sys.stdin.readline().strip())) # Seed the random number generator

# main function where the program execution starts
def main():
    # Read input as a string
    N = next.String()
    b = list(N) # Convert string to list
    n = 0 # Initialize sum of digits

    # Calculate the sum of digits in the input number
    for i in range(len(b)):
        n += int(b[i]) # Convert byte to int and accumulate

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

# Pairs is a slice of Pair structs
class Pairs:
    def __init__(self, pairs):
        self.pairs = pairs

    def Len(self):
        return len(self.pairs)

    def Swap(self, i, j):
        self.pairs[i], self.pairs[j] = self.pairs[j], self.pairs[i]

    def Less(self, i, j):
        return self.pairs[i].b < self.pairs[j].b

# Utility functions for various operations

# Check if a value is within a range
def in(c, a, z):
    return c >= a and c < z

# Check if a value is outside a range
def out(c, a, z):
    return not in(c, a, z)

# Convert boolean to integer (1 for true, 0 for false)
def btoi(b):
    if b:
        return 1
    return 0

# Convert integer to boolean (non-zero to true, zero to false)
def itob(a):
    return a != 0

# Return the maximum value from a list of integers
def max(a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

# Return the minimum value from a list of integers
def min(a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

# Calculate the sum of a slice of integers
def sum(a):
    r = 0
    for i in range(len(a)):
        r += a[i]
    return r

# Calculate the product of a slice of integers
def pro(a):
    r = a[0]
    for i in range(1, len(a)):
        r *= a[i]
    return r

# Fill a slice with a specified value
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
    if a % b != 0:
        return 1
    return 0

# Print a slice of strings with space separation
def printStrings(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

# Print a slice of integers with space separation
def printInts(out):
    for i in range(len(out)):
        print(out[i], end=" ")
    print()

# ---------- buffered scanner -----------------------------------------

# scanner struct for buffered input reading
class Scanner:
    def __init__(self):
        self.r = sys.stdin # Buffered reader
        self.buf = [] # Buffer to hold input
        self.p = 0 # Current position in the buffer

    # Read the next token from the input
    def next(self):
        self.pre() # Ensure the buffer is filled
        start = self.p # Mark the start of the token
        for ; self.p < len(self.buf); self.p += 1:
            if self.buf[self.p] == ' ': # Stop at space
                break
        result = "".join(self.buf[start:self.p]) # Extract the token
        self.p += 1 # Move past the space
        return result

    # Read the entire line from the input
    def Line(self):
        self.pre() # Ensure the buffer is filled
        start = self.p # Mark the start of the line
        self.p = len(self.buf) # Move to the end of the buffer
        return "".join(self.buf[start:]) # Return the line

    # Read the next string from the input
    def String(self):
        return self.next() # Call next to get the next token

    # Read the next integer from the input
    def Int(self):
        v = int("".join(self.next())) # Convert the next token to an integer
        return v # Return the integer

    # Read multiple integers from the input
    def Ints(self, n):
        r = [] # Create a slice to hold the integers
        for i in range(n):
            r.append(self.Int()) # Read each integer
        return r # Return the slice of integers

    # Read the next int64 from the input
    def Int64(self):
        v = int("".join(self.next())) # Convert the next token to int64
        return v # Return the int64

    # Read the next uint64 from the input
    def Uint64(self):
        v = int("".join(self.next())) # Convert the next token to uint64
        return v # Return the uint64

    # Read the next float64 from the input
    def Float64(self):
        v = float("".join(self.next())) # Convert the next token to float64
        return v # Return the float64

    # Pre-read to ensure there is data in the buffer
    def pre(self):
        if self.p >= len(self.buf): # If current position is at the end of the buffer
            self.readLine() # Read a new line
            self.p = 0 # Reset position to the start of the new buffer

    # Read a line from the input and fill the buffer
    def readLine(self):
        self.buf = [] # Reset the buffer
        while True:
            l, p = self.r.readline().split() # Read a line
            self.buf.extend(l) # Append line to buffer
            if not p: # If the line is complete
                break

# Initialize a new scanner instance
next = Scanner()

# ---------------------------------------------------------

# Initialize the scanner and set up logging and random seed
init()

# Call the main function
main()

# 