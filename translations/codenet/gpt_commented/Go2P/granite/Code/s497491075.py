
import math
import os
import sys

def run(reader, writer):
    # Initialize a new scanner to read input
    sc = Scanner(reader)

    # Read the first line of input and parse N (number of lines) and D (distance threshold)
    a = sc.readline().ints()
    N, D = a[0], a[1]

    # Read the next N lines of input, each containing a pair of integers
    lines = sc.readlines(N).ints()

    # Initialize a counter for the number of points within the distance D
    count = 0
    # Iterate over each line of input
    for line in lines:
        # Calculate the Euclidean distance from the origin (0, 0)
        d = math.sqrt(line[0] * line[0] + line[1] * line[1])
        # Check if the distance is less than or equal to D
        if D >= d:
            count += 1  # Increment the count if within distance
    # Output the total count of points within distance D
    writer.write(str(count))

# main function serves as the entry point of the program
def main():
    # Call the run function with standard input and output
    run(sys.stdin, sys.stdout)

# Scanner class wraps bufio.Scanner for reading input
class Scanner:
    def __init__(self, r):
        self.sc = bufio.Scanner(r)

    def readline(self):
        if self.sc.scan():
            return Value(self.sc.text())
        raise Exception("scan error")

    def readlines(self, n):
        a = []
        # Loop to read n lines
        for i in range(n):
            a.append(self.readline())  # Append each line to the list
        return a

# Value class represents a string value with additional methods for conversion
class Value:
    def __init__(self, s):
        self.s = s

    def __str__(self):
        return self.s

    def int(self):
        return int(self.s)

    def float(self):
        return float(self.s)

    def strings(self):
        return self.s.split(" ")

    def ints(self):
        return [int(s) for s in self.strings()]

    def float64s(self):
        return [float(s) for s in self.strings()]

    def runes(self):
        return list(self.s)

# Values class represents a list of Value
class Values:
    def __init__(self, values):
        self.values = values

    def strings(self):
        return [value.strings() for value in self.values]

    def ints(self):
        return [value.ints() for value in self.values]

    def float64s(self):
        return [value.float64s() for value in self.values]

    def runes(self):
        return [value.runes() for value in self.values]

# Run the program
if __name__ == "__main__":
    run(sys.stdin, sys.stdout)

