import sys  # For handling input and output

class Main:
    # Main method to start the program
    @staticmethod
    def main():
        input_stream = sys.stdin  # Input stream from console
        output_stream = sys.stdout  # Output stream to console
        solver = TaskD()  # Create TaskD object
        solver.solve(1, input_stream, output_stream)  # Solve the problem and print output

class TaskD:
    def solve(self, test_number, input_stream, output_stream):
        S = input_stream.read().strip()  # Read the input string
        score = 0  # Variable to store the score

        # Iterate through each character in the string
        for i in range(len(S)):
            my = 'g' if i % 2 == 0 else 'p'  # Determine my move based on the index
            his = S[i]  # Read his move from the input string

            # Update the score based on the moves
            if my != his:
                score += 1 if my == 'p' else -1

        # Print the score
        output_stream.write(f"{score}\n")  # Print the score

if __name__ == "__main__":
    Main.main()  # Start the program

# <END-OF-CODE>
