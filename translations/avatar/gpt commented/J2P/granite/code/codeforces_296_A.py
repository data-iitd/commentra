
import sys

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Create an InputReader to read input from the input stream
    input_reader = InputReader(input_stream)

    # Create a PrintWriter to write output to the output stream
    output_writer = PrintWriter(output_stream)

    # Instantiate the Task class to solve the problem
    solver = Task()

    # Call the solve method to process the input and produce output
    solver.solve(input_reader, output_writer)

    # Close the PrintWriter to flush and release resources
    output_writer.close()

class Task:
    def solve(self, input_reader, output_writer):
        # Read the number of elements
        n = input_reader.nextInt()

        # Initialize an array to count occurrences of each index (up to 1000)
        array = [0] * 1001

        # Read n integers and count their occurrences
        for i in range(n):
            index = input_reader.nextInt()
            array[index] += 1

        # Determine the maximum count of any index
        count_max = max(array)

        # Check if the maximum count is within allowed limits based on n being even or odd
        if n % 2 == 0:
            # For even n, check if the maximum count is less than or equal to n/2
            if count_max <= n // 2:
                output_writer.println("YES")
            else:
                output_writer.println("NO")
        else:
            # For odd n, check if the maximum count is less than or equal to n/2 + 1
            if count_max <= n // 2 + 1:
                output_writer.println("YES")
            else:
                output_writer.println("NO")

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.current_line = 0
        self.current_token = 0
        self.current_tokens = []

    def next(self):
        if self.current_token >= len(self.current_tokens):
            self.current_line += 1
            self.current_tokens = self.stream.readline().split()
            self.current_token = 0
        self.current_token += 1
        return self.current_tokens[self.current_token - 1]

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return long(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        self.current_line += 1
        return self.stream.readline()

