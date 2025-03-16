
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
    # Initializes a new FastScanner with a buffered reader.
    def __init__(self):
        self.r = open(0)
        self.buf = ""
        self.p = 0

    # Reads the next token from the input.
    def next(self):
        self.pre()
        start = self.p
        for self.p in range(self.p, len(self.buf)):
            if self.buf[self.p] == ' ':
                break
        result = self.buf[start:self.p]
        self.p += 1
        return result

    # Reads the next line from the input.
    def next_line(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    # Reads the next integer from the input.
    def next_int(self):
        return int(self.next())

    # Reads the next 64-bit integer from the input.
    def next_int64(self):
        return int(self.next())

    # pre: Ensures that the buffer has data to read.
    def pre(self):
        if self.p >= len(self.buf):
            self.read_line()
            self.p = 0

    # read_line: Reads the entire line from the input and stores it in the buffer.
    def read_line(self):
        self.buf = ""
        while True:
            l, p, e = self.r.readline()
            if e != None:
                raise e
            self.buf += l
            if not p:
                break

# Utility functions for various operations.
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
    return int_gcd(b, a%b)

def int64_gcd(a, b):
    if a < b:
        b, a = a, b
    if b == 0:
        return a
    return int64_gcd(b, a%b)

def int_abs(a):
    if a < 0:
        a *= -1
    return a

def int64_abs(a):
    if a < 0:
        a *= -1
    return a


# 