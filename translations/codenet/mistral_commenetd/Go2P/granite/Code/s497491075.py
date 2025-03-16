

# Python code to calculate the number of points within a square with side length D and center at (0,0)

import math

def run(r, w):
    # Initialize a new scanner object to read input
    sc = Scanner(r)

    # Read the first line of input containing N and D
    a = sc.readline().split()
    N, D = int(a[0]), int(a[1])

    # Read N lines of input and store them in a list called lines
    lines = [list(map(int, line.split())) for line in sc.readlines(N)]

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the lines list
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(line[0] ** 2 + line[1] ** 2)

        # If the distance of the current line is less than or equal to D, increment the counter
        if d <= D:
            count += 1

    # Write the final result to the output writer
    w.write(str(count) + '\n')

# main function calls the run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

# Scanner class to read input lines
class Scanner:
    def __init__(self, r):
        self.sc = r.readline

    def readline(self):
        # Read a line using the scanner and return it as a Value object
        return self.sc()

    def readlines(self, n):
        # Initialize an empty list called a and append N Value objects to it
        a = []
        for _ in range(n):
            # Read a single line and append it to the list
            a.append(self.readline())
        # Return the list of Value objects
        return a

# Function to convert a string to an integer
def to_int(s):
    return int(s)

# Function to convert a string to a float
def to_float(s):
    return float(s)

# Function to split a string into a list of strings based on whitespace
def split_string(s):
    return s.split()

# Function to convert a list of strings to a list of integers
def convert_to_int(l):
    return list(map(to_int, l))

# Function to convert a list of strings to a list of floats
def convert_to_float(l):
    return list(map(to_float, l))

# Function to calculate the number of points within a square with side length D and center at (0,0)
def run(r, w):
    # Initialize a new scanner object to read input
    sc = Scanner(r)

    # Read the first line of input containing N and D
    a = sc.readline().split()
    N, D = int(a[0]), int(a[1])

    # Read N lines of input and store them in a list called lines
    lines = [convert_to_int(line.split()) for line in sc.readlines(N)]

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the lines list
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(line[0] ** 2 + line[1] ** 2)

        # If the distance of the current line is less than or equal to D, increment the counter
        if d <= D:
            count += 1

    # Write the final result to the output writer
    w.write(str(count) + '\n')

# main function calls the run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

# Scanner class to read input lines
class Scanner:
    def __init__(self, r):
        self.sc = r.readline

    def readline(self):
        # Read a line using the scanner and return it as a Value object
        return self.sc()

    def readlines(self, n):
        # Initialize an empty list called a and append N Value objects to it
        a = []
        for _ in range(n):
            # Read a single line and append it to the list
            a.append(self.readline())
        # Return the list of Value objects
        return a

# Function to convert a string to an integer
def to_int(s):
    return int(s)

# Function to convert a string to a float
def to_float(s):
    return float(s)

# Function to split a string into a list of strings based on whitespace
def split_string(s):
    return s.split()

# Function to convert a list of strings to a list of integers
def convert_to_int(l):
    return list(map(to_int, l))

# Function to convert a list of strings to a list of floats
def convert_to_float(l):
    return list(map(to_float, l))

# Function to calculate the number of points within a square with side length D and center at (0,0)
def run(r, w):
    # Initialize a new scanner object to read input
    sc = Scanner(r)

    # Read the first line of input containing N and D
    a = sc.readline().split()
    N, D = int(a[0]), int(a[1])

    # Read N lines of input and store them in a list called lines
    lines = [convert_to_int(line.split()) for line in sc.readlines(N)]

    # Initialize a counter variable count to 0
    count = 0

    # Iterate through each line in the lines list
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(line[0] ** 2 + line[1] ** 2)

        # If the distance of the current line is less than or equal to D, increment the counter
        if d <= D:
            count += 1

    # Write the final result to the output writer
    w.write(str(count) + '\n')

# main function calls the run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

# Scanner class to read input lines
class Scanner:
    def __init__(self, r):
        self.sc = r.readline

    def readline(self):
        # Read a line using the scanner and return it as a Value object
        return self.sc()

    def readlines(self, n):
        # Initialize an empty list called a and append N Value objects to it
        a = []
        for _ in range(n):
            # Read a single line and append it to the list
            a.append(self.readline())
        # Return the list of Value objects
        return a

# Function to convert a string to an integer
def to_int(s):
    return int(s)

# Function to convert a string to a float
def to_float(s):
    return float(s)

# Function to split a string into a list of strings based on whitespace
def split_string(s):
    return s.split()

# Function to convert a list of strings to a list of integers
def convert_to_int(l):
    return list(map(to_int, l))

# Function to convert a list of strings to a list of floats
def convert_to_float(l):
    return list(map(to_float, l))

# Function to calculate the number of points within a square with side length D and center at (0,0)
def run(r, w):
    # Initialize a new scanner object to read input
    sc = Scanner(r)

    # Read the first line of input containing N and D
    a = sc.readline().split()
    N, D = int(a[0]), int(a[1])

    # Read N lines of input and store them in a list called lines
    lines = [convert_to_int(line.split()) for line in sc.readlines(N)]

    # Initialize a counter variable count to 0

    # Iterate through each line in the lines list
    for line in lines:
        # Calculate the Euclidean distance of the current line from the origin (0,0)
        d = math.sqrt(line[0] ** 2 + line[1] ** 2)

        # If the distance of the current line is less than or equal to D, increment the counter
        if d <= D:
            count += 1

    # Write the final result to the output writer
    w.write(str(count) + '\n')

# main function calls the run function with standard input and output streams
def main():
    run(sys.stdin, sys.stdout)

# Scanner class to read input lines
class Scanner:
    def __init__(self, r):
        self.sc = r.readline

    def readline(self):
        # Read a line using the scanner and return it as a Value object
        return self.sc()

    def readlines(self, n):
        # Initialize an empty list called a and append N Value objects to it
        a = []
        for _ in range(n):
            # Read a single line and append it to the list
            a.append(self.readline())
        // Return the list of Value objects
        return a

# Function to convert a string to an integer
def to_int(s):
    return int(s)

# Function to convert a string to a float
def to_float(s):
    return float(s)

# Function to split a string into a list of strings based on whitespace
def split_string(s):
    return s.split()

# Function to convert a list of strings to a list of integers
def convert_to_int(l):
    return list(map(to_int, l))

// Function to convert a list of strings to a list of floats
func convert_to_float(l)
    return list(map(to_float, l))

// Function to calculate the number of points within a square with side length D and center at (0,0)
func run(r, w)
    // Initialize a new scanner object to read input
    sc := Scanner(r)

    // Read the first line of input containing N and D
    a := sc.readline().split()
    N, D := int(a[0]), int(a[1])

    // Read N lines of input and store them in a list called lines
    lines := [convert_to_int(line.split()) for line in sc.readlines(N)]

    // Initialize a counter variable count to 0

    // Iterate through each line in the lines list
    for line in lines {
        // Calculate the Euclidean distance of the current line from the origin (0,0)
        d := math.Sqrt(line[0]*line[0])

        // If the distance of the current line is less than or equal to D, increment the counter
        if d <= D {
            count += 1
        }
    }

    // Write the final result to the output writer
    w.write(str(count) + '\n')

// main function calls the run function with standard input and output streams
func main() {
    run(sys.stdin, sys.stdout)
}

// Scanner class to read input lines
class Scanner:
    def __init__(self, r)
    def readline(self)
    def readlines(self, n)
    a := []string{}
    for _ = range(n) {
        // Read a line using the scanner and return it as a Value object
        return self.readline()
    }

    // Function to convert a string to an integer
    def to_int(s)
    return int(s)

// Function to convert a string to a float
def to_float(s)
    return float64(s)

// Function to split a string into a list of