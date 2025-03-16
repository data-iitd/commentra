

# by syu
import sys

# Initialize a global Scanner instance to read from standard input
in = Scanner(sys.stdin)

def main():
    # Read two integers, n and k, from standard input
    n, k = in.int(), in.int()
    
    # Check if n is divisible by k
    if n % k == 0:
        # If n is divisible by k, print 0
        print(0)
    else:
        # If n is not divisible by k, print 1
        print(1)

# Define a custom Scanner type to read input efficiently
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

# Helper function to print a line of output
def Pln(*s):
    print(*s)

