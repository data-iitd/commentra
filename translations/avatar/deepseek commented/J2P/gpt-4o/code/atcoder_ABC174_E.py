import sys
import math

class InputReader:  # InputReader class helps in reading inputs efficiently
    def __init__(self, stream):  # Constructor to initialize the InputReader
        self.reader = stream  # Use the provided stream for input
        self.tokenizer = []  # Initialize the tokenizer as an empty list

    def next(self):  # Method to read the next token
        while not self.tokenizer:  # Check if there are more tokens
            line = self.reader.readline()  # Read the next line
            self.tokenizer = line.split()  # Tokenize the line
        return self.tokenizer.pop(0)  # Return the next token

    def next_int(self):  # Method to read the next integer
        return int(self.next())  # Parse the next token as an integer

    def read_array(self, n):  # Method to read an array of integers
        return [self.next_int() for _ in range(n)]  # Read n integers and return as a list


class Solution:  # Solution class contains the logic for solving the problem
    def solve(self, in_reader, out_writer):  # solve method reads input, processes it, and writes the output
        n = in_reader.next_int()  # Read the number of logs
        k = in_reader.next_int()  # Read the number of cuts allowed
        logs_length = in_reader.read_array(n)  # Read the lengths of the logs
        min_length = 1
        max_length = int(1e9) + 1000  # Initialize the binary search range

        while min_length < max_length:  # Perform binary search
            mid = (min_length + max_length) // 2  # Calculate the middle value
            if self.can_cut(mid, logs_length, k):  # Check if the current mid can be used to cut all logs
                max_length = mid  # Adjust the max value to search in the lower half
            else:
                min_length = mid + 1  # Adjust the min value to search in the upper half

        out_writer.write(f"{min_length}\n")  # Print the result

    def can_cut(self, mid, logs_length, k):  # can_cut method checks if the current mid can be used to cut all logs
        for log in logs_length:  # Iterate through each log
            k -= (log + mid - 1) // mid - 1  # Calculate the number of cuts needed for the current log
            if k < 0:  # If k is negative, it means we cannot make the required cuts
                return False  # Return false as the current mid cannot be used
        return True  # Return true if all logs can be cut with the given number of k


def main():  # Main function is the entry point of the program
    input_reader = InputReader(sys.stdin)  # Create an InputReader object to read input
    output_writer = sys.stdout  # Get the output stream from the system
    solution = Solution()  # Create a Solution object to solve the problem
    solution.solve(input_reader, output_writer)  # Call the solve method to process the input and produce output


if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
