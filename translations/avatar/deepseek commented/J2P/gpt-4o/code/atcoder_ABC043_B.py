import sys

class LightScanner:
    def __init__(self, input_stream):
        self.reader = input_stream
        self.tokenizer = None

    def string(self):
        if self.tokenizer is None or not self.tokenizer:
            line = self.reader.readline().strip()
            self.tokenizer = line.split()
        return self.tokenizer.pop(0)

class BUnhappyHackingABCEdit:
    def solve(self, test_number, in_stream, out_stream):
        # Read the input string
        s = in_stream.string()
        
        # StringBuilder equivalent in Python
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
                if d:
                    d.pop()
        
        # Print the result
        out_stream.write(''.join(d) + '\n')

def main():
    # Step 1: Define the input stream and output stream
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Step 2: Create a LightScanner instance for reading input efficiently
    in_stream = LightScanner(input_stream)
    
    # Step 3: Create an instance of the problem solver
    solver = BUnhappyHackingABCEdit()
    
    # Step 4: Solve the problem
    solver.solve(1, in_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
