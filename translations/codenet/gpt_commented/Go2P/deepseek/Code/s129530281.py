import sys
import io
import os
import math

# get_next_string retrieves the next string from the input.
def get_next_string(input_stream):
    return input_stream.readline().strip()

# get_next_int retrieves the next integer from the input.
def get_next_int(input_stream):
    return int(get_next_string(input_stream))

# get_next_int64 retrieves the next int64 from the input.
def get_next_int64(input_stream):
    return int(get_next_string(input_stream))

# get_next_uint64 retrieves the next uint64 from the input.
def get_next_uint64(input_stream):
    return int(get_next_string(input_stream))

# get_next_float64 retrieves the next float64 from the input.
def get_next_float64(input_stream):
    return float(get_next_string(input_stream))

# main function to execute the program
def main():
    # Determine the input source: either standard input or a file specified as a command-line argument
    input_stream = sys.stdin
    if len(sys.argv) > 1:
        input_stream = open(sys.argv[1], 'r')  # Open the file if an argument is provided

    # Read the number of elements and operations
    n = get_next_int(input_stream)
    m = get_next_int(input_stream)

    # Initialize the Segment structure
    seg = Segment()
    seg.init(n)  # Initialize the segment with size n

    # Populate the segment with initial values
    for i in range(n):
        seg.maximize(i, get_next_int(input_stream))  # Maximize the segment with the input values

    # Perform m operations to maximize the segment
    for i in range(m):
        seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1)  # Maximize using the top value and half of the last bucket's first element

    # Calculate the final answer by summing up the values in the first bucket
    ans = 0
    for i in range(n):
        ans += seg.bucket[0][i]  # Accumulate the values

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
        self.unit = [1]  # Initialize unit array
        self.bucket = [[]]  # Initialize bucket array
        self.bucket[0] = [0] * n

        self.chunk = 8  # Define the chunk size
        while n > 1:
            n = (n - 1) // self.chunk + 1  # Reduce n based on the chunk size
            self.bucket.append([0] * n)  # Append a new bucket
            self.unit.append(self.unit[-1] * self.chunk)  # Update unit array
        self.h = len(self.unit)  # Set the height of the segment

    # maximize updates the segment at a given index with a new value.
    def maximize(self, index, value):
        self.bucket[0][index] = value  # Set the value in the first bucket
        for self.i in range(self.h - 1):
            s = index - index % self.chunk  # Calculate the start of the current chunk
            t = s + self.chunk  # Calculate the end of the current chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])  # Adjust end if it exceeds the bucket length
            parent = index // self.chunk  # Determine the parent index
            max_val = max(self.bucket[self.i][s:t])  # Find the maximum value in the current chunk
            self.bucket[self.i + 1][parent] = max_val  # Update the parent bucket with the maximum value
            index //= self.chunk  # Move to the parent index for the next iteration

    # top retrieves the index of the top value in the segment.
    def top(self):
        index = 0  # Start from the root index
        for self.i in range(self.h - 2, -1, -1):
            s = index * self.chunk  # Calculate the start of the current chunk
            t = s + self.chunk  # Calculate the end of the current chunk
            if t > len(self.bucket[self.i]):
                t = len(self.bucket[self.i])  # Adjust end if it exceeds the bucket length
            for i in range(s, t):
                if self.bucket[self.i][i] == self.bucket[self.i + 1][index]:
                    index = i  # Update index if the value matches the top value
                    break
        return index  # Return the index of the top value

# Execute the main function
if __name__ == "__main__":
    main()
