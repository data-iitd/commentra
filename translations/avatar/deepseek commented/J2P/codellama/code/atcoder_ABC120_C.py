import sys

def main():
    # Set up the standard input and output streams
    inputStream = sys.stdin
    outputStream = sys.stdout
    # Create an InputReader to read input from the standard input stream
    in = InputReader(inputStream)
    # Create a PrintWriter to write output to the standard output stream
    out = PrintWriter(outputStream)
    # Create an instance of TaskB and call its solve method
    solver = TaskB()
    solver.solve(1, in, out)
    # Close the PrintWriter to flush the output and close the stream
    out.close()

class TaskB:
    # The solve method implements the main logic
    def solve(self, testNumber, in, out):
        # Read the input string
        x = in.next()
        # Initialize a stack to keep track of characters
        s = []
        # Initialize a counter to count balanced pairs
        c = 0
        # Iterate through each character in the input string
        for i in range(len(x)):
            # Push the current character onto the stack
            s.append(x[i])
            # While the stack has more than one element, check for balanced pairs
            while len(s) > 1:
                # Pop the top two elements from the stack
                p = s.pop()
                q = s.pop()
                # Check if they form a balanced pair
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    # Increment the counter if a balanced pair is found
                    c += 1
                    continue
                else:
                    # If not a balanced pair, push the popped elements back onto the stack
                    s.append(q)
                    s.append(p)
                    break
        # Output the result, which is twice the counter value
        out.println(c * 2)

class InputReader:
    # Constructor to initialize the InputReader with the standard input stream
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    # Method to read the next token from the input stream
    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = self.reader.readline()
            except IOException as e:
                raise RuntimeException(e)
        return self.tokenizer.nextToken()

class PrintWriter:
    # Constructor to initialize the PrintWriter with the standard output stream
    def __init__(self, stream):
        self.writer = stream

    # Method to write a string to the output stream
    def println(self, s):
        self.writer.write(s + '\n')

if __name__ == '__main__':
    main()

