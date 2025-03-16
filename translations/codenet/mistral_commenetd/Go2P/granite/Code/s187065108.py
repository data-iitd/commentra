
import sys

# Initialize a new scanner for reading input from stdin
sc = bufio.Scanner(sys.stdin)

# Function to read an integer as input
def scanInt():
    num = int(scanString()) # Convert the string to integer
    return num # Return the integer

# Function to read a string as input
def scanString():
    sc.scan() # Read the next token as a string
    return sc.text() # Return the string

# Function to read an array of integers as input
def scanInts(n):
    sl = [0] * n # Allocate memory for an array of n integers
    for i in range(n): # Iterate through each index of the array
        sl[i] = scanInt() # Read and store an integer at the current index
    return sl # Return the array

# Function to read an array of strings as input
def scanStrings(n):
    sl = [0] * n # Allocate memory for an array of n strings
    for i in range(n): # Iterate through each index of the array
        sl[i] = scanString() # Read and store a string at the current index
    return sl # Return the array

# Initialize the scanner for reading input
def init():
    sc.whitespace = " \n\r\t" # Set the scanner to split input on whitespace
    sc.commenters = "" # Disable commenting in the input

# Main function to execute the program
def main():
    # Read the first three integers as input
    r, D, x = scanInt(), scanInt(), scanInt()

    # Iterate through a loop 10 times
    for i in range(1, 11): # Iterate from 1 to 10
        # Calculate the new value of x using the given formula
        x = r*x - D

        # Print the value of x to the console
        print(x)

# The end of the code