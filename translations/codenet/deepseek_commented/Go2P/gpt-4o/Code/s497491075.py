import sys
import math

def run(input_stream, output_stream):
    # Read the first line which contains two integers N and D.
    first_line = input_stream.readline().strip()
    N, D = map(int, first_line.split())

    # Initialize a counter to keep track of points within the given distance.
    count = 0

    # Read the next N lines which contain pairs of integers representing points.
    for _ in range(N):
        line = input_stream.readline().strip()
        x, y = map(int, line.split())
        
        # Calculate the Euclidean distance of the point from the origin.
        distance = math.sqrt(x * x + y * y)
        
        # Check if the distance is within the given limit.
        if distance <= D:
            count += 1

    # Write the count of points within the distance to the output stream.
    output_stream.write(f"{count}\n")

def main():
    run(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
