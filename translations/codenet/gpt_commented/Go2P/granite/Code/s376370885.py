
# by syu
import sys

# Initialize a new Scanner for reading input from standard input (sys.stdin)
in = Scanner(sys.stdin)

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

# Scanner class wraps bufio.Scanner for custom input handling
class Scanner:
    def __init__(self, r):
        self.s = bufio.Scanner(r) # Create a new Scanner
        self.s.whitespace = " \n\r\t" # Set the whitespace characters to be ignored
        self.s.buffer_size = 1048576 # Set the buffer size for the scanner

    def int(self):
        self.s.scan() # Scan the next token
        return int(self.s.token()) # Return the parsed integer

# Pln is a convenience function to print a line to standard output
def Pln(*s):
    print(*s) # Print the provided arguments

# End of code
