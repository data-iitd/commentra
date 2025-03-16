
# by syu
import sys

# Define a custom scanner class that wraps bufio.Scanner
class Scanner:
    def __init__(self, r, max=1048576):
        self.s = bufio.Scanner(r)
        self.s.buffer = bytearray(max)
        self.s.split(self.split_words)

    # Parse an integer from the current scanner data
    def int(self):
        self.s.scan()
        return int(self.s.token())

    # Split input data into tokens using scanWords function
    def split_words(self, data, at_eof):
        start = 0
        while start < len(data) and data[start] in'\n\r\t':
            start += 1
        for i in range(start, len(data)):
            if data[i] in'\n\r\t':
                return i + 1, data[start:i]
        if at_eof and len(data) > start:
            return len(data), data[start:]
        return start, None

    # Print a line to the console with the given arguments
    def pln(self, *s):
        print(*s)

# Initialize a new Scanner instance with the given file object
in = Scanner(sys.stdin)

# Read two integers n and k from standard input
n, k = in.int(), in.int()

# Check if n is divisible by k
if n % k == 0:
    # If n is divisible by k, print 0 to the console
    in.pln(0)
else:
    # If n is not divisible by k, print 1 to the console
    in.pln(1)

