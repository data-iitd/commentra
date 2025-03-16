import math
import sys

def run(r, w):
    # Create a new scanner object to read input lines
    sc = Scanner(r)

    # Read the first line of input containing two integers N and D
    a = sc.read_line().split()
    N, D = int(a[0]), int(a[1])

    # Read N lines of input and store them in a list called lines
    lines = []
    for _ in range(N):
        line = sc.read_line().split()
        lines.append([int(line[0]), int(line[1])])

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the lines list
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(line[0]**2 + line[1]**2)

        # If the distance of the current line is less than or equal to D, increment the counter
        if D >= d:
            count += 1

    # Write the final result to the output writer
    print(count, file=w)

class Scanner:
    def __init__(self, r):
        self.r = r

    def read_line(self):
        # Read a line using the reader and return it as a string
        return next(self.r).strip()

# main function calls the run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

if __name__ == "__main__":
    main()
