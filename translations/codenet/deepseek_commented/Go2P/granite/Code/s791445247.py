
# by syu

import sys

# Initialize a global Scanner instance to read from standard input.
in = Scanner(sys.stdin)

def main():
    # Read two integers, n and k, from the input.
    n, k = in.int(), in.int()
    
    # Check if n is divisible by k.
    if n % k == 0:
        # If n is divisible by k, print 0.
        print(0)
    else:
        # If n is not divisible by k, print 1.
        print(1)

# Define a custom Scanner type to read input efficiently.
class Scanner:
    def __init__(self, r):
        self.r = r
        self.line = []
        self.i = 0

    def int(self):
        if self.i == len(self.line):
            self.line = self.r.readline().split()
            self.i = 0
        self.i += 1
        return int(self.line[self.i - 1])

# Helper function to check if a character is a space character.
def isSpace(c):
    return c =='' or c == '\n' or c == '\r' or c == '\t'

# Custom split function for Scanner to split by words.
def scanWords(data):
    start = 0
    while start < len(data) and isSpace(data[start]):
        start += 1
    for i in range(start, len(data)):
        if isSpace(data[i]):
            return data[start:i], data[i+1:]
    return data[start:], ""

# Helper function to print a line of output.
def Pln(*s):
    print(*s)

# End of code.
