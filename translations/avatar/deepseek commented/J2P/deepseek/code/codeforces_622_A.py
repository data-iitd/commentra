import sys
import io
import os
import math

BUFFERSIZE = 512000

# Step 2: Define the Scanner and PrintWriter for input and output operations.
# Since Python does not have built-in support for buffered input/output, we will use sys.stdin and sys.stdout.

# Step 3: Implement the solve method to find the position of a given value in a sequence.
def solve():
    position = int(sys.stdin.readline().strip())
    nrstSeqStartIndx = 1
    
    # Step 4: Find the starting index of the sequence where the position might be located.
    while getValueAtIndex(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2
    
    # Step 4: Find the exact position within the sequence.
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1
    
    startIndex = getValueAtIndex(nrstSeqStartIndx)
    print((position - startIndex) + 1)

# Step 4: Implement the getValueAtIndex method to calculate the value at a specific index in the sequence.
def getValueAtIndex(index):
    return 1 + ((index - 1) * index // 2)

# Step 5: Implement the main method to initialize the input and call the solve method.
if __name__ == "__main__":
    # Since Python does not have a built-in way to handle input buffering, we will use sys.stdin directly.
    position = int(sys.stdin.readline().strip())
    solve()
