
# Import packages for reading input
import sys
import math
import random

# Initialize the scanner
scanner = sys.stdin

# Constants and variables declaration
inf = math.inf # Constants for maximum signed integer value

# Global variables declaration
next = scanner # Global scanner for reading input

# ---------------------------------------------------------

# init function initializes the program
def init():
    # Set log flags for short file names
    log.basicConfig(filename='log.txt', level=log.DEBUG, format='%(asctime)s %(message)s')
    # Seed random number generator with current time
    random.seed(time.time())

# main function is the entry point of the program
def main():
    # Read input N as a string
    N = next.readline().strip()
    # Convert N to an integer
    b = list(map(int, N))
    n = 0
    # Iterate through each digit in the number N
    for i in range(len(b)):
        n += b[i] # Convert each digit to an integer and add to the sum
    # Read input m as an integer
    m = int(N)
    # Check if m is divisible by n
    if m % n == 0:
        print("Yes") # Print "Yes" if m is divisible by n
    else:
        print("No") # Print "No" if m is not divisible by n

# ---------------------------------------------------------

# Pair type definition for storing two integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs type definition for storing a slice of Pair
class Pairs:
    def __init__(self, pairs):
        self.pairs = pairs

    def __len__(self):
        return len(self.pairs)

    def __getitem__(self, i):
        return self.pairs[i]

    def __setitem__(self, i, v):
        self.pairs[i] = v

    def __delitem__(self, i):
        del self.pairs[i]

    def __iter__(self):
        return iter(self.pairs)

    def __reversed__(self):
        return reversed(self.pairs)

    def __contains__(self, v):
        return v in self.pairs

    def __add__(self, other):
        return Pairs(self.pairs + other.pairs)

    def __iadd__(self, other):
        self.pairs += other.pairs
        return self

    def __mul__(self, other):
        return Pairs(self.pairs * other.pairs)

    def __imul__(self, other):
        self.pairs *= other.pairs
        return self

# Implement Len, Swap, and Less methods for sorting Pairs based on the second element
def len(pairs):
    return len(pairs.pairs)

def swap(pairs, i, j):
    pairs.pairs[i], pairs.pairs[j] = pairs.pairs[j], pairs.pairs[i]

def less(pairs, i, j):
    return pairs.pairs[i].b < pairs.pairs[j].b # Sort based on the second element

# ------int methods-------------------------
def in(c, a, z):
    return c >= a and c < z # Check if c is within the range [a, z)

def out(c, a, z):
    return not in(c, a, z) # Check if c is outside the range [a, z)

def btoi(b):
    if b:
        return 1 # Convert boolean to integer: 1 for true, 0 for false
    return 0

def itob(a):
    return a != 0 # Convert integer to boolean: true for non-zero, false for zero

def max(a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i] # Find the maximum integer among the given integers
    return r

def min(a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i] # Find the minimum integer among the given integers
    return r

def sum(a):
    r = 0
    for i in range(len(a)):
        r += a[i] # Calculate the sum of all integers in the given slice
    return r

def pro(a):
    r = a[0]
    for i in range(1, len(a)):
        r *= a[i] # Calculate the product of all integers in the given slice
    return r

def fill(a, n):
    for i in range(len(a)):
        a[i] = n # Fill the given slice with the given integer value
    return a

def minmax(a, b):
    if a > b:
        return b, a # Return the minimum and maximum integers among the given integers
    return a, b

def abs(a):
    if a < 0:
        return -a # Calculate the absolute value of an integer
    return a

# ---------- buffered scanner -----------------------------------------
class scanner:
    def __init__(self):
        # Initialize a new bufio.Reader with a buffer size of 10000
        self.r = bufio.Reader(sys.stdin, 10000)
        self.buf = [] # Buffer for storing the input line
        self.p = 0 # Position in the buffer

    def next(self):
        self.pre()
        start = self.p
        for i in range(self.p, len(self.buf)):
            if self.buf[i] == ' ':
                break # Find the position of the next whitespace character
        result = ''.join(self.buf[start:i]) # Extract the substring from the buffer
        self.p = i + 1 # Increment the position in the buffer
        return result

    def Line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        result = ''.join(self.buf[start:]) # Extract the rest of the line as a string
        return result

    def String(self):
        return self.next() # Call next() method to read the next token as a string

    def Int(self):
        v = int(''.join(self.next())) # Convert the next token to an integer
        return v

    def Ints(self, n):
        r = [] # Initialize an empty slice of integers with the given size
        for i in range(n):
            r.append(self.Int()) # Read and store n integers in the slice
        return r

    def Int64(self):
        v = int(''.join(self.next())) # Convert the next token to an integer
        return v

    def Uint64(self):
        v = int(''.join(self.next())) # Convert the next token to an integer
        return v

    def Float64(self):
        v = float(''.join(self.next())) # Convert the next token to a float
        return v

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine() # Read a new line if the buffer is empty
            self.p = 0

    def readLine(self):
        self.buf = [] # Clear the buffer
        while True:
            l, p, err = self.r.readLine()
            if err:
                log.Fatal(err) # Log an error and exit the program if an error occurs during reading
            self.buf.extend(l) # Append the read line to the buffer
            if not p:
                break # Exit the loop if the end of the input is reached

# END-OF-CODE
