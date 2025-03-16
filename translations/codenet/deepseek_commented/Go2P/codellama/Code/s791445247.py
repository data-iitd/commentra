// by syu
import sys

# Initialize a Scanner instance to read from standard input.
in = Scanner(sys.stdin, 0)

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
    def __init__(self, r, max):
        self.scanner = bufio.Scanner(r)
        self.scanner.split = scanWords
        if max <= 0:
            max = 1048576
        self.scanner.buffer(max)

    # Read and return an integer from the input.
    def int(self):
        self.scanner.scan()
        i, e = strconv.ParseInt(self.scanner.text(), 10, 64)
        if e != None:
            panic(e)
        return int(i)

# Helper function to check if a byte is a space character.
def isSpace(b):
    return b == ' ' or b == '\n' or b == '\r' or b == '\t'

# Custom split function for bufio.Scanner to split by words.
def scanWords(data, atEOF):
    start = 0
    for start < len(data) and isSpace(data[start]):
        start++
    for i in range(start, len(data)):
        if isSpace(data[i]):
            return i + 1, data[start:i], None
    if atEOF and len(data) > start:
        return len(data), data[start:], None
    return start, None, None

# Helper function to print a line of output.
def Pln(s):
    print(s)


