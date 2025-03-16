import sys
import io
import os
import math

# FastReader class to read input efficiently
class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))

    def readline(self):
        return self.buffer.readline().decode('utf-8').strip()

    def read(self):
        return self.buffer.read()

    def readint(self):
        return int(self.readline())

    def readfloat(self):
        return float(self.readline())

    def readline_stripped(self):
        return self.readline().strip()

# PrintWriter object to output the result
class PrintWriter:
    def __init__(self, output):
        self.output = output

    def print(self, *args, **kwargs):
        print(*args, **kwargs, file=self.output)

    def close(self):
        self.output.close()

# Main function
def main():
    # Read the dimensions of the grid
    n = FastReader().readint()
    # Read the number of banned cells
    m = FastReader().readint()

    # Initialize sets to keep track of banned rows and columns
    banned_rows, banned_cols = set(), set()

    # Read each banned cell and add it to the appropriate set if it's not on the border
    for _ in range(m):
        r = FastReader().readint()
        if r > 1 and r < n:
            banned_rows.add(r)
        c = FastReader().readint()
        if c > 1 and c < n:
            banned_cols.add(c)

    # Calculate the number of cells that can be reached, accounting for banned rows and columns
    answer = (n - 2) * 2
    answer -= len(banned_rows)
    answer -= len(banned_cols)

    # Adjust the answer if the grid size is odd and the center cell is not banned
    if n % 2 != 0:
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            answer -= 1

    # Output the final answer
    print(answer)

if __name__ == "__main__":
    main()
