

import sys

def main():
    # Step 1: Define the input stream and output stream
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Step 2: Create a LightScanner instance for reading input efficiently
    in = LightScanner(input_stream)
    
    # Step 3: Create a PrintWriter instance for writing output
    out = PrintWriter(output_stream)
    
    # Step 4: Create an instance of the problem solver
    solver = BUnhappyHackingABCEdit()
    
    # Step 5: Solve the problem
    solver.solve(1, in, out)
    
    # Close the output writer
    out.close()

# Helper class for solving the problem
class BUnhappyHackingABCEdit:
    def solve(self, test_number, in, out):
        # Read the input string
        s = in.string()
        
        # StringBuilder to build the result
        d = StringBuilder()
        
        # Iterate over each character in the input string
        for c in s:
            if c == '0':
                # Append '0' to the result
                d.append('0')
            elif c == '1':
                # Append '1' to the result
                d.append('1')
            elif c == 'B':
                # Remove the last character if the result is not empty
                if len(d) > 0:
                    d.setLength(len(d) - 1)
        
        # Print the result
        out.println(d)

# LightScanner class for reading input efficiently
class LightScanner:
    def __init__(self, in):
        self.reader = BufferedReader(in)
        self.tokenizer = None
    
    def string(self):
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise UncheckedIOException(e)
        return self.tokenizer.nextToken()

if __name__ == '__main__':
    main()

