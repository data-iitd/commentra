
import sys

def main():
    # Initialize input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout

    # Create a Scanner object for reading input
    in_scanner = Scanner(input_stream)

    # Create a PrintWriter object for writing output
    out_writer = PrintWriter(output_stream)

    # Create an instance of the BABC class to solve the problem
    solver = BABC()

    # Call the solve method with test number, input scanner, and output writer
    solver.solve(1, in_scanner, out_writer)

    # Close the output writer
    out_writer.close()

class BABC:
    def solve(self, test_number, in_scanner, out_writer):
        # Read the input string and replace occurrences of "BC" with "D"
        s = in_scanner.next().replace("BC", "D")

        # Initialize counters for 'A' and the result
        cnt = 0
        tmp = 0

        # Iterate through the modified string to count occurrences
        for i in range(len(s)):
            # Increment temporary counter for 'A'
            if s[i] == 'A':
                tmp += 1
            # Add the count of 'A's to the result when 'D' is encountered
            elif s[i] == 'D':
                cnt += tmp
            # Reset the temporary counter for any other character
            else:
                tmp = 0

        # Output the final count of valid pairs
        out_writer.println(cnt)

# End of code