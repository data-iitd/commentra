import sys

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
    
    def next(self):
        if not self.buffer:
            self.buffer = self.stream.readline().strip().split()
        return self.buffer.pop(0)

class TaskB:
    def solve(self, test_number, in_reader, out_writer):
        x = in_reader.next()  # Reading the input string
        s = []  # Stack to store characters
        c = 0  # Counter to store the number of pairs

        # Iterating through each character in the input string
        for char in x:
            s.append(char)  # Pushing the character onto the stack

            # Popping two characters from the stack and checking for a pair
            while len(s) > 1:
                p = s.pop()  # Popping the top character
                q = s.pop()  # Popping the second top character

                # If the popped characters form a pair, increment the counter and continue
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    c += 1
                    continue

                # If the characters don't form a pair, push them back onto the stack and break
                s.append(q)
                s.append(p)
                break

        # Writing the output to the PrintWriter object
        out_writer.write(str(c * 2) + '\n')

def main():
    input_stream = sys.stdin  # Input stream for reading input
    output_stream = sys.stdout  # Output stream for writing output
    in_reader = InputReader(input_stream)  # Creating an InputReader object
    out_writer = output_stream  # Using the standard output stream
    solver = TaskB()  # Creating a TaskB object
    solver.solve(1, in_reader, out_writer)  # Calling the solve method of TaskB class

if __name__ == "__main__":
    main()

# <END-OF-CODE>
