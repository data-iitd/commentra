import sys

def main():
    # Initialize input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Create a Scanner object for reading input and a PrintWriter for output
    in_ = sys.stdin.readline
    out = sys.stdout.write
    
    # Create an instance of the AStationAndBus class to solve the problem
    solver = AStationAndBus()
    
    # Call the solve method with test number 1, passing the input and output objects
    solver.solve(1, in_, out)
    
    # Close the PrintWriter to flush the output
    # Note: In Python, we don't explicitly close the input stream, as it's not needed

# Static inner class to handle the logic of the problem
class AStationAndBus:
    def solve(self, testNumber, in_, out):
        # Read the input string
        s = in_().strip()
        
        # Check if the string contains both 'A' and 'B'
        if 'A' in s and 'B' in s:
            # If both characters are present, print "Yes"
            out("Yes\n")
        else:
            # If either character is missing, print "No"
            out("No\n")

if __name__ == "__main__":
    main()
