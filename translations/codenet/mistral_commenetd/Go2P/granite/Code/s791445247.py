

# by syu
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
    def __init__(self, r):
        # Initialize a new bufio.Scanner instance
        self.s = bufio.Scanner(r)
        # Set the split function to split on words instead of whitespace
        self.s.word_chars = bytes(string.ascii_letters + string.digits, 'utf-8')
        self.s.buffer = []
        self.s.buffersize = 1048576

    # Parse an integer from a string
    def int(self):
        # Read the next token as a string
        self.s.scan()
        # Parse the string to an integer and return it
        return int(self.s.token())

# Print a line with the given arguments
def Pln(*s):
    # Print the line with the given arguments
    print(*s)

# End of code
