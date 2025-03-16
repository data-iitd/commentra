import sys
import math

def run(input_stream, output_stream):
    # Read the first line of input containing two integers N and D
    first_line = input_stream.readline().strip()
    N, D = map(int, first_line.split())

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the input
    for _ in range(N):
        line = input_stream.readline().strip()
        x, y = map(int, line.split())

        # Calculate the Euclidean distance of the current point from the origin (0,0)
        d = math.sqrt(x * x + y * y)

        # If the distance of the current point is less than or equal to D, increment the counter
        if D >= d:
            count += 1

    # Write the final result to the output stream
    output_stream.write(f"{count}\n")

# Main function calls the run function with standard input and output streams
if __name__ == "__main__":
    run(sys.stdin, sys.stdout)

# <END-OF-CODE>
