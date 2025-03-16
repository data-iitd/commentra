
import sys

def main():
    # Set up input and output streams
    input = sys.stdin
    output = sys.stdout

    # Initialize the LightScanner for reading input
    in = LightScanner(input)

    # Initialize PrintWriter for output
    out = PrintWriter(output)

    # Create an instance of the problem solver
    solver = BUnhappyHackingABCEdit()

    # Solve the problem for the first test case
    solver.solve(1, in, out)

    # Close the output stream
    out.close()

# Class to solve the B Unhappy Hacking problem
class BUnhappyHackingABCEdit:
    def solve(self, testNumber, in, out):
        # Read the input string
        s = in.string()
        # StringBuilder to construct the output string
        d = StringBuilder()

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
                if len(d) > 0:
                    d.setLength(len(d) - 1)

        # Output the final result
        out.println(d)

# Class for reading input efficiently
class LightScanner:
    def __init__(self, input):
        self.reader = BufferedReader(input)
        self.tokenizer = None

    def string(self):
        # Check if there are more tokens to read
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                # Read a new line and create a new StringTokenizer
                self.tokenizer = StringTokenizer(self.reader.readLine())
            except IOException as e:
                # Handle IOException by throwing an unchecked exception
                raise UncheckedIOException(e)

        # Return the next token
        return self.tokenizer.nextToken()

# End of code
