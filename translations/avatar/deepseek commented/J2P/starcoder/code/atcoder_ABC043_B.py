
import sys

class BUnhappyHackingABCEdit:
    def solve(self, testNumber, in, out):
        # Read the input string
        s = in.string()
        
        # StringBuilder to build the result
        d = []
        
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
                    d.pop()
        
        # Print the result
        out.println(''.join(d))

# Helper class for solving the problem
class Main:
    def __init__(self):
        # Step 1: Define the input stream and output stream
        self.inputStream = sys.stdin
        self.outputStream = sys.stdout
        
        # Step 2: Create a LightScanner instance for reading input efficiently
        self.in = LightScanner(self.inputStream)
        
        # Step 3: Create a PrintWriter instance for writing output
        self.out = PrintWriter(self.outputStream)
        
        # Step 4: Create an instance of the problem solver
        self.solver = BUnhappyHackingABCEdit()
        
        # Step 5: Solve the problem
        self.solver.solve(1, self.in, self.out)
        
        # Close the output writer
        self.out.close()

# Helper class for reading input efficiently
class LightScanner:
    def __init__(self, in):
        self.reader = in
        self.tokenizer = None
    
    def string(self):
        if self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        return self.tokenizer.nextToken()

# Main entry point of the program
if __name__ == '__main__':
    Main()

