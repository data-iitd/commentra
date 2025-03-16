import sys  # Import sys for standard input and output

class BABC:
    # Class for solving the problem

    def solve(self, test_number, input_stream, output_stream):
        # Method for solving the problem

        s = input_stream.readline().strip().replace("BC", "D")  # Read input, strip whitespace, and replace "BC" with "D"

        cnt = 0  # Initialize counter for the number of "D"s
        tmp = 0  # Initialize temporary variable for counting consecutive "A"s

        for char in s:
            # Loop through each character in the string

            if char == 'A':
                # If the character is "A", increment the temporary counter
                tmp += 1
            elif char == 'D':
                # If the character is "D", add the temporary counter to the total count
                cnt += tmp
            else:
                # If the character is neither "A" nor "D", reset the temporary counter
                tmp = 0

        # Print the result
        output_stream.write(f"{cnt}\n")  # Write the result to the output stream

def main():
    # Main function that starts the program
    input_stream = sys.stdin  # Input stream for reading from the console
    output_stream = sys.stdout  # Output stream for writing to the console

    solver = BABC()  # Create a new instance of the BABC class
    solver.solve(1, input_stream, output_stream)  # Solve the problem and print the result

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
