import sys # Importing the sys module for input and output operations

# The Main class is defined to run the program
class Main:
    # The main method initializes input and output streams, creates an instance of TaskD, and calls its solve method
    def main(self):
        sys.stdin = open("input.txt", "r") # Open the input file
        sys.stdout = open("output.txt", "w") # Open the output file
        solver = TaskD() # Create an instance of TaskD
        solver.solve(1, InputReader(sys.stdin), OutputWriter(sys.stdout)) # Call the solve method of TaskD
        sys.stdout.close() # Close the output stream

# The TaskD class contains the solve method which calculates a score based on the input string
class TaskD:
    # The solve method takes a test number, an InputReader instance, and a PrintWriter instance
    def solve(self, testNumber, in, out):
        S = in.next() # Read the next string from the input
        score = 0 # Initialize the score to 0
        # Iterate through each character in the string S
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p' # Determine the expected character based on the index
            his = S[i] # Get the character at the current index in S
            # Compare the expected character with the actual character and update the score
            if my!= his:
                score += my == 'p' and 1 or -1 # Update the score based on the expected character
        out.println(score) # Print the final score

# The InputReader class is used to read input efficiently
class InputReader:
    def __init__(self, stream):
        self.reader = stream.buffer # Create a BufferedReader with a buffer size of 32768
        self.tokenizer = None # Initialize the tokenizer as null

    # Method to read the next token from the input stream
    def next(self):
        while self.tokenizer == None or not self.tokenizer.hasMoreTokens(): # Check if there are more tokens
            try:
                self.tokenizer = StringTokenizer(self.reader.readLine()) # Read the next line and tokenize it
            except IOException as e:
                raise RuntimeException(e) # Throw a RuntimeException if an IOException occurs
        return self.tokenizer.nextToken() # Return the next token

# The OutputWriter class is used to write output efficiently
class OutputWriter:
    def __init__(self, stream):
        self.writer = PrintWriter(stream, True) # Create a PrintWriter instance to write output

    # Method to print a string to the output stream
    def println(self, string):
        self.writer.println(string) # Print the string to the output stream

    # Method to close the output stream
    def close(self):
        self.writer.close() # Close the output stream

# The main method is defined to run the program
if __name__ == '__main__':
    main() # Call the main method

