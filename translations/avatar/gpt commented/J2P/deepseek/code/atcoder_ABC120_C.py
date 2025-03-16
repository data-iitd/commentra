import sys
import io
import os
import re
from collections import deque

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next(self):
        # Read the next token from the input stream
        while True:
            line = self.input_stream.readline()
            if not line:
                break
            yield line.strip()

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = InputReader(input_stream)
    out = io.TextIOWrapper(output_stream, write_through=True)
    
    # Create an instance of TaskB and solve the problem
    solver = TaskB()
    solver.solve(in_reader, out)
    
    # Close the output stream
    out.flush()

class TaskB:
    def solve(self, in_reader, out):
        # Read the input string
        x = next(in_reader.next())
        s = deque()
        c = 0  # Counter for pairs of '0' and '1'
        
        # Iterate through each character in the input string
        for i in range(len(x)):
            # Append the current character to the deque
            s.append(x[i])
            
            # Process the deque while there are at least two characters
            while len(s) > 1:
                p = s.pop()  # Pop the last character
                q = s.pop()  # Pop the next last character
                
                # Check if the characters form a pair of '0' and '1'
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    c += 1  # Increment the counter for valid pairs
                    continue  # Continue to check for more pairs
                else:
                    # If not a valid pair, push the characters back to the deque
                    s.append(q)
                    s.append(p)
                    break  # Exit the while loop
        
        # Output the result, which is twice the count of pairs found
        out.write(str(c * 2) + '\n')

if __name__ == "__main__":
    main()
