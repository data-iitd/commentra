
import sys

def main():
    # Step 1: Define the input stream and output stream
    inputStream = sys.stdin
    outputStream = sys.stdout
    
    # Step 2: Create a LightScanner instance for reading input efficiently
    in = LightScanner(inputStream)
    
    # Step 3: Create a PrintWriter instance for writing output
    out = PrintWriter(outputStream)
    
    # Step 4: Create an instance of the problem solver
    solver = BUnhappyHackingABCEdit()
    
    # Step 5: Solve the problem
    solver.solve(1, in, out)
    
    # Close the output writer
    out.close()

# Helper class for solving the problem
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

# LightScanner class for reading input efficiently
class LightScanner:
    def __init__(self, in):
        self.reader = BufferedReader(InputStreamReader(in))
    
    def string(self):
        if self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                raise UncheckedIOException(e)
        return self.tokenizer.nextToken()

# PrintWriter class for writing output
class PrintWriter:
    def __init__(self, out):
        self.writer = BufferedWriter(OutputStreamWriter(out))
    
    def println(self, s):
        self.writer.write(s + '\n')

# END-OF-CODE
