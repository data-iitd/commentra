import sys
import random

# Constants
inf = float('inf')  # Maximum signed integer value

# Directions for movement
dx = [0, 1, 1, 1, 0, -1, -1, -1, 0]
dy = [1, 1, 0, -1, -1, -1, 0, 1, 0]

# Global scanner for reading input
class Scanner:
    def __init__(self):
        self.buffer = []
        self.position = 0

    def next(self):
        self.pre()
        start = self.position
        while self.position < len(self.buffer):
            if self.buffer[self.position] == ' ':
                break
            self.position += 1
        result = ''.join(self.buffer[start:self.position])
        self.position += 1
        return result

    def line(self):
        self.pre()
        start = self.position
        self.position = len(self.buffer)
        return ''.join(self.buffer[start:])

    def string(self):
        return self.next()

    def int(self):
        return int(self.next())

    def ints(self, n):
        return [self.int() for _ in range(n)]

    def pre(self):
        if self.position >= len(self.buffer):
            self.read_line()
            self.position = 0

    def read_line(self):
        self.buffer = list(sys.stdin.readline().strip())

# Initialize the scanner
next = Scanner()

# Main function
def main():
    # Read input N as a string
    N = next.string()
    # Convert N to an integer
    n = sum(int(digit) for digit in N)  # Sum of digits in N
    m = int(N)  # Convert N to an integer
    # Check if m is divisible by n
    if m % n == 0:
        print("Yes")  # Print "Yes" if m is divisible by n
    else:
        print("No")  # Print "No" if m is not divisible by n

# Entry point of the program
if __name__ == "__main__":
    random.seed()  # Seed random number generator
    main()

# <END-OF-CODE>
