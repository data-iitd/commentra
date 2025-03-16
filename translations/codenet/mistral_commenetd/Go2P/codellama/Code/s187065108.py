
# Initialize a new scanner for reading input from stdin
sc = input()

# Function to read an integer as input
def scanInt():
    return int(sc)

# Function to read a string as input
def scanString():
    return sc

# Function to read an array of integers as input
def scanInts(n):
    sl = []
    for i in range(n):
        sl.append(scanInt())
    return sl

# Function to read an array of strings as input
def scanStrings(n):
    sl = []
    for i in range(n):
        sl.append(scanString())
    return sl

# Initialize the scanner for reading input
def init():
    sc = input()

# Main function to execute the program
def main():
    # Read the first three integers as input
    r, D, x = scanInt(), scanInt(), scanInt()

    # Iterate through a loop 10 times
    for i in range(1, 11):
        # Calculate the new value of x using the given formula
        x = r*x - D

        # Print the value of x to the console
        print(x)

# The end of the code
