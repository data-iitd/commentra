import sys

class TaskB:
    def solve(self, test_number, input_stream, output_stream):
        # Read the input string
        x = input_stream.readline().strip()
        # Initialize a stack to keep track of characters
        s = []
        # Initialize a counter to count balanced pairs
        c = 0
        # Iterate through each character in the input string
        for char in x:
            # Push the current character onto the stack
            s.append(char)
            # While the stack has more than one element, check for balanced pairs
            while len(s) > 1:
                # Pop the top two elements from the stack
                p = s.pop()
                q = s.pop()
                # Check if they form a balanced pair
                if (p == '1' and q == '0') or (p == '0' and q == '1'):
                    # Increment the counter if a balanced pair is found
                    c += 1
                    continue
                else:
                    # If not a balanced pair, push the popped elements back onto the stack
                    s.append(q)
                    s.append(p)
                    break
        # Output the result, which is twice the counter value
        output_stream.write(f"{c * 2}\n")

def main():
    # Create an instance of TaskB and call its solve method
    solver = TaskB()
    solver.solve(1, sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
