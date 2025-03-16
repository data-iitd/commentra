
import sys

# Main method is the entry point of the Python application
def main():

    # Initialize input and output streams
    inputStream = sys.stdin
    outputStream = sys.stdout

    # Create InputReader and PrintWriter objects
    in = InputReader(inputStream)
    out = PrintWriter(outputStream)

    # Read input integers a, b, c, and d
    a = in.nextInt()
    b = in.nextInt()
    c = in.nextInt()
    d = in.nextInt()

    # Check if c is greater than b
    if c > b:
        # If yes, print 0 and exit
        out.println(0)
        return

    # Check if a is greater than d
    elif a > d:
        # If yes, print 0 and exit
        out.println(0)
        return

    # Check if a is less than c
    elif a < c:
        # If yes, calculate the difference between the smaller and larger of b and d
        difference = min(b, d) - c
        # Print the difference
        out.println(difference)
        return

    # If none of the above conditions are true, then a, b, c, and d are in sorted order
    else:
        # Create a List of integers a, b, c, and d
        l = [a, b, c, d]

        # Sort the List in ascending order
        l.sort()

        # Calculate the difference between the second and third elements of the List
        difference = l[2] - l[1]

        # Print the difference
        out.println(difference)

# InputReader class for reading input from standard input
class InputReader:

    reader = None
    tokenizer = None

    # Constructor for InputReader
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    # Method for reading a string
    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

    # Method for reading an integer
    def nextInt(self):
        return int(self.next())

    # Method for reading a long integer
    def nextLong(self):
        return long(self.next())

# PrintWriter class for writing output to standard output
class PrintWriter:

    writer = None

    # Constructor for PrintWriter
    def __init__(self, stream):
        self.writer = stream

    # Method for writing a string
    def println(self, s):
        self.writer.write(s + "\n")

# END-OF-CODE
