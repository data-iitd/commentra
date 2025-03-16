import sys
import io
import os

input = sys.stdin.read

def main():
    # Set up input and output streams
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    
    # Initialize the LightScanner for reading input
    in_ = LightScanner(input_stream)
    
    # Initialize PrintWriter for output
    out = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    
    # Create an instance of the problem solver
    solver = BUnhappyHackingABCEdit()
    
    # Solve the problem for the first test case
    solver.solve(1, in_, out)
    
    # Close the output stream
    out.flush()

# Class to solve the B Unhappy Hacking problem
class BUnhappyHackingABCEdit:
    def solve(self, testNumber, in_, out):
        # Read the input string
        s = in_.string()
        # String to construct the output string
        d = []
        
        # Process each character in the input string
        for c in s:
            if c == '0':
                # Append '0' to the output
                d.append('0')
            elif c == '1':
                # Append '1' to the output
                d.append('1')
            elif c == 'B':
                # Handle the 'B' character by removing the last character if possible
                if d:
                    d.pop()  # Remove the last character
        
        # Output the final result
        out.write(''.join(d) + '\n')
        out.flush()

# Class for reading input efficiently
class LightScanner:
    def __init__(self, input_stream):
        self.reader = input_stream
        self.buf = []
        self.pos = 0
    
    def string(self):
        # Read a line from the input stream
        while self.pos == len(self.buf):
            self.buf = self.reader.readline().split()
            self.pos = 0
        result = self.buf[self.pos]
        self.pos += 1
        return result

if __name__ == '__main__':
    main()
