import sys
import io
import os
import math

# Define a constant for the buffer size used in input and output operations
BUFFERSIZE = 512000

# Initialize a StringIO for reading input with a buffered reader for efficiency
input_stream = io.TextIOWrapper(sys.stdin.buffer, BUFFERSIZE)

# Initialize a StringIO for output with a buffered output stream for efficiency
output_stream = io.TextIOWrapper(sys.stdout.buffer, BUFFERSIZE)

# Method to solve the main problem
def solve():
    # Read the position from input
    position = int(input_stream.readline().strip())
    
    # Initialize the nearest sequence start index
    nrst_seq_start_indx = 1
    
    # Find the nearest sequence start index such that its value is less than the position
    while getValueAtIndex(nrst_seq_start_indx * 2) < position:
        nrst_seq_start_indx *= 2
    
    # Increment the nearest sequence start index until its value exceeds the position
    while getValueAtIndex(nrst_seq_start_indx + 1) <= position:
        nrst_seq_start_indx += 1
    
    # Get the starting index value for the nearest sequence
    start_index = getValueAtIndex(nrst_seq_start_indx)
    
    # Output the result, which is the difference between the position and the start index plus one
    output_stream.write(f"{position - start_index + 1}\n")

# Method to calculate the value at a given index based on a specific formula
def getValueAtIndex(index):
    return 1 + ((index - 1) * index // 2)

# Main method to execute the program
if __name__ == "__main__":
    # Call the solve method to process the input and produce output
    solve()
    
    # Close the output stream
    output_stream.flush()
