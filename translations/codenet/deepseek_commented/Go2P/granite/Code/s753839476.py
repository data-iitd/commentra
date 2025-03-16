
import bufio
import math
import os
import sys

# Main function: Reads input values, calculates the minimum difference, and prints the index.
def main():
    n, t, a = map(int, input().split()) # Read values for n, t, and a.
    heights = list(map(int, input().split())) # Read a list of heights.

    min_diff = abs(t - heights[0] * 0.006 - a) # Calculate the initial minimum difference.
    min_idx = 0 # Initialize the index of the minimum difference.
    for i, h in enumerate(heights[1:], 1): # Iterate through the heights starting from the second element.
        diff = abs(t - h * 0.006 - a) # Calculate the difference for the current height.
        if diff < min_diff: # Update the minimum difference and index if a smaller difference is found.
            min_diff = diff
            min_idx = i

    print(min_idx + 1) # Print the index (plus one for 1-based indexing).

# AbsDiffFloat64 computes the absolute difference between two float64 numbers.
def AbsDiffFloat64(n1, n2):
    return math.fabs(n1 - n2)

# IO struct for input/output operations.
class IO:
    def __init__(self):
        self.scanner = bufio.Scanner(sys.stdin)
        self.writer = bufio.Writer(sys.stdout)

    def scan_bytes(self):
        if not self.scanner.scan():
            raise Exception("scan string failed")
        return self.scanner.bytes()

    def scan_string(self):
        if not self.scanner.scan():
            raise Exception("scan string failed")
        return self.scanner.text()

    def scan_strings(self, n):
        strs = [None] * n
        for i in range(n):
            strs[i] = self.scan_string()
        return strs

    def scan_2d_strings(self, y, x):
        strings = [None] * y
        for i in range(y):
            strings[i] = self.scan_strings(x)
        return strings

    def scan_2d_graph(self, y):
        strs = [None] * y
        for i in range(y):
            strs[i] = list(self.scan_string())
        return strs

    def scan_int(self):
        return int(self.scan_int64())

    def scan_int2(self):
        return int(self.scan_int64()), int(self.scan_int64())

    def scan_int3(self):
        return int(self.scan_int64()), int(self.scan_int64()), int(self.scan_int64())

    def scan_int4(self):
        return int(self.scan_int64()), int(self.scan_int64()), int(self.scan_int64()), int(self.scan_int64())

    def scan_ints(self, n):
        ints = [None] * n
        for i in range(n):
            ints[i] = self.scan_int()
        return ints

    def scan_2d_ints(self, y, x):
        ints = [None] * y
        for i in range(y):
            ints[i] = self.scan_ints(x)
        return ints

    def scan_int64(self):
        i = self.scan_string()
        try:
            return int(i)
        except ValueError:
            raise Exception("scan int64 failed")

    def scan_float64(self):
        i = self.scan_string()
        try:
            return float(i)
        except ValueError:
            raise Exception("scan float64 failed")

    def scan_float64s(self, n):
        floats = [None] * n
        for i in range(n):
            floats[i] = self.scan_float64()
        return floats

    def println(self, *a):
        print(*a, file=self.writer)

# Initialize IO and defer flushing the writer.
io = IO()
sys.stdout.flush = lambda: None
defer io.writer.flush()

# Read input values, calculate the minimum difference, and print the index.
n, t, a = map(int, input().split()) # Read values for n, t, and a.
heights = list(map(int, input().split())) # Read a list of heights.

min_diff = abs(t - heights[0] * 0.006 - a) # Calculate the initial minimum difference.
min_idx = 0 # Initialize the index of the minimum difference.
for i, h in enumerate(heights[1:], 1): # Iterate through the heights starting from the second element.
    diff = abs(t - h * 0.006 - a) # Calculate the difference for the current height.
    if diff < min_diff: # Update the minimum difference and index if a smaller difference is found.
        min_diff = diff
        min_idx = i

print(min_idx + 1) # Print the index (plus one for 1-based indexing).

