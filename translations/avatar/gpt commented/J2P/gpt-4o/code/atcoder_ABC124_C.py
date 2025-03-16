import sys

class CColoringColorfully:
    def solve(self, test_number, input_stream, output_stream):
        # Read the input string
        x = input_stream.readline().strip()
        
        # Create two lists to manipulate the string
        a = list(x)
        b = list(x)
        
        # Initialize counters for the number of changes made
        a1 = 0
        a2 = 0
        
        # First pass: modify 'a' from left to right
        for i in range(1, len(x)):
            # Check if the current character is the same as the previous one
            if a[i] == a[i - 1]:
                # Change the character to the opposite value
                a[i] = '0' if a[i] == '1' else '1'
                # Increment the change counter
                a1 += 1
        
        # Second pass: modify 'b' from right to left
        for i in range(len(x) - 1, 0, -1):
            # Check if the current character is the same as the previous one
            if b[i] == b[i - 1]:
                # Change the previous character to the opposite value
                b[i - 1] = '0' if b[i - 1] == '1' else '1'
                # Increment the change counter
                a2 += 1
        
        # Output the minimum number of changes made in either pass
        output_stream.write(f"{min(a1, a2)}\n")

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Instantiate the solver class for the problem
    solver = CColoringColorfully()
    
    # Solve the problem for the first test case
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
