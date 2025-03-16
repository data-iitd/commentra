
#!/usr/bin/env python3

import sys

# getScanner initializes a new scanner for reading from the provided file pointer.
def getScanner(fp):
    scanner = fp.read().split() # Split the input into words
    return scanner

# getNextString retrieves the next string from the scanner.
def getNextString(scanner):
    return scanner.pop(0) # Retrieve the next string

# getNextInt retrieves the next integer from the scanner.
def getNextInt(scanner):
    return int(getNextString(scanner)) # Convert the next string to an integer

# getNextInt64 retrieves the next int64 from the scanner.
def getNextInt64(scanner):
    return int(getNextString(scanner)) # Convert the next string to int64

# getNextUint64 retrieves the next uint64 from the scanner.
def getNextUint64(scanner):
    return int(getNextString(scanner)) # Convert the next string to uint64

# getNextFloat64 retrieves the next float64 from the scanner.
def getNextFloat64(scanner):
    return float(getNextString(scanner)) # Convert the next string to float64

def main():
    # Determine the input source: either standard input or a file specified as a command-line argument
    if len(sys.argv) > 1:
        fp = open(sys.argv[1], 'r') # Open the file if an argument is provided
    else:
        fp = sys.stdin # Otherwise, use standard input
    scanner = getScanner(fp) # Initialize the scanner for the input source
    writer = sys.stdout # Create a buffered writer for output

    # Read the number of elements and operations
    n = getNextInt(scanner)
    m = getNextInt(scanner)

    # Initialize the Segment structure
    seg = Segment()
    seg.init(n) # Initialize the segment with size n

    # Populate the segment with initial values
    for i in range(n):
        seg.maximize(i, getNextInt(scanner)) # Maximize the segment with the input values

    # Perform m operations to maximize the segment
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h-1][0]>>1) # Maximize using the top value and half of the last bucket's first element

    # Calculate the final answer by summing up the values in the first bucket
    ans = 0
    for i in range(n):
        ans += seg.bucket[0][i] # Accumulate the values

    # Output the final result
    print(ans)

# Segment structure to hold the segment data and operations
class Segment:
    def __init__(self):
        self.n = 0
        self.h = 0
        self.i = 0
        self.chunk = 0
        self.unit = []
        self.bucket = []

    # init initializes the segment structure with the given size n.
    def init(self, n):
        self.n = n
        self.unit = [1] # Initialize unit array
        self.bucket = [[0 for i in range(n)]] # Initialize bucket array

        chunk = 8 # Define the chunk size
        for i in range(0, n):
            n = (n-1)//chunk + 1 # Reduce n based on the chunk size
            self.bucket.append([0 for i in range(n)]) # Append a new bucket
            self.unit.append(self.unit[i]*chunk) # Update unit array
        self.h = len(self.unit) # Set the height of the segment
        self.chunk = chunk # Set the chunk size

    # maximize updates the segment at a given index with a new value.
    def maximize(self, index, value):
        self.bucket[0][index] = value # Set the value in the first bucket
        for i in range(0, self.h-1):
            s = index - index%self.chunk # Calculate the start of the current chunk
            t = s + self.chunk # Calculate the end of the current chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i]) # Adjust end if it exceeds the bucket length
            parent = index // self.chunk # Determine the parent index
            max = 0 # Initialize max value
            for i in range(s, t):
                if max < self.bucket[i]:
                    max = self.bucket[i] # Find the maximum value in the current chunk
            self.bucket[i+1][parent] = max # Update the parent bucket with the maximum value
            index //= self.chunk # Move to the parent index for the next iteration

    # top retrieves the index of the top value in the segment.
    def top(self):
        index = 0 # Start from the root index
        for i in range(self.h-2, -1, -1):
            s = index * self.chunk # Calculate the start of the current chunk
            t = s + self.chunk # Calculate the end of the current chunk
            if t > len(self.bucket[i]):
                t = len(self.bucket[i]) # Adjust end if it exceeds the bucket length
            for i in range(s, t):
                if self.bucket[i] == self.bucket[i+1][index]:
                    index = i # Update index if the value matches the top value
                    break
        return index # Return the index of the top value

