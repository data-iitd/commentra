
import sys

# Run function processes input from the reader and writes output to the writer
def run(r, w):
    # Initialize a new scanner to read input
    sc = Scanner(r)

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
        d = math.sqrt(line[0]**2 + line[1]**2)
        # Check if the distance is less than or equal to D
        if D >= d:
            count += 1 # Increment the count if within distance

    # Output the total count of points within distance D
    print(count, file=w)

# main function serves as the entry point of the program
def main():
    # Call the Run function with standard input and output
    run(sys.stdin, sys.stdout)

# Scanner struct wraps bufio.Scanner for reading input
class Scanner:
    # Initialize a new Scanner with the provided io.Reader
    def __init__(self, r):
        self.sc = bufio.Scanner(r)

    # ReadLine reads a single line from the input and returns it as a Value
    def readline(self):
        if self.sc.scan():
            return Value(self.sc.text())
        raise Exception("scan error") # Panic if scanning fails

    # ReadLines reads n lines from the input and returns them as Values
    def readlines(self, n):
        a = []
        # Loop to read n lines
        for i in range(n):
            a.append(self.readline()) # Append each line to the Values slice
        return a # Return the slice of Values

# Value type represents a string value with additional methods for conversion
class Value:
    # Initialize a new Value with the provided string
    def __init__(self, s):
        self.s = s

    # String returns the string representation of the Value
    def string(self):
        return self.s

    # Int converts the Value to an integer
    def int(self):
        try:
            return int(self.s)
        except ValueError:
            raise Exception("conversion error") # Panic if conversion fails

    # Float64 converts the Value to a float64
    def float64(self):
        try:
            return float(self.s)
        except ValueError:
            raise Exception("conversion error") # Panic if conversion fails

    # Strings splits the Value into a slice of strings
    def strings(self):
        return self.s.split(" ")

    # Ints converts the Value to a slice of integers
    def ints(self):
        a = []
        # Split the Value into strings and convert each to an integer
        for s in self.strings():
            try:
                a.append(int(s))
            except ValueError:
                raise Exception("conversion error") # Panic if conversion fails
        return a # Return the slice of integers

    # Float64s converts the Value to a slice of float64
    def float64s(self):
        a = []
        # Split the Value into strings and convert each to a float64
        for s in self.strings():
            try:
                a.append(float(s))
            except ValueError:
                raise Exception("conversion error") # Panic if conversion fails
        return a # Return the slice of float64

    # Runes converts the Value to a slice of runes
    def runes(self):
        return list(self.s)

# Values type represents a slice of Value
class Values:
    # Initialize a new Values with the provided slice of Value
    def __init__(self, a):
        self.a = a

    # Strings converts the Values to a slice of string slices
    def strings(self):
        a = []
        # Loop through each Value and convert to strings
        for value in self.a:
            a.append(value.strings())
        return a # Return the slice of string slices

    # Ints converts the Values to a slice of integer slices
    def ints(self):
        a = []
        # Loop through each Value and convert to integers
        for value in self.a:
            a.append(value.ints())
        return a # Return the slice of integer slices

    # Float64s converts the Values to a slice of float64 slices
    def float64s(self):
        a = []
        # Loop through each Value and convert to float64
        for value in self.a:
            a.append(value.float64s())
        return a # Return the slice of float64 slices

    # Runes converts the Values to a slice of rune slices
    def runes(self):
        a = []
        # Loop through each Value and convert to runes
        for value in self.a:
            a.append(value.runes())
        return a # Return the slice of rune slices


