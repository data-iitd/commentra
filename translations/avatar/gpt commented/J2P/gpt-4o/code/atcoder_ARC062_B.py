import sys

class TaskD:
    def solve(self, test_number, input_reader, output_writer):
        # Read the input string S
        S = input_reader.next()
        score = 0  # Initialize score to zero
        
        # Iterate through each character in the string S
        for i in range(len(S)):
            # Determine the character for 'my' based on the index (even or odd)
            my = 'g' if i % 2 == 0 else 'p'
            
            # Get the character from the input string at the current index
            his = S[i]
            
            # Compare 'my' and 'his' characters to update the score
            if my != his:
                # Increment score if 'my' is 'p', otherwise decrement
                score += 1 if my == 'p' else -1
        
        # Output the final score
        output_writer.write(f"{score}\n")

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.current_line = None
        self.current_index = 0

    def next(self):
        if self.current_line is None or self.current_index >= len(self.current_line):
            self.current_line = self.stream.readline().strip().split()
            self.current_index = 0
        token = self.current_line[self.current_index]
        self.current_index += 1
        return token

def main():
    # Set up input and output streams
    input_reader = InputReader(sys.stdin)
    output_writer = sys.stdout
    
    # Create an instance of TaskD to solve the problem
    solver = TaskD()
    
    # Call the solve method with test number, input reader, and output writer
    solver.solve(1, input_reader, output_writer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
