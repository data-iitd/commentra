import sys

class BABC:
    def solve(self, test_number, input_stream, output_stream):
        s = input_stream.readline().strip().replace("BC", "D")
        # Read the input string and replace all occurrences of "BC" with "D".
        cnt = 0  # Initialize a counter to keep track of the result.
        tmp = 0  # Temporary variable to count consecutive 'A's.
        for char in s:
            if char == 'A':
                tmp += 1  # Increment tmp if the current character is 'A'.
            elif char == 'D':
                cnt += tmp  # Add tmp to cnt if the current character is 'D'.
            else:
                tmp = 0  # Reset tmp if the current character is not 'A' or 'D'.
        output_stream.write(f"{cnt}\n")  # Print the final count.

def main():
    input_stream = sys.stdin  # Get the input stream from the system.
    output_stream = sys.stdout  # Get the output stream from the system.
    solver = BABC()  # Create an instance of the BABC class.
    solver.solve(1, input_stream, output_stream)  # Call the solve method of the BABC class.

if __name__ == "__main__":
    main()

# The BABC class contains the logic to solve the problem. The solve method implements the main logic.
# <END-OF-CODE>
