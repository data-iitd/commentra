
import sys

# Define a custom scanner class to read input efficiently
class SimpleScanner:
    # Define a buffer size for reading input
    BUFFER_SIZE = 10240

    # Constructor to initialize the scanner with a file-like object
    def __init__(self, stream):
        self.stream = stream
        self.buffer = bytearray(self.BUFFER_SIZE)
        self.pos = self.BUFFER_SIZE
        self.eof = False

    # Method to read a single character from the input
    def read(self):
        if self.pos == self.BUFFER_SIZE:
            self.pos = 0
            self.buffer = self.stream.read(self.BUFFER_SIZE)
            if not self.buffer:
                self.eof = True
                return None
        char = self.buffer[self.pos]
        self.pos += 1
        return char

    # Method to check if the end of the input has been reached
    def check_eof(self):
        if self.eof:
            raise NoSuchElementException()

    # Method to read the next character, ensuring EOF is checked
    def next_char(self):
        self.check_eof()
        char = self.read()
        self.check_eof()
        return char

    # Method to read the next token as a String
    def next(self):
        char = self.next_char()
        while char.isspace():
            char = self.next_char()
        buffer = []
        while not self.eof and not char.isspace():
            buffer.append(char)
            char = self.read()
        return ''.join(buffer)

    # Method to read the next integer from the input
    def next_int(self):
        return int(self.next())

    # Method to read the next long value from the input
    def next_long(self):
        return long(self.next())

    # Method to read the next double value from the input
    def next_double(self):
        return float(self.next())

# Create a SimpleScanner instance to read input from the standard input stream
scanner = SimpleScanner(sys.stdin)

# Read integer values for r and d, and a long value for x from the input
r = scanner.next_int()
d = scanner.next_int()
x = scanner.next_long()

# Perform the calculation and output the result 10 times
for i in range(10):
    # Update x according to the formula x = r * x - d
    x = r * x - d
    # Print the updated value of x
    print(x)

# Translate the Java code to Python and end with comment "