import sys
import math

class IO:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def scan_int(self):
        value = int(self.data[self.index])
        self.index += 1
        return value

    def scan_float(self):
        value = float(self.data[self.index])
        self.index += 1
        return value

    def scan_floats(self, n):
        values = [float(self.data[i]) for i in range(self.index, self.index + n)]
        self.index += n
        return values

def abs_diff_float(n1, n2):
    return abs(n1 - n2)

def main():
    io = IO()
    n = io.scan_int()
    t = io.scan_float()
    a = io.scan_float()
    heights = io.scan_floats(n)

    min_diff = abs_diff_float(t - heights[0] * 0.006, a)
    min_idx = 0
    for i in range(1, n):
        diff = abs_diff_float(t - heights[i] * 0.006, a)
        if diff < min_diff:
            min_diff = diff
            min_idx = i

    print(min_idx + 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
