
// by syu
import sys

# Initialize a new scanner for reading input
in = Scanner(sys.stdin)

def main():
    # Read the first two integers from the standard input
    n, k = in.int(), in.int()

    # Check if n is divisible by k
    if n % k == 0:
        # If it is, print 0
        print(0)
    else:
        # If not, print 1
        print(1)

# Define a new Scanner type
class Scanner:
    # Create a new Scanner instance
    def __init__(self, r):
        # Initialize a new bufio.Scanner instance
        self.s = bufio.Scanner(r)
        # Set the split function to split on words instead of whitespace
        self.s.split(scanWords)
        # Set the buffer size if it's provided
        if max <= 0:
            max = 1048576
        # Set the buffer and return the new Scanner instance
        self.s.buffer([]byte{}, max)
        return self

    # Parse an integer from a string
    def int(self):
        # Read the next token as a string
        self.s.scan()
        # Parse the string to an integer and return it
        i, _ = strconv.ParseInt(self.s.text(), 10, 64)
        # Return the integer value
        return int(i)

# Check if a byte is a whitespace character
def isSpace(b):
    # Return true if the byte is a space, newline, carriage return, or tab character
    return b == ' ' or b == '\n' or b == '\r' or b == '\t'

# Split function for bufio.Scanner to split on words instead of whitespace
def scanWords(data, atEOF):
    # Initialize the start index
    start = 0
    # Find the first non-whitespace character
    for start < len(data) and isSpace(data[start]):
        start++
    # Iterate through the data and find the next whitespace character or end of data
    for i in range(start, len(data)):
        # If the current character is a whitespace character, return the token and advance the index
        if isSpace(data[i]):
            return i + 1, data[start:i], None
    # If we've reached the end of data and there's still data to read, return the remaining data as the token
    if atEOF and len(data) > start:
        return len(data), data[start:], None
    # Return the start index as the token and the length of the token as the advance value
    return start, None, None

# Print a line with the given arguments
def Pln(s):
    # Print the line with the given arguments
    print(s)

# END-OF-CODE
