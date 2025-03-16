import sys

class AStationAndBus:
    def solve(self, test_number, input_stream, output_stream):
        # Read the input string
        s = input_stream.readline().strip()
        
        # Check if the string contains both 'A' and 'B'
        if 'A' in s and 'B' in s:
            # If both characters are present, print "Yes"
            output_stream.write("Yes\n")
        else:
            # If either character is missing, print "No"
            output_stream.write("No\n")

def main():
    # Create an instance of the AStationAndBus class to solve the problem
    solver = AStationAndBus()
    
    # Call the solve method with test number 1, passing the input and output streams
    solver.solve(1, sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
