
# Import the input function from the sys module
import sys

# Read a line from input using the input function
input_string = sys.stdin.readline()

# Replace all commas with spaces in the input string
modified_string = input_string.replace(',', ' ')

# Print the modified string to the console
print(modified_string)