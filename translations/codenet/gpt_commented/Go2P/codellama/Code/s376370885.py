// by syu
import sys

# Initialize a new Scanner for reading input from standard input (sys.stdin)
in = Scanner(sys.stdin, 0)

def main():
    # Read two integers n and k from the input
    n, k = in.int(), in.int()
    
    # Check if n is divisible by k
    if n % k == 0:
        # If n is divisible by k, print 0
        print(0)
    else:
        # If n is not divisible by k, print 1
        print(1)

class Scanner:
    def __init__(self, r, max):
        self.scanner = bufio.Scanner(r) # Create a new Scanner
        self.scanner.split = scanWords # Set the split function to scan words
        if max <= 0:
            max = 1048576 # Default buffer size if max is not specified
        self.scanner.buffer_size = max # Set the buffer size for the scanner

    def int(self):
        self.scanner.scan() # Scan the next token
        i, e = strconv.ParseInt(self.scanner.text, 10, 64) # Parse the token as an integer
        if e != None:
            raise e # Panic if there is an error during parsing
        return int(i) # Return the parsed integer

def scanWords(data, atEOF):
    start = 0
    # Skip leading whitespace
    for start < len(data) and isSpace(data[start]):
        start += 1
    # Find the end of the next word
    for i in range(start, len(data)):
        if isSpace(data[i]):
            return i + 1, data[start:i], None # Return the word found
    # If at EOF and there is data left, return the last word
    if atEOF and len(data) > start:
        return len(data), data[start:], None
    return start, None, None # Return the current position if no word is found

def isSpace(b):
    return b == ' ' or b == '\n' or b == '\r' or b == '\t'

def Pln(s):
    print(s) # Print the provided arguments


