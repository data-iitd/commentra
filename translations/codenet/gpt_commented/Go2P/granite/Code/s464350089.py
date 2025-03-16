
import sys

# Define a constant for the modulo value
mod = 1000000007

# Define a constant for the input/output buffer size (1MB)
ioBufferSize = 1 * 1024 * 1024

# Initialize a buffered reader for reading input
br = sys.stdin.buffer
# Set the buffer size for the reader
br.buffer = bytearray(ioBufferSize)
# Split the input by whitespace
br.read = lambda: br.read().split()

# Function to read the next string from input
def next():
    return next(br.read)

# Function to read the next integer from input
def nextInt():
    return int(next())

def main():
    # Read the values of h and n from input
    h, n = nextInt(), nextInt()
    a = 0 # Initialize a variable to accumulate the sum of integers

    # Loop to read n integers and accumulate their sum
    for i in range(n):
        a += nextInt()

    # Check if the accumulated sum is less than h
    if h > a:
        # If h is greater than the sum, print "No"
        print("No")
    else:
        # Otherwise, print "Yes"
        print("Yes")

