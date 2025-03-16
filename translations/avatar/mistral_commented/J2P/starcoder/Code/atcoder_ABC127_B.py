
# Importing necessary Python packages for input and output
import sys
import io

# Creating a SimpleScanner class for reading input and a PrintWriter class for writing output
class SimpleScanner:
    # Constructor for initializing the SimpleScanner object
    def __init__(self, in_stream):
        self.in = in_stream
        self.buffer = io.StringIO()
        self.eof = False

    # A method for reading a single character from the input stream
    def read(self):
        # If the character buffer is empty, refill it
        if not self.buffer.tell():
            self.buffer.write(self.in.read())
        # Return the current character from the character buffer
        return self.buffer.read(1)

    # A method for checking the end-of-file condition
    def checkEof(self):
        if self.eof:
            raise NoSuchElementException()

    # A method for reading a single character
    def nextChar(self):
        self.checkEof()
        b = self.read()
        self.checkEof()
        return b

    # A method for reading a string
    def next(self):
        sb = io.StringIO()
        b = self.read()
        while not self.eof:
            sb.write(b)
            b = self.read()
        return sb.getvalue()

    # A method for reading an integer
    def nextInt(self):
        return int(self.next())

    # A method for reading a long integer
    def nextLong(self):
        return long(self.next())

    # A method for reading a double
    def nextDouble(self):
        return float(self.next())

# Main method is the entry point of the Python application
def main():
    # Creating a SimpleScanner object for reading input and a PrintWriter object for writing output
    scanner = SimpleScanner(sys.stdin)
    writer = sys.stdout

    # Reading input variables from the user
    r = scanner.nextInt()  # Reading the first integer 'r' from the user
    d = scanner.nextInt()  # Reading the second integer 'd' from the user
    x = scanner.nextLong()  # Reading the long integer 'x' from the user

    # Running the loop for 10 iterations
    for i in range(10):
        # Multiplying 'r' with 'x' and subtracting 'd' from it
        x = r * x - d

        # Writing the result to the output stream
        writer.write(str(x) + '\n')

# Calling the main method
if __name__ == '__main__':
    main()

# 