import sys

class AStationAndBus:
    # Class to solve the problem

    def solve(self, test_number, input_stream, output_stream):
        # Method to solve the problem
        s = input_stream.readline().strip()  # Read the next input string

        # Check if the string contains both 'A' and 'B'
        if 'A' in s and 'B' in s:
            output_stream.write("Yes\n")  # Print "Yes" if both characters are present
        else:
            output_stream.write("No\n")  # Print "No" if either character is missing

def main():
    # Main method to start the program
    input_stream = sys.stdin  # Initialize input stream
    output_stream = sys.stdout  # Initialize output stream

    solver = AStationAndBus()  # Create an instance of the solver class
    solver.solve(1, input_stream, output_stream)  # Call the solve method with test number, input stream, and output stream

if __name__ == "__main__":
    main()  # Run the main method

# <END-OF-CODE>
