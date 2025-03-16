# Import the sys module for standard input/output
import sys

# Define a variable `s` to store the user input.
s = ""

# Read a string input from the standard input and store it in the variable `s`.
s = input("Enter a string: ")  # Print a prompt message to the standard output.

# Replace all occurrences of the string "2017" in the string `s` with the string "2018".
s = s.replace("2017", "2018")

# Print the modified string to the standard output.
print("Modified string:", s)

# End of code.
