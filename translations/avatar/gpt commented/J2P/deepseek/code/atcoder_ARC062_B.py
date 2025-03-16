import sys
import io
import os

class InputReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream

    def next(self):
        # Read a line from the input stream
        line = self.input_stream.readline()
        # Strip any leading/trailing whitespace and return the line
        return line.strip()

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Create an InputReader to read input from the input stream
    in_reader = InputReader(input_stream)
    
    # Create a PrintWriter to write output to the output stream
    out = io.TextIOWrapper(output_stream, write_through=True)
    
    # Create an instance of TaskD to solve the problem
    solver = TaskD()
    
    # Call the solve method with test number, input reader, and output writer
    solver.solve(1, in_reader, out)
    
    # Close the output writer
    out.flush()

class TaskD:
    def solve(self, test_number, in_reader, out):
        # Read the input string S
        S = in_reader.next()
        score = 0  # Initialize score to zero
        
        # Iterate through each character in the string S
        for i in range(len(S)):
            # Determine the character for 'my' based on the index (even or odd)
            my = 'g' if i % 2 == 0 else 'p'
            
            # Get the character from the input string at the current index
            his = S[i]
            
            # Compare 'my' and 'his' characters to update the score
            if my != his:
                # Increment score if 'my' is 'p', otherwise decrement
                score += 1 if my == 'p' else -1
        
        # Output the final score
        out.write(f"{score}\n")

if __name__ == "__main__":
    main()
