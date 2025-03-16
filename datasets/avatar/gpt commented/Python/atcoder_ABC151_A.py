import sys
import math

# Flag to enable or disable debugging
debug = False

# Function to log debug messages
def log(text):
    if debug:
        print(text)

# Function to parse input from the user or from a string
def parse_input(lines_as_string=None):
    global debug
    lines = []
    
    # Check if input is provided as a string
    if lines_as_string is None:
        debug = False  # Disable debug mode for standard input
        lines.append(input())  # Read input from the user
    else:
        debug = True  # Enable debug mode for string input
        # Split the input string into lines and ignore the first and last lines
        lines = [e for e in lines_as_string.split("\n")][1:-1]
    
    # Extract the first element from the first line as the character to process
    c = [e for e in lines[0].split(" ")][0]
    return (c,)

# Function to solve the problem by finding the next character in the alphabet
def solve(c):
    a = "abcdefghijklmnopqrstuvwxyz"  # String containing all lowercase letters
    i = a.index(c)  # Find the index of the given character
    return a[i + 1]  # Return the next character in the alphabet

# Main function to execute the program logic
def main():
    # Parse input and solve the problem
    result = solve(*parse_input())
    
    # Check if the result is a list and print each result
    if isinstance(result, list):
        for r in result:
            print("%s" % r, sep='')
    else:
        # Print the single result
        print("%s" % result, sep='')

# Entry point of the program
if __name__ == '__main__':
    main()
