import sys
import math

def run(input_stream, output_stream):
    # Read the first line of input and parse N (number of lines) and D (distance threshold)
    first_line = input_stream.readline().strip()
    N, D = map(int, first_line.split())

    # Initialize a counter for the number of points within the distance D
    count = 0

    # Read the next N lines of input, each containing a pair of integers
    for _ in range(N):
        line = input_stream.readline().strip()
        x, y = map(int, line.split())
        # Calculate the Euclidean distance from the origin (0, 0)
        d = math.sqrt(x * x + y * y)
        # Check if the distance is less than or equal to D
        if d <= D:
            count += 1  # Increment the count if within distance

    # Output the total count of points within distance D
    output_stream.write(f"{count}\n")

# Main function serves as the entry point of the program
if __name__ == "__main__":
    run(sys.stdin, sys.stdout)

# <END-OF-CODE>
