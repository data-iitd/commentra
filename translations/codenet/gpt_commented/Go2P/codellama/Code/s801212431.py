
# Import the required libraries
import sys

# Define constants for buffer sizes
initial_buf_size = 1e4 # Initial buffer size for the scanner
max_buf_size = 1e8 # Maximum buffer size for the scanner

# Create a new scanner to read from standard input
sc = sys.stdin

# Initialize the scanner with a buffer and set the split function
buf = bytearray(initial_buf_size) # Create a byte array for the buffer
sc.buffer(buf, max_buf_size) # Set the buffer size for the scanner
sc.split(None, maxsplit=0) # Split the input by words

# Function to read the next word from input
def next():
    sc.scan() # Scan the next word
    return sc.text() # Return the scanned word as a string

# Function to return the minimum of two integers
def min(x, y):
    if x > y:
        return y # Return y if x is greater
    else:
        return x # Return x otherwise

# Main function where the program execution begins
def main():
    S = next() # Read the input string

    l0, l1 = 0, 0 # Initialize counters for '0's and '1's
    # Loop through each character in the input string
    for i in range(len(S)):
        if S[i] == '0':
            l0 += 1 # Increment the counter for '0'
        else:
            l1 += 1 # Increment the counter for '1'
    # Print the result, which is twice the minimum count of '0's or '1's
    print(2 * min(l0, l1))

# End of code
