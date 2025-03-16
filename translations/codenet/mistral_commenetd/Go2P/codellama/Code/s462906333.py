
# Importing necessary packages
import sys

# Constants and variables declaration
inf = 1e14

# Function to read input from standard input using buffered scanner
class scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = self.r.readline().strip().split()

    def next(self):
        self.pre()
        start = self.p
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                break
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def Line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def Int(self):
        return int(self.next())

    def Int64(self):
        return int(self.next())

# Main function
def main():
    # Setting up logging
    # log.SetFlags(log.Lshortfile)

    # Creating a new scanner object
    next = scanner()

    # Reading input
    n = next.Int()
    x = next.Int()

    # Initializing arrays
    a = [0] * n
    v = [0] * n
    for i in range(n):
        a[i] = next.Int()
    v = a[:]

    # Initializing answer variable
    ans = inf

    # Iterating through all possible subarrays
    for k in range(n):
        # Initializing variable to store sum of subarray elements
        kans = 0

        # Iterating through all elements of the subarray
        for i in range(n):
            # Checking if current index is out of bounds for subarray
            if i-k < 0:
                # Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n+i-k])
            else:
                # Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i-k])

            # Adding current element to the sum of subarray
            kans += v[i]

        # Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans+k*x)

    # Printing the answer
    print(ans)

# Helper functions
def min(a, b):
    if a < b:
        return a
    return b

# -------------------------------
# Function to check if a given number is inside a given range
def in(c, a, z):
    return c >= a and c < z

# Function to convert boolean value to integer
def btoi(b):
    if b:
        return 1
    return 0

# Function to convert integer value to boolean
def itob(a):
    if a == 0:
        return False
    return True

# END-OF-CODE
