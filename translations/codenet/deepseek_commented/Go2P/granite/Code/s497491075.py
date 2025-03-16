
import math
import os
import sys

# Run function reads input from the reader, processes it, and writes the output to the writer.
def Run(r, w):
    sc = Scanner(r)

    # Read the first line which contains two integers N and D.
    a = sc.ReadLine().split()
    N, D = int(a[0]), int(a[1])

    # Read the next N lines which contain pairs of integers representing points.
    lines = sc.ReadLines(N)

    # Initialize a counter to keep track of points within the given distance.
    count = 0

    # Iterate over each point and calculate the distance from the origin.
    for line in lines:
        # Calculate the Euclidean distance of the point from the origin.
        d = math.sqrt(line[0] * line[0] + line[1] * line[1])
        # Check if the distance is within the given limit.
        if D >= d:
            count += 1

    # Write the count of points within the distance to the writer.
    w.write(str(count) + "\n")

# main function initializes the Run function with sys.stdin and sys.stdout.
def main():
    Run(sys.stdin, sys.stdout)

# Scanner class is used to read input efficiently.
class Scanner:
    def __init__(self, r):
        self.sc = r.readline

    def ReadLine(self):
        return self.sc().rstrip()

    def ReadLines(self, n):
        return [self.ReadLine() for _ in range(n)]

if __name__ == "__main__":
    main()

