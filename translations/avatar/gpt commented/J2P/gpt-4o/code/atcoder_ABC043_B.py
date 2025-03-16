import sys

class BUnhappyHackingABCEdit:
    def solve(self, test_number, input_string):
        # StringBuilder equivalent in Python
        d = []
        
        # Process each character in the input string
        for c in input_string:
            if c == '0':
                # Append '0' to the output
                d.append('0')
            elif c == '1':
                # Append '1' to the output
                d.append('1')
            elif c == 'B':
                # Handle the 'B' character by removing the last character if possible
                if d:
                    d.pop()  # Remove the last character
        
        # Output the final result
        print(''.join(d))

def main():
    # Read input from standard input
    input_string = sys.stdin.read().strip()
    
    # Create an instance of the problem solver
    solver = BUnhappyHackingABCEdit()
    
    # Solve the problem for the first test case
    solver.solve(1, input_string)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
