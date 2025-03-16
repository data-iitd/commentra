
import sys

# Initializes a new Scanner instance to read from standard input.
sc = Scanner()

# Reads three integers H, W, and N from the standard input.
H, W, N = sc.nextInt(), sc.nextInt(), sc.nextInt()

# Determines the maximum of H and W and assigns it to A.
A = max(H, W)

# Calculates the result by dividing N by A and rounding up.
# This is done by adding N-1 to the division result and then performing integer division by A.
print((N + A - 1) // A)

class Scanner:
    def __init__(self):
        self.r = sys.stdin
        self.buf = []
        self.p = 0

    def next(self):
        self.pre()
        start = self.p
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                break
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    def nextInt(self):
        return int(self.next())

    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        for self.p < len(self.buf)+1:
            if self.p == len(self.buf) or self.buf[self.p] == ' ':
                v = int(''.join(self.buf[start:self.p]))
                result.append(v)
                start = self.p + 1
        v = int(''.join(self.buf[start:self.p]))
        result.append(v)
        return result

    def nextMap(self):
        self.pre()
        start = self.p
        mp = {}
        for self.p < len(self.buf):
            if self.buf[self.p] == ' ':
                v = int(''.join(self.buf[start:self.p]))
                mp[v] = True
                start = self.p + 1
        v = int(''.join(self.buf[start:self.p]))
        mp[v] = True
        return mp

    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    def readLine(self):
        self.buf = []
        for line in self.r:
            self.buf.extend(line)
            if not line.endswith(' '):
                break

def max(a, b):
    if a < b:
        return b
    return a

# 