// by syu
import sys

# Define a custom scanner type that wraps sys.stdin
class Scanner:
    def __init__(self, max=1048576):
        self.max = max
        self.buffer = []

    def scan(self):
        if not self.buffer:
            self.buffer = sys.stdin.readline().strip().split()
        return self.buffer.pop(0)

    def int(self):
        return int(self.scan())

# Check if a character is a whitespace character
def is_space(c):
    return c == ' ' or c == '\n' or c == '\r' or c == '\t'

# Split input data into tokens using scan_words function
def scan_words(data, at_eof=False):
    start = 0
    for start in range(len(data)):
        if not is_space(data[start]):
            break
    for i in range(start, len(data)):
        if is_space(data[i]):
            return i + 1, data[start:i]
    if at_eof and len(data) > start:
        return len(data), data[start:]
    return start, None

# Print a line to the console with the given arguments
def pln(s):
    print(s)

# Entry point of the program
def main():
    # Read two integers n and k from standard input
    n, k = in.int(), in.int()
    # Check if n is divisible by k
    if n % k == 0:
        # If n is divisible by k, print 0 to the console
        pln(0)
    else:
        # If n is not divisible by k, print 1 to the console
        pln(1)

