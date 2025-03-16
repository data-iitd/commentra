import sys

class TaskD:
    def solve(self, testNumber, in, out):
        # Read the input string S
        S = in.next()
        score = 0 # Initialize score to zero
        
        # Iterate through each character in the string S
        for i in range(len(S)):
            # Determine the character for'my' based on the index (even or odd)
            my = 'g' if i % 2 == 0 else 'p'
            
            # Get the character from the input string at the current index
            his = S[i]
            
            # Compare'my' and 'his' characters to update the score
            if my!= his:
                # Increment score if'my' is 'p', otherwise decrement
                score += 1 if my == 'p' else -1
        
        # Output the final score
        out.println(score)

class InputReader:
    def __init__(self, stream):
        self.reader = sys.stdin
        self.tokenizer = None

    def next(self):
        # Keep reading until we have a token available
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = StringTokenizer(self.reader.readLine())
        # Return the next token
        return self.tokenizer.nextToken()

if __name__ == '__main__':
    # Set up input and output streams
    inputStream = sys.stdin
    outputStream = sys.stdout

    # Create an InputReader to read input from the input stream
    in = InputReader(inputStream)

    # Create a PrintWriter to write output to the output stream
    out = PrintWriter(outputStream)

    # Create an instance of TaskD to solve the problem
    solver = TaskD()

    # Call the solve method with test number, input reader, and output writer
    solver.solve(1, in, out)

    # Close the PrintWriter to flush the output
    out.close()

