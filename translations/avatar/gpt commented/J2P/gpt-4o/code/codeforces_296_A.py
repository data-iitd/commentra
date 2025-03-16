import sys
from collections import defaultdict

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.current_line = None
        self.current_index = 0

    def next(self):
        if self.current_line is None or self.current_index >= len(self.current_line):
            self.current_line = self.stream.readline().strip().split()
            self.current_index = 0
        result = self.current_line[self.current_index]
        self.current_index += 1
        return result

    def next_int(self):
        return int(self.next())

class Task:
    def solve(self, in_reader, out_writer):
        # Read the number of elements
        n = in_reader.next_int()

        # Initialize a dictionary to count occurrences of each index (up to 1000)
        array = [0] * 1001

        # Read n integers and count their occurrences
        for _ in range(n):
            index = in_reader.next_int()
            array[index] += 1

        # Determine the maximum count of any index
        count_max = max(array)

        # Check if the maximum count is within allowed limits based on n being even or odd
        if n % 2 == 0:
            # For even n, check if the maximum count is less than or equal to n/2
            if count_max <= n // 2:
                out_writer.write("YES\n")
            else:
                out_writer.write("NO\n")
        else:
            # For odd n, check if the maximum count is less than or equal to n/2 + 1
            if count_max <= n // 2 + 1:
                out_writer.write("YES\n")
            else:
                out_writer.write("NO\n")

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Create an InputReader to read input from the input stream
    in_reader = InputReader(input_stream)

    # Create a Task instance to solve the problem
    solver = Task()

    # Call the solve method to process the input and produce output
    solver.solve(in_reader, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
