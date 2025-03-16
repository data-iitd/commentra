
import sys

def main():
    # Read input from the console
    input_stream = sys.stdin
    output_stream = sys.stdout
    in = LightScanner(input_stream)
    out = PrintWriter(output_stream)

    # Test case number
    test_number = 1

    # Initialize the solver
    solver = BUnhappyHackingABCEdit()

    # Run the solver with the given input and output streams
    solver.solve(test_number, in, out)

    # Close the PrintWriter to flush the output buffer
    out.close()

# Static class for reading input
class LightScanner:
    def __init__(self, in):
        self.reader = BufferedReader(InputStreamReader(in))

    def string(self):
        if self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                line = self.reader.readLine()
                if line is None:
                    raise UncheckedIOException()
                self.tokenizer = StringTokenizer(line)
            except IOException as e:
                raise UncheckedIOException(e)
        return self.tokenizer.nextToken()

# Static class for solving the problem
class BUnhappyHackingABCEdit:
    def solve(self, test_number, in, out):
        # Read the input string
        s = in.string()
        d = StringBuilder()

        # Iterate through each character in the input string
        for c in s:
            # Switch statement to handle different characters
            if c == '0':
                d.append("0")
            elif c == '1':
                d.append("1")
            elif c == 'B':
                if d.length() > 0:
                    d.setLength(d.length() - 1)
                    d.trimToSize()

        # Print the output StringBuilder to the console
        out.println(d)

# Static class for writing output
class PrintWriter:
    def __init__(self, out):
        self.out = out

    def close(self):
        self.out.close()

    def println(self, d):
        self.out.write(str(d))
        self.out.write("\n")

# Static class for building output strings
class StringBuilder:
    def __init__(self):
        self.string = ""

    def append(self, s):
        self.string += s

    def setLength(self, length):
        self.string = self.string[:length]

    def trimToSize(self):
        pass

    def length(self):
        return len(self.string)

    def __str__(self):
        return self.string

if __name__ == "__main__":
    main()

