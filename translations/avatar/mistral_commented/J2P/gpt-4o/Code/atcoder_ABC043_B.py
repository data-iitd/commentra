import sys

class LightScanner:
    def __init__(self, input_stream):
        self.reader = input_stream
        self.tokenizer = None

    def string(self):
        if self.tokenizer is None or not self.tokenizer:
            line = self.reader.readline()
            if not line:  # If there is no more input
                raise EOFError("No more input")
            self.tokenizer = line.split()  # Initialize the tokenizer with the new line
        return self.tokenizer.pop(0)  # Return the next token

class BUnhappyHackingABCEdit:
    def solve(self, test_number, in_stream, out_stream):
        s = in_stream.string()  # Read the input string
        d = []  # Initialize an empty list for the output

        for c in s:  # Iterate through each character in the input string
            if c == '0':
                d.append("0")  # Append "0" to the output list
            elif c == '1':
                d.append("1")  # Append "1" to the output list
            elif c == 'B':
                if d:  # If there is a character in the output list
                    d.pop()  # Remove the last character from the output list

        out_stream.write(''.join(d) + '\n')  # Print the output list to the console

def main():
    input_stream = sys.stdin  # Input stream from the console
    output_stream = sys.stdout  # Output stream to the console
    in_stream = LightScanner(input_stream)  # Initialize LightScanner for reading input
    solver = BUnhappyHackingABCEdit()  # Initialize the solver

    test_number = 1  # Test case number
    solver.solve(test_number, in_stream, output_stream)  # Run the solver with the given input and output streams

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
