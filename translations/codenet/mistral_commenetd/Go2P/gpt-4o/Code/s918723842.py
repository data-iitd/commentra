# Import necessary modules
import sys

# max function returns the maximum value between two integers a and b.
def max(a, b):
    return b if a < b else a

# Scanner class represents the input reader.
class Scanner:
    def __init__(self):
        # Initialize a buffer for reading input
        self.buffer = sys.stdin.read().splitlines()
        self.current_line = 0
        self.current_pos = 0

    # Next method reads the next token from the input.
    def next(self):
        self.pre()
        start = self.current_pos
        while self.current_pos < len(self.buffer[self.current_line]) and self.buffer[self.current_line][self.current_pos] != ' ':
            self.current_pos += 1
        result = self.buffer[self.current_line][start:self.current_pos]
        self.current_pos += 1  # Move past the space
        return result

    # NextLine method reads the next line from the input.
    def next_line(self):
        self.pre()
        result = self.buffer[self.current_line]
        self.current_line += 1
        self.current_pos = 0
        return result

    # NextInt method reads an integer from the input.
    def next_int(self):
        token = self.next()
        return int(token)

    # pre method prepares the scanner for reading the next token.
    def pre(self):
        while self.current_line < len(self.buffer) and self.current_pos >= len(self.buffer[self.current_line]):
            self.current_line += 1
            self.current_pos = 0

# main function is the entry point of the program.
def main():
    sc = Scanner()
    H = sc.next_int()
    W = sc.next_int()
    N = sc.next_int()
    A = max(H, W)
    print((N + A - 1) // A)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
