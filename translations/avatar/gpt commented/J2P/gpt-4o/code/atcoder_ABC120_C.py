import sys

class TaskB:
    def solve(self, test_number, input_stream, output_stream):
        # Read the input string
        x = input_stream.readline().strip()
        stack = []
        c = 0  # Counter for pairs of '0' and '1'
        
        # Iterate through each character in the input string
        for char in x:
            # Push the current character onto the stack
            stack.append(char)
            
            # Process the stack while there are at least two characters
            while len(stack) > 1:
                p = stack.pop()  # Pop the top character
                q = stack.pop()  # Pop the next character
                
                # Check if the characters form a pair of '0' and '1'
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    c += 1  # Increment the counter for valid pairs
                    continue  # Continue to check for more pairs
                else:
                    # If not a valid pair, push the characters back onto the stack
                    stack.append(q)
                    stack.append(p)
                    break  # Exit the while loop
        
        # Output the result, which is twice the count of pairs found
        output_stream.write(f"{c * 2}\n")

def main():
    # Set up input and output streams
    input_stream = sys.stdin
    output_stream = sys.stdout
    
    # Create an instance of TaskB and solve the problem
    solver = TaskB()
    solver.solve(1, input_stream, output_stream)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
