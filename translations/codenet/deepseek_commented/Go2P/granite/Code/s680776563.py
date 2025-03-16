

import sys

# Main function: Entry point of the program.
# Initializes a FastScanner, reads three integers A, B, and C,
# and checks if the difference between consecutive integers is the same.
# If the difference is the same, it prints "YES"; otherwise, it prints "NO".
def main():
    fsc = FastScanner()
    A, B, C = fsc.next_int(), fsc.next_int(), fsc.next_int()
    if B - A == C - B:
        print("YES")
    else:
        print("NO")

# FastScanner class: Efficiently reads input.
class FastScanner:
    def __init__(self):
        self.rdr = sys.stdin
        self.buf = []
        self.p = 0

    def next(self):
        while self.p >= len(self.buf):
            self.read_line()
            self.p = 0
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def next_line(self):
        while self.p >= len(self.buf):
            self.read_line()
            self.p = 0
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def next_int(self):
        return int(self.next())

    def next_int64(self):
        return int(self.next())

    def read_line(self):
        self.buf = self.rdr.readline().strip().split()

# Utility functions: Max, Min, Gcd, Abs.
def int_max(a, b):
    if a < b:
        return b
    return a

def int64_max(a, b):
    if a < b:
        return b
    return a

def float64_max(a, b):
    if a < b:
        return b
    return a

def int_min(a, b):
    if a > b:
        return b
    return a

def int64_min(a, b):
    if a > b:
        return b
    return a

def float64_min(a, b):
    if a > b:
        return b
    return a

def int_gcd(a, b):
    if a < b:
        b, a = a, b
    if b == 0:
        return a
    return int_gcd(b, a % b)

def int64_gcd(a, b):
    if a < b:
        b, a = a, b
    if b == 0:
        return a
    return int64_gcd(b, a % b)

def int_abs(a):
    if a < 0:
        a *= -1
    return a

def int64_abs(a):
    if a < 0:
        a *= -1
    return a

# End of code

