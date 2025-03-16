
import sys

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Initialize InputReader for reading input and PrintWriter for output
    input_reader = InputReader(input_stream)
    output_writer = PrintWriter(output_stream)

    # Create an instance of Solution to solve the problem
    solution = Solution()
    solution.solve(input_reader, output_writer)

    # Close the output stream
    output_writer.close()

class Solution:
    def solve(self, input_reader, output_writer):
        # Read the number of logs and the value of k
        n, k = input_reader.read_int(), input_reader.read_int()

        # Read the lengths of the logs into an array
        logs_length = input_reader.read_int_array(n)

        # Initialize binary search bounds
        min_length, max_length = 1, 1000000000

        # Perform binary search to find the minimum possible length
        while min_length < max_length:
            mid_length = (min_length + max_length) // 2

            # Check if it's possible to cut the logs with the current mid length
            if self.nei(mid_length, logs_length, k):
                max_length = mid_length
            else:
                min_length = mid_length + 1

        # Output the minimum length found
        output_writer.println(min_length)

    # Helper method to determine if logs can be cut with the given mid length
    def nei(self, mid_length, logs_length, k):
        for log in logs_length:
            k -= (log + mid_length - 1) // mid_length - 1
        # Return true if we can make the cuts within the limit of k
        return k >= 0

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.current_token = None

    def read_int(self):
        return int(self.read())

    def read_int_array(self, n):
        return [self.read_int() for _ in range(n)]

    def read(self):
        if self.current_token is None:
            self.current_token = self.stream.readline().strip()
        return self.current_token

    def read_token(self):
        self.current_token = None
        return self.stream.readline().strip()

