import sys

def main():
    # Read from standard input
    input_stream = sys.stdin
    # Write to standard output
    output_stream = sys.stdout
    
    # Initialize the scanner for reading input
    in_scanner = sys.stdin
    # Initialize the print writer for writing output
    out_writer = sys.stdout
    
    # Create an instance of the TaskC class
    solver = TaskC()
    # Call the solve method with input scanner and output print writer
    solver.solve(1, in_scanner, out_writer)

class TaskC:
    # Class to solve the problem
    
    def solve(self, test_number, in_scanner, out_writer):
        # Method to solve the problem
        
        # Read the number of test cases
        n = int(next(in_scanner).strip())
        
        # Initialize a dictionary to store counts
        cnt = {'M': 0, 'A': 0, 'R': 0, 'C': 0, 'H': 0}
        
        # Loop through each test case
        for _ in range(n):
            # Read a string from input
            str_input = next(in_scanner).strip()
            
            # Increment the count for the corresponding character
            if str_input[0] in cnt:
                cnt[str_input[0]] += 1
        
        # Calculate the result using the counts
        res = (cnt['M'] * cnt['A'] * cnt['R'] +
               cnt['M'] * cnt['A'] * cnt['C'] +
               cnt['M'] * cnt['A'] * cnt['H'] +
               cnt['M'] * cnt['R'] * cnt['C'] +
               cnt['M'] * cnt['R'] * cnt['H'] +
               cnt['M'] * cnt['C'] * cnt['H'] +
               cnt['A'] * cnt['R'] * cnt['C'] +
               cnt['A'] * cnt['R'] * cnt['H'] +
               cnt['A'] * cnt['C'] * cnt['H'] +
               cnt['R'] * cnt['C'] * cnt['H'])
        
        # Write the result to the output
        print(res, file=out_writer)

# Call the main method
if __name__ == "__main__":
    main()
