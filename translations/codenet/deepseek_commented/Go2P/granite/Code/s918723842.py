
import bufio
import os
import sys

# Initializes a new Scanner instance to read from standard input.
def main():
    sc = Scanner()
    
    # Reads three integers H, W, and N from the standard input.
    H, W, N = sc.nextInt(), sc.nextInt(), sc.nextInt()
    
    # Determines the maximum of H and W and assigns it to A.
    A = max(H, W)
    
    # Calculates the result by dividing N by A and rounding up.
    # This is done by adding N-1 to the division result and then performing integer division by A.
    print((N + A - 1) // A)

# Returns the maximum of two integers.
def max(a, b):
    if a < b:
        return b
    return a

# Scanner struct to read input efficiently.
class Scanner:
    def __init__(self):
        self.r = bufio.BufferedReader(sys.stdin, 1000)
        self.buf = ""
        self.p = 0

    # Reads the next token from the input buffer.
    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = self.buf[start:self.p]
        self.p += 1
        return result

    # Reads the next line from the input buffer.
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return self.buf[start:]

    # Reads the next integer from the input buffer.
    def nextInt(self):
        return int(self.next())

    # Reads the next 64-bit integer from the input buffer.
    def nextInt64(self):
        return int(self.next())

    # Reads the next float from the input buffer.
    def nextFloat(self):
        return float(self.next())

    # Reads the next array of integers from the input buffer.
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = [int(x) for x in self.buf[start:self.p].split()]
        self.p += 1
        return result

    # Reads the next array of 64-bit integers from the input buffer.
    def nextInt64Array(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf) and self.buf[self.p]!='':
            self.p += 1
        result = [int(x) for x in self.buf[start:self.p].split()]
        self.p += 1
        return result

    # Reads the next map of integers from the input buffer.
    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                mp[int(self.buf[start:self.p])] = True
                start = self.p + 1
            self.p += 1
        mp[int(self.buf[start:self.p])] = True
        return mp

    # Ensures that the buffer has data before reading.
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # Reads the entire line from the input buffer.
    def readLine(self):
        self.buf = self.r.readline()

# End of code.