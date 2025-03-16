
import bufio
import math
import os
import sys

def main():
    # Initialize input/output handling
    io, flash = NewIO()
    defer flash() # Ensure the writer is flushed before exiting

    # Read the number of heights, target temperature, and actual temperature
    n, t, a = io.ScanInt(), io.ScanFloat64(), io.ScanFloat64()
    # Read the heights as a list of float64
    heights = io.ScanFloat64s(n)

    # Initialize minimum difference and index for tracking the closest height
    min_diff = abs(t - heights[0] * 0.006 - a)
    min_idx = 0

    # Iterate through the heights to find the one with the minimum temperature difference
    for i, h in enumerate(heights[1:], 1):
        diff = abs(t - h * 0.006 - a)
        if diff < min_diff:
            min_diff = diff
            min_idx = i

    # Output the 1-based index of the closest height
    print(min_idx + 1)

def AbsDiffFloat64(n1, n2):
    return math.fabs(n1 - n2)

class IO:
    def __init__(self):
        self.scanner = bufio.Scanner(sys.stdin)
        self.writer = bufio.Writer(sys.stdout)

    def ScanBytes(self):
        if not self.scanner.scan():
            raise Exception("scan string failed") # Raise an exception if scanning fails
        return self.scanner.bytes() # Return the scanned bytes

    def ScanString(self):
        if not self.scanner.scan():
            raise Exception("scan string failed") # Raise an exception if scanning fails
        return self.scanner.text() # Return the scanned string

    def ScanStrings(self, n):
        strs = [self.ScanString() for _ in range(n)] # Scan each string
        return strs # Return the list of strings

    def Scan2DStrings(self, y, x):
        strings = [self.ScanStrings(x) for _ in range(y)] # Scan each row of strings
        return strings # Return the 2D list of strings

    def Scan2DGraph(self, y):
        strs = [list(s) for s in self.ScanStrings(y)] # Split each line into characters
        return strs # Return the 2D list of characters

    def ScanInt(self):
        return int(self.ScanInt64()) # Convert the scanned int64 to int

    def ScanInt2(self):
        return int(self.ScanInt64()), int(self.ScanInt64()) # Return two integers

    def ScanInt3(self):
        return int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()) # Return three integers

    def ScanInt4(self):
        return int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()), int(self.ScanInt64()) # Return four integers

    def ScanInts(self, n):
        ints = [self.ScanInt() for _ in range(n)] # Scan each integer
        return ints # Return the list of integers

    def Scan2DInts(self, y, x):
        ints = [self.ScanInts(x) for _ in range(y)] # Scan each row of integers
        return ints # Return the 2D list of integers

    def ScanInt64(self):
        i = int(self.ScanString()) # Parse the scanned string to int64
        return i # Return the int64 value

    def ScanFloat64(self):
        i = float(self.ScanString()) # Parse the scanned string to float64
        return i # Return the float64 value

    def ScanFloat64s(self, n):
        floats = [self.ScanFloat64() for _ in range(n)] # Scan each float64
        return floats # Return the list of float64

    def Println(self, *a):
        print(*a, file=self.writer) # Print the provided arguments to the writer

def NewIO():
    return IO(), lambda: None # Return a new IO instance and a function that does nothing

if __name__ == "__main__":
    main()

