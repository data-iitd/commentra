

import sys

# Initialize a new scanner
def newScanner():
    rdr = bufio.NewReaderSize(sys.stdin, 1000)
    return scanner(rdr)

# Scanner structure definition
class scanner:
    def __init__(self, r):
        self.r = r
        self.buf = []
        self.p = 0

    # Next function to read the next token as a string
    def next(self):
        self.pre()
        start = self.p
        while self.p < len(self.buf):
            if self.buf[self.p] =='':
                break
            self.p += 1
        result = ''.join(self.buf[start:self.p])
        self.p += 1
        return result

    # NextLine function to read the next line as a string
    def nextLine(self):
        self.pre()
        start = self.p
        self.p = len(self.buf)
        return ''.join(self.buf[start:])

    # NextInt function to read the next integer from the standard input
    def nextInt(self):
        v = int(self.next())
        return v

    # NextIntArray function to read an array of integers from the standard input
    def nextIntArray(self):
        self.pre()
        start = self.p
        result = []
        while self.p < len(self.buf)+1:
            if self.p == len(self.buf) or self.buf[self.p] =='':
                v = int(self.buf[start:self.p])
                result.append(v)
                start = self.p + 1
            self.p += 1
        return result

    # Pre function to prepare the scanner for reading the next token
    def pre(self):
        if self.p >= len(self.buf):
            self.readLine()
            self.p = 0

    # ReadLine function to read a line from the standard input
    def readLine(self):
        self.buf = []
        while True:
            l = self.r.readline()
            if not l:
                break
            self.buf.extend(l)

# Initialize a new scanner
sc = newScanner()

# Read the first string from the standard input
S = sc.next()

# Check if the string starts with "YAKI"
if S.startswith("YAKI"):
    print("Yes") # Print "Yes" if the condition is true
else:
    print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
    # Determine the minimum of two integers
    if a > b:
        return b
    return a

# Maximum function
def max(a, b):
    # Determine the maximum of two integers
    if a > b:
        return a
    return b

# 