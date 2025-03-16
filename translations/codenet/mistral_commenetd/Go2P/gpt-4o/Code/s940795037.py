# Importing necessary modules
import sys

class Scanner:
    def __init__(self):
        # Initializing the input buffer
        self.buffer = sys.stdin.read().splitlines()
        self.current_line = 0
        self.current_token = 0

    def next(self):
        # Get the next token from the input
        while self.current_line < len(self.buffer):
            line = self.buffer[self.current_line].strip()
            if line:
                tokens = line.split()
                if self.current_token < len(tokens):
                    token = tokens[self.current_token]
                    self.current_token += 1
                    return token
                else:
                    self.current_line += 1
                    self.current_token = 0
        return ""

    def next_int(self):
        # Read the next token as an integer
        return int(self.next())

def main():
    # Creating a new scanner instance
    sc = Scanner()

    # Reading the first integer from the standard input
    n = sc.next_int()
    # Initializing the answer variable
    ans = 0.0

    # Iterating through the given number of integers
    for _ in range(n):
        # Reading the next integer from the standard input
        tmp = 1 / float(sc.next_int())
        # Adding the reciprocal of the current integer to the answer
        ans += tmp

    # Printing the final answer
    print(1 / ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
