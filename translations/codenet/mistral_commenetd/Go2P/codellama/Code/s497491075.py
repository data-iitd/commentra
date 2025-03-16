
# Package main is the entry point of the program
import sys
import math

# Function Run calculates the number of points within a square with side length D and center at (0,0)
def run(r, w):
    # Initialize a new scanner object to read input
    sc = Scanner(r)

    # Read the first line of input containing N and D
    a = sc.read_line().ints()
    N, D = a[0], a[1]

    # Read N lines of input and store them in a slice called lines
    lines = sc.read_lines(N).ints()

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the lines slice
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(float(line[0] * line[0] + line[1] * line[1]))

        # If the distance of the current line is less than or equal to D, increment the counter
        if float(D) >= d:
            count += 1

    # Write the final result to the output writer
    w.write(str(count) + "\n")

# main function calls the Run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

# Scanner structure to read input lines
class Scanner:
    # Initialize a new scanner object to read input
    def __init__(self, r):
        self.sc = r

    # ReadLine function reads a single line of input and returns it as a Value object
    def read_line(self):
        # Read a line using the scanner and return it as a Value object
        line = self.sc.readline()
        return Value(line)

    # ReadLines function reads N lines of input and returns them as a slice of Value objects
    def read_lines(self, N):
        # Initialize an empty slice called a and append N Value objects to it
        a = []
        for i in range(N):
            # Read a single line and append it to the slice
            a.append(self.read_line())
        # Return the slice of Value objects
        return a

# Value structure to store a string value
class Value:
    # Initialize a Value object with a string value
    def __init__(self, s):
        self.s = s

    # String function returns the string representation of the Value object
    def string(self):
        return self.s

    # Int function converts a Value object to an integer
    def int(self):
        # Parse the string representation of the Value object to an integer and return it
        n = int(self.s)
        return n

    # Float64 function converts a Value object to a float64
    def float64(self):
        # Parse the string representation of the Value object to a float64 and return it
        f = float(self.s)
        return f

    # Strings function splits a Value object into a slice of strings based on whitespace
    def strings(self):
        # Split the string representation of the Value object based on whitespace and return the slice
        return self.s.split(" ")

    # Ints function converts a Value object to a slice of integers
    def ints(self):
        # Convert each string in the slice returned by the Strings function to an integer and return the slice
        a = []
        for s in self.strings():
            n = int(s)
            a.append(n)
        return a

    # Float64s function converts a Value object to a slice of float64s
    def float64s(self):
        # Parse each string in the slice returned by the Strings function to a float64 and return the slice
        a = []
        for s in self.strings():
            f = float(s)
            a.append(f)
        return a

    # Runes function converts a Value object to a slice of runes
    def runes(self):
        # Convert the string representation of the Value object to a slice of runes and return it
        return list(self.s)

# Values structure to store a slice of Value objects
class Values:
    # Initialize a Values object with a slice of Value objects
    def __init__(self, a):
        self.a = a

    # Strings function returns a slice of slices of strings, where each inner slice corresponds to the strings in a single Value object
    def strings(self):
        # Convert each Value object to a slice of strings and return the outer slice
        a = []
        for value in self.a:
            a.append(value.strings())
        return a

    # Ints function returns a slice of slices of integers, where each inner slice corresponds to the integers in a single Value object
    def ints(self):
        # Convert each Value object to a slice of integers and return the outer slice
        a = []
        for value in self.a:
            a.append(value.ints())
        return a

    # Float64s function returns a slice of slices of float64s, where each inner slice corresponds to the float64s in a single Value object
    def float64s(self):
        # Convert each Value object to a slice of float64s and return the outer slice
        a = []
        for value in self.a:
            a.append(value.float64s())
        return a

    # Runes function returns a slice of slices of runes, where each inner slice corresponds to the runes in a single Value object
    def runes(self):
        # Convert each Value object to a slice of runes and return the outer slice
        a = []
        for value in self.a:
            a.append(value.runes())
        return a

# main function calls the Run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

# Function Run calculates the number of points within a square with side length D and center at (0,0)
def run(r, w):
    # Initialize a new scanner object to read input
    sc = Scanner(r)

    # Read the first line of input containing N and D
    a = sc.read_line().ints()
    N, D = a[0], a[1]

    # Read N lines of input and store them in a slice called lines
    lines = sc.read_lines(N).ints()

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the lines slice
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(float(line[0] * line[0] + line[1] * line[1]))

        # If the distance of the current line is less than or equal to D, increment the counter
        if float(D) >= d:
            count += 1

    # Write the final result to the output writer
    w.write(str(count) + "\n")

# Scanner structure to read input lines
class Scanner:
    # Initialize a new scanner object to read input
    def __init__(self, r):
        self.sc = r

    # ReadLine function reads a single line of input and returns it as a Value object
    def read_line(self):
        # Read a line using the scanner and return it as a Value object
        line = self.sc.readline()
        return Value(line)

    # ReadLines function reads N lines of input and returns them as a slice of Value objects
    def read_lines(self, N):
        # Initialize an empty slice called a and append N Value objects to it
        a = []
        for i in range(N):
            # Read a single line and append it to the slice
            a.append(self.read_line())
        # Return the slice of Value objects
        return a

# Value structure to store a string value
class Value:
    # Initialize a Value object with a string value
    def __init__(self, s):
        self.s = s

    # String function returns the string representation of the Value object
    def string(self):
        return self.s

    # Int function converts a Value object to an integer
    def int(self):
        # Parse the string representation of the Value object to an integer and return it
        n = int(self.s)
        return n

    # Float64 function converts a Value object to a float64
    def float64(self):
        # Parse the string representation of the Value object to a float64 and return it
        f = float(self.s)
        return f

    # Strings function splits a Value object into a slice of strings based on whitespace
    def strings(self):
        # Split the string representation of the Value object based on whitespace and return the slice
        return self.s.split(" ")

    # Ints function converts a Value object to a slice of integers
    def ints(self):
        # Convert each string in the slice returned by the Strings function to an integer and return the slice
        a = []
        for s in self.strings():
            n = int(s)
            a.append(n)
        return a

    # Float64s function converts a Value object to a slice of float64s
    def float64s(self):
        # Parse each string in the slice returned by the Strings function to a float64 and return the slice
        a = []
        for s in self.strings():
            f = float(s)
            a.append(f)
        return a

    # Runes function converts a Value object to a slice of runes
    def runes(self):
        # Convert the string representation of the Value object to a slice of runes and return it
        return list(self.s)

# Values structure to store a slice of Value objects
class Values:
    # Initialize a Values object with a slice of Value objects
    def __init__(self, a):
        self.a = a

    # Strings function returns a slice of slices of strings, where each inner slice corresponds to the strings in a single Value object
    def strings(self):
        # Convert each Value object to a slice of strings and return the outer slice
        a = []
        for value in self.a:
            a.append(value.strings())
        return a

    # Ints function returns a slice of slices of integers, where each inner slice corresponds to the integers in a single Value object
    def ints(self):
        # Convert each Value object to a slice of integers and return the outer slice
        a = []
        for value in self.a:
            a.append(value.ints())
        return a

    # Float64s function returns a slice of slices of float64s, where each inner slice corresponds to the float64s in a single Value object
    def float64s(self):
        # Convert each Value object to a slice of float64s and return the outer slice
        a