# Import necessary modules
import sys
import math

# Define a function to log messages when debug mode is enabled
def log(text):
    # Check if debug mode is enabled
    if debug:
        # Print the log message
        print(text)

# Function to parse input lines
def parse_input(lines_as_string=None):
    # Set the global debug flag
    global debug

    # Initialize an empty list to store the lines
    lines = []

    # If lines_as_string is provided, set debug mode to True and parse lines
    if lines_as_string is not None:
        debug = True
        lines = [e for e in lines_as_string.split("\n")] [1:-1]

    # Extract the first character from the first line as the command
    c = [e for e in lines[0].split(" ")] [0]

    # Return the command as a tuple
    return (c,)

# Function to solve the problem based on the command
def solve(c):
    # Define the alphabet string
    a = "abcdefghijklmnopqrstuvwxyz"

    # Find the index of the command character in the alphabet string
    i = a.index(c)

    # Return the next character in the alphabet string
    return a[i+1]

# Main function to execute the code
def main():
    # Call the parse_input function to get the command
    result = solve(*parse_input())

    # Check if the result is a list or a single string
    if isinstance(result, list):
        # If it's a list, print each element separately
        for r in result:
            print(f"{r}", sep="")
    else:
        # If it's a single string, print it directly
        print(f"{result}", sep="")

# Run the main function if the script is executed directly
if __name__ == '__main__':
    main()
