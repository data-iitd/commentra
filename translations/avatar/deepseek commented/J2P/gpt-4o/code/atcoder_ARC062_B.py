import sys  # Importing sys for input and output operations

# The Main class is defined to run the program
class Main:
    # The main method initializes input and output streams and calls the solve method
    @staticmethod
    def main():
        input_stream = sys.stdin  # Get the input stream from the system
        output_stream = sys.stdout  # Get the output stream from the system
        solver = TaskD()  # Create an instance of TaskD
        solver.solve(1, input_stream, output_stream)  # Call the solve method of TaskD

# The TaskD class contains the solve method which calculates a score based on the input string
class TaskD:
    # The solve method takes a test number, an input stream, and an output stream
    def solve(self, test_number, input_stream, output_stream):
        S = input_stream.readline().strip()  # Read the next string from the input
        score = 0  # Initialize the score to 0
        # Iterate through each character in the string S
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'  # Determine the expected character based on the index
            his = S[i]  # Get the character at the current index in S
            # Compare the expected character with the actual character and update the score
            if my != his:
                score += 1 if my == 'p' else -1  # Update the score based on the expected character
        output_stream.write(f"{score}\n")  # Print the final score

# Entry point of the program
if __name__ == "__main__":
    Main.main()  # Call the main method

# <END-OF-CODE>
