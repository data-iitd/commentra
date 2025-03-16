import sys
import math

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    def next(self):
        if self.tokenizer is None or not self.tokenizer:
            line = self.reader.readline()
            if not line:
                raise RuntimeError("End of input reached")
            self.tokenizer = line.split()
        return self.tokenizer.pop(0)

    def next_int(self):
        return int(self.next())

    def read_array(self, n):
        return [self.next_int() for _ in range(n)]

class Solution:
    def solve(self, in_reader, out_writer):
        n = in_reader.next_int()  # Read the number of logs
        k = in_reader.next_int()  # Read the number of days
        logs_length = in_reader.read_array(n)  # Read the lengths of the logs

        # Initialize the minimum and maximum possible days
        min_day, max_day = 1, int(1e9) + 1000

        # Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
        while min_day < max_day:
            mid = (min_day + max_day) // 2  # Calculate the middle day
            if self.nei(mid, logs_length, k):  # If the number of days needed to cut the logs is greater than or equal to k
                max_day = mid  # Narrow down the search space to the left
            else:
                min_day = mid + 1  # Narrow down the search space to the right

        # Print the minimum day as the output
        out_writer.write(f"{min_day}\n")

    def nei(self, mid, logs_length, k):
        days_needed = 0  # Initialize the days needed to zero

        # Iterate through all the logs and calculate the days needed to cut them
        for log in logs_length:
            days_needed += (log + mid - 1) // mid  # Calculate the days needed to cut the current log
            k -= days_needed  # Subtract the days needed from the remaining days
            if k < 0:  # If the remaining days are not sufficient to cut all the logs
                return False  # Return false to indicate that the middle day is not the answer

        # If all the logs have been cut, return true to indicate that the middle day is the answer
        return True

def main():
    input_stream = sys.stdin  # Initialize input stream from standard input
    output_stream = sys.stdout  # Initialize output stream to standard output
    in_reader = InputReader(input_stream)  # Create an InputReader object
    out_writer = output_stream  # Use the standard output stream
    sol = Solution()  # Create a Solution object
    sol.solve(in_reader, out_writer)  # Call the solve method of Solution object

if __name__ == "__main__":
    main()

# <END-OF-CODE>
