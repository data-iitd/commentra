
import sys

# Define a large constant for infinity
inf = 1e14

# ---------------------------------------------------------
def main():
    # Set log flags to show the file name and line number
    log.SetFlags(log.Lshortfile)

    # Initialize a new scanner for input
    next = Scanner()

    # Read the number of elements and the value of x
    n = next.Int()
    x = next.Int()

    # Create a list to hold the input integers
    a = [next.Int() for _ in range(n)]

    # Create a copy of the list a for manipulation
    v = a[:]

    # Initialize the answer to infinity
    ans = inf

    # Iterate over each possible k value
    for k in range(n):
        kans = 0  # Initialize the current answer for this k

        # Calculate the minimum values for the current k
        for i in range(n):
            if i-k < 0:
                # If i-k is out of bounds, use the wrapped index
                v[i] = min(v[i], a[(n+i-k)%n])
            else:
                # Otherwise, use the normal index
                v[i] = min(v[i], a[i-k])
            # Accumulate the current answer
            kans += v[i]

        # Update the overall answer with the minimum found so far
        ans = min(ans, kans+k*x)

    # Print the final answer
    print(ans)

# ---------------------------------------------------------
class Scanner:
    def __init__(self):
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()  # Ensure the buffer is filled
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1  # Move past the space
        return result

    def Line(self):
        self.pre()  # Ensure the buffer is filled
        start = self.p
        self.p = len(self.buf)  # Move to the end of the buffer
        return ''.join(self.buf[start:])

    def Int(self):
        return int(self.next())

    def Int64(self):
        return int(self.next())

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()  # Read a new line into the buffer
            self.p = 0  # Reset the position to the start of the buffer

    def readLine(self):
        self.buf = []  # Clear the buffer
        while True:
            l = sys.stdin.readline()  # Read a line
            if not l:
                break  # Exit if the line is empty
            self.buf.extend(l)  # Append the line to the buffer

# ---------------------------------------------------------

# in checks if c is within the range [a, z)
def in_range(c, a, z):
    return c >= a and c < z

# btoi converts a boolean to an integer (1 for true, 0 for false)
def bool_to_int(b):
    return 1 if b else 0

# itob converts an integer to a boolean (false for 0, true for non-zero)
def int_to_bool(a):
    return a!= 0

# max returns the maximum value from a list of integers
def max_int(*a):
    return max(a)

# min returns the minimum value from a list of integers
def min_int(*a):
    return min(a)

# minmax returns the minimum and maximum of two integers
def minmax_int(a, b):
    return min(a, b), max(a, b)

# abs returns the absolute value of an integer
def abs_int(a):
    return abs(a)

# sum returns the sum of a list of integers
def sum_int(*a):
    return sum(a)

# ---------------------------------------------------------

# 