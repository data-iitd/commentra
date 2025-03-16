
import math
import os
import sys

# Initialize IO object and handle resources
def main():
    io, flash = new_io()
    defer flash()

    # Read input values
    n, t, a = io.scan_int(), io.scan_float(), io.scan_float()

    # Initialize variables for heights and minimum difference
    heights = io.scan_float_array(n)
    min_diff = abs_diff_float(t - heights[0] * 0.006, a)
    min_idx = 0

    # Iterate through the remaining heights and find the minimum difference
    for i, h in enumerate(heights[1:]):
        # Calculate the difference between the target and the height
        diff = abs_diff_float(t - h * 0.006, a)

        # Update minimum difference and index if the current difference is smaller
        if diff < min_diff:
            min_diff = diff
            min_idx = i + 1

    # Print the result
    print(min_idx + 1)

# Calculate absolute difference between two float64 numbers
def abs_diff_float(n1, n2):
    return abs(n1 - n2)

# Initialize IO object with scanner and writer
class IO:
    def __init__(self):
        self.scanner = new_scanner()
        self.writer = new_writer()

# Create new IO object
def new_io():
    io = IO()
    return io, io.writer.flush

# Initialize scanner with standard input
def new_scanner():
    s = sys.stdin
    return s

# Initialize writer with standard output
def new_writer():
    w = sys.stdout
    return w

# Read a single byte from the scanner
def scan_bytes(self):
    if not self.scanner.readline():
        panic("scan string failed")
    return self.scanner.readline()

# Read a single string from the scanner
def scan_string(self):
    if not self.scanner.readline():
        panic("scan string failed")
    return self.scanner.readline().strip()

# Read multiple strings from the scanner
def scan_strings(self, n):
    strs = []
    for i in range(n):
        strs.append(self.scan_string())
    return strs

# Read a 2D array of strings from the scanner
def scan_2d_strings(self, y, x):
    strings = []
    for i in range(y):
        strings.append(self.scan_strings(x))
    return strings

# Read a 2D array of graphs from the scanner
def scan_2d_graph(self, y):
    strs = []
    for i in range(y):
        strs.append(self.scan_string().split())
    return strs

# Read a single integer from the scanner
def scan_int(self):
    return int(self.scan_int64())

# Read two integers from the scanner
def scan_int2(self):
    return int(self.scan_int64()), int(self.scan_int64())

# Read three integers from the scanner
def scan_int3(self):
    return int(self.scan_int64()), int(self.scan_int64()), int(self.scan_int64())

# Read four integers from the scanner
def scan_int4(self):
    return int(self.scan_int64()), int(self.scan_int64()), int(self.scan_int64()), int(self.scan_int64())

# Read a slice of integers from the scanner
def scan_ints(self, n):
    ints = []
    for i in range(n):
        ints.append(self.scan_int())
    return ints

# Read a 2D slice of integers from the scanner
def scan_2d_ints(self, y, x):
    ints = []
    for i in range(y):
        ints.append(self.scan_ints(x))
    return ints

# Read a single int64 from the scanner
def scan_int64(self):
    i, err = strconv.ParseInt(self.scan_string(), 10, 64)
    if err != nil:
        panic(err)
    return i

# Read a single float64 from the scanner
def scan_float64(self):
    i, _ = strconv.ParseFloat(self.scan_string(), 64)
    return i

# Read a slice of float64 from the scanner
def scan_float64s(self, n):
    floats = []
    for i in range(n):
        floats.append(self.scan_float64())
    return floats

# Write a single line to the writer
def print_ln(self, a):
    self.writer.write(a)
    self.writer.write("\n")

# Flush the writer buffer
def flush(self):
    self.writer.flush()

# Function to handle resource deallocation
def flash(self):
    self.scanner.close()
    self.writer.flush()
    os.stdin.close()
    os.stdout.close()

# Function to calculate the absolute difference between two float64 numbers
def abs_diff_float(n1, n2):
    return math.fabs(n1 - n2)



