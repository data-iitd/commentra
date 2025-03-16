

import sys

# Initialize constants
BUFFER_SIZE = 512000

# Initialize input and output streams
def init():
 global in_file, out_file
 in_file = sys.stdin
 out_file = sys.stdout

# Close input and output streams
def closeIO():
 in_file.close()
 out_file.close()

# Solve the problem
def solve():
 position = long(in_file.readline())
 solveHelper(position)

# Helper method to solve the problem
def solveHelper(position):
 nrstSeqStartIndx = 1
 while getValueAtIndex(nrstSeqStartIndx * 2) < position:
 nrstSeqStartIndx *= 2
 while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
 nrstSeqStartIndx += 1
 startIndex = getValueAtIndex(nrstSeqStartIndx)
 out_file.write(str(position - startIndex + 1) + '\n')

# Get the value at a given index
def getValueAtIndex(index):
 return 1 + (index - 1) * index / 2

# Main method
def main():
 init() # Initialize input and output streams
 solve() # Solve the problem
 closeIO() # Close input and output streams

if __name__ == '__main__':
 main()

