
# <START-OF-CODE>

# Main method to start the program
def main():
    input_stream = System.in # Initialize input stream
    output_stream = System.out # Initialize output stream
    in = Scanner(input_stream) # Initialize scanner for reading input
    out = PrintWriter(output_stream) # Initialize print writer for writing output

    solver = AStationAndBus() # Create an instance of the solver class
    solver.solve(1, in, out) # Call the solve method with test number, input scanner, and output print writer

    out.close() # Close the output print writer

# Inner class to solve the problem
class AStationAndBus:
    def solve(self, testNumber, in, out):
        # Method to solve the problem

        s = in.next() # Read the next input string

        # Check if the string contains both 'A' and 'B'
        if s.contains("A") and s.contains("B"):
            out.println("Yes") # Print "Yes" if both characters are present
        else:
            out.println("No") # Print "No" if either character is missing

if __name__ == '__main__':
    main()

# 