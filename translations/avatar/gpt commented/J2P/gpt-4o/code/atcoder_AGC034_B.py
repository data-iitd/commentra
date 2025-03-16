import sys

class BABC:
    def solve(self, test_number, input_stream, output_stream):
        # Read the input string and replace occurrences of "BC" with "D"
        s = input_stream.readline().strip().replace("BC", "D")
        
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
        output_stream.write(f"{cnt}\n")

def main():
    # Create an instance of the BABC class to solve the problem
    solver = BABC()
    
    # Call the solve method with test number, input stream, and output stream
    solver.solve(1, sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
