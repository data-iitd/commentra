

import bufio
import math
import os
import sys

# Initialize IO object and handle resources
def main():
    io, flash = IO()
    try:
        # Read input values
        n, t, a = io.scan_int(), io.scan_float(), io.scan_float()

        # Initialize variables for heights and minimum difference
        heights = io.scan_floats(n)
        min_diff = abs(t - heights[0] * 0.006 - a)
        min_idx = 0

        # Iterate through the remaining heights and find the minimum difference
        for i, h in enumerate(heights[1:], 1):
            diff = abs(t - h * 0.006 - a)

            # Update minimum difference and index if the current difference is smaller
            if diff < min_diff:
                min_diff = diff
                min_idx = i

        # Print the result
        print(min_idx + 1)
    finally:
        flash()

# Calculate absolute difference between two float numbers
def abs_diff_float(n1, n2):
    return math.fabs(n1 - n2)

# Initialize IO object with scanner and writer
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

    def scan_float(self):
        i = self.scan_string()
        try:
            return float(i)
        except ValueError:
            raise Exception("scan float failed")

    def scan_floats(self, n):
        floats = [None] * n
        for i in range(n):
            floats[i] = self.scan_float()
        return floats

    def println(self, *a):
        print(*a, file=self.writer)

    def flush(self):
        self.writer.flush()

# Function to handle resource deallocation
def flash():
    sys.stdin.close()
    sys.stdout.close()

# Function to calculate the absolute difference between two float numbers
def abs_diff_float(n1, n2):
    return math.fabs(n1 - n2)

# Initialize IO object and handle resources
main()

# Translate the above Python code to Go and end with comment "