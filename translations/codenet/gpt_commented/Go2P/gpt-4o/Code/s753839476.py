import sys
import math

class IO:
    def __init__(self):
        self.input = sys.stdin.read
        self.output = sys.stdout.write

    def scan_int(self):
        return int(self.scan_string())

    def scan_float(self):
        return float(self.scan_string())

    def scan_string(self):
        return self.input().strip()

    def scan_floats(self, n):
        return list(map(float, self.input().strip().split()))[:n]

def abs_diff_float(n1, n2):
    return abs(n1 - n2)

def main():
    io = IO()

    # Read the number of heights, target temperature, and actual temperature
    n = io.scan_int()
    t = io.scan_float()
    a = io.scan_float()
    
    # Read the heights as a list of float
    heights = io.scan_floats(n)

    # Initialize minimum difference and index for tracking the closest height
    min_diff = abs_diff_float(t - heights[0] * 0.006, a)
    min_idx = 0

    # Iterate through the heights to find the one with the minimum temperature difference
    for i in range(1, n):
        diff = abs_diff_float(t - heights[i] * 0.006, a)
        if diff < min_diff:
            min_diff = diff
            min_idx = i  # Update the index of the closest height

    # Output the 1-based index of the closest height
    io.output(f"{min_idx + 1}\n")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
