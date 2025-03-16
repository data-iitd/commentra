
import sys
import math

# Initialize constants
BUFFER_SIZE = 512000

# Initialize scanner and print writer
sc = sys.stdin
out = sys.stdout

# Main method
def main():
    init() # Initialize input and output streams
    solve() # Solve the problem
    closeIO() # Close input and output streams

# Initialize input and output streams
def init():
    in.init(sys.stdin) # Initialize input stream

# Close input and output streams
def closeIO():
    in.close() # Close input stream
    out.close() # Close output stream

# Solve the problem
def solve():
    position = sc.nextLong() # Read the position from input
    solveHelper(position) # Solve the problem using helper method

# Helper method to solve the problem
def solveHelper(position):
    nrstSeqStartIndx = 1 # Initialize index for the start of the next sequence

    # Binary search for the start index of the sequence containing the position
    while getValueAtIndex(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2 # Multiply index by 2

    # Linear search for the end index of the sequence containing the position
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1 # Increment index

    # Print the answer
    startIndex = getValueAtIndex(nrstSeqStartIndx) # Get the start index of the sequence
    out.println((position - startIndex) + 1) # Print the length of the sequence

# Get the value at a given index
def getValueAtIndex(index):
    return 1 + ((index - 1) * index / 2) # Calculate the value at the given index

# Inner class for input handling
class in:
    reader = None
    tokenizer = None

    # Initialize input stream
    @staticmethod
    def init(input):
        in.reader = sys.stdin
        in.tokenizer = sys.stdin.readline().split()

    # Read a string token from input
    @staticmethod
    def next():
        while not in.tokenizer:
            in.tokenizer = in.reader.readline().split()
        return in.tokenizer.pop(0)

    # Read an integer from input
    @staticmethod
    def nextInt():
        return int(in.next())

    # Read a double from input
    @staticmethod
    def nextDouble():
        return float(in.next())

    # Read a long from input
    @staticmethod
    def nextLong():
        return long(in.next())

if __name__ == "__main__":
    main()

