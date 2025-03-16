
import sys

# Define a constant for the buffer size used in input and output operations
BUFFERSIZE = 512000

# Initialize a Scanner for reading input with a buffered reader for efficiency
sc = iter(sys.stdin.read().splitlines())

# Initialize a PrintWriter for output with a buffered output stream for efficiency
out = sys.stdout

# Method to solve the main problem
def solve():
    # Read the position from input
    position = int(next(sc))

    # Initialize the nearest sequence start index
    nrstSeqStartIndx = 1

    # Find the nearest sequence start index such that its value is less than the position
    while getValueAtIndex(nrstSeqStartIndx * 2) < position:
        nrstSeqStartIndx *= 2

    # Increment the nearest sequence start index until its value exceeds the position
    while getValueAtIndex(nrstSeqStartIndx + 1) <= position:
        nrstSeqStartIndx += 1

    # Get the starting index value for the nearest sequence
    startIndex = getValueAtIndex(nrstSeqStartIndx)

    # Output the result, which is the difference between the position and the start index plus one
    out.write(str((position - startIndex) + 1) + '\n')

# Method to calculate the value at a given index based on a specific formula
def getValueAtIndex(index):
    return 1 + ((index - 1) * index // 2)

# Main method to execute the program
def main():
    # Call the solve method to process the input and produce output
    solve()

# Execute the main method
if __name__ == '__main__':
    main()

# End of code