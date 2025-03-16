import sys
import io

class BABC:
    def solve(self, test_number, inp, out):
        # Read the input string and replace occurrences of "BC" with "D"
        s = inp.readline().replace("BC", "D")
        
        # Initialize counters for 'A' and the result
        cnt = 0
        tmp = 0
        
        # Iterate through the modified string to count occurrences
        for char in s:
            # Increment temporary counter for 'A'
            if char == 'A':
                tmp += 1
            # Add the count of 'A's to the result when 'D' is encountered
            elif char == 'D':
                cnt += tmp
            # Reset the temporary counter for any other character
            else:
                tmp = 0
        
        # Output the final count of valid pairs
        out.write(str(cnt) + '\n')

# Main function to handle input and output
def main():
    # Initialize input and output streams
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    
    # Create an instance of the BABC class to solve the problem
    solver = BABC()
    
    # Call the solve method with test number, input stream, and output writer
    solver.solve(1, input_stream, output_stream)
    
    # Close the output writer
    output_stream.flush()

if __name__ == "__main__":
    main()
